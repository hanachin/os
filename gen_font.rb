#!/usr/bin/env ruby
BITMAP_MAX = 8

def generate_font(bdf)
  sections = bdf.lines.chunk_while { @2 !~ /^START/ }.map(&:join)
  chars = sections.select { @1.start_with?('STARTCHAR 0x00') }
  chars = chars.select { @1.include?("BITMAP") }
  chars_table = chars.map {
    _bbx, height, width, offset_x, offset_y = @1.match(/^BBX (\-?\d+) (\-?\d+) (\-?\d+) (\-?\d+)\n/).to_a.map(&:to_i)
    bitmap_index = @1.lines.index { @1 =~ /^BITMAP$/ }
    bitmap = @1.lines[bitmap_index + 1, height].map { @1.to_i(16) }
    raise if height > BITMAP_MAX
    [height, width, offset_x, offset_y].all? { @1 < 0x10 }
    height_width = (height << 4) | width
    offset_xy = (offset_x << 4) | offset_y
    [@1.match(/STARTCHAR 0x00([\dA-F]{2})/)[1].to_i(16), [height_width, offset_xy, *bitmap]]
  }.to_h
  (0x00..0xFF).map {
    data = (chars_table[@1] || [0, 0]).pack('C*')
    pad = BITMAP_MAX - (data.size - 2)
    data + ([0] * pad).pack('C*')
  }.join
end

filename = ARGV.fetch(0)
bdf = File.read(filename)
font_bin = generate_font(bdf)
File.write('font.bin', font_bin)
