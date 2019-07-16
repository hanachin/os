#!/usr/bin/env ruby
require 'erb'

BITMAP_MAX = 8

Character = Struct.new(:code, :height, :width, :offset_x, :offset_y, :bitmap)

def render(chars)
  erb = ERB.new(<<~C)
  #include "font.h"
  Font hankaku[256] = {
  <%
    (0..255).each do |code|
      c = chars.detect { @1.code == code } || Character.new(code, 0, 0, 0, 0, [])
  %>
    // <%= code.chr.inspect %>
    // <%= code.to_s(16) %>
    {
      .height = <%= c.height %>,
      .width = <%= c.width %>,
      .offset_x = <%= c.offset_x %>,
      .offset_y = <%= c.offset_y %>,
      .bitmap = {<%= c.bitmap.join(',') %>}
    },
  <% end %>
  };
  C
  erb.result(binding)
end

def generate_font(bdf)
  sections = bdf.lines.chunk_while { @2 !~ /^START/ }.map(&:join)
  chars = sections.select { @1.start_with?('STARTCHAR 0x00') }
  chars = chars.select { @1.include?("BITMAP") }
  chars = chars.map do
    _bbx, width, height, offset_x, offset_y = @1.match(/^BBX (\-?\d+) (\-?\d+) (\-?\d+) (\-?\d+)\n/).to_a.map(&:to_i)
    bitmap_index = @1.lines.index { @1 =~ /^BITMAP$/ }
    c = @1
    bitmap = @1.lines[bitmap_index + 1, height].map { @1.to_i(16) }

    raise if height > BITMAP_MAX
    raise unless [height, width, offset_x, offset_y].all? { @1 < 0x10 }

    Character.new(
      @1.match(/STARTCHAR 0x00([\dA-F]{2})/)[1].to_i(16),
      height,
      width,
      offset_x,
      offset_y,
      bitmap
    )
  end

  render(chars)
end

filename = ARGV.fetch(0)
bdf = File.read(filename)
font_c = generate_font(bdf)
File.write('font.c', font_c)
