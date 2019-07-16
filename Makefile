default:
	  make img

font.c : font.h gen_font.rb mplus_q06r.bdf
		./gen_font.rb mplus_q06r.bdf

ipl10.bin : ipl10.nas Makefile
	  nasm ipl10.nas -o ipl10.bin -l ipl10.lst

asmhead.bin : asmhead.nas Makefile
	  nasm asmhead.nas -o asmhead.bin -l asmhead.lst

naskfunc.o : naskfunc.nas Makefile
	  nasm -g -f elf naskfunc.nas -o naskfunc.o

%.o : %.c
		gcc -c -fno-pic -march=i486 -m32 -nostdlib -o $*.o $*.c

bootpack.hrb : bootpack.o naskfunc.o font.o har.ld Makefile
		ld -m elf_i386 -T har.ld -e HariMain -o bootpack.hrb bootpack.o naskfunc.o font.o

haribote.sys : asmhead.bin bootpack.hrb Makefile
	  cat asmhead.bin bootpack.hrb > haribote.sys

haribote.img : ipl10.bin haribote.sys Makefile
		mformat -f 1440 -C -B ipl10.bin -i haribote.img ::
	 	mcopy haribote.sys -i haribote.img ::

asm :
	  make -r ipl10.bin

img :
	  make -r haribote.img

run :
	  make img
		qemu-system-i386 -fda haribote.img

clean :
	rm *.bin *.hrb *.img *.lst *.o *.sys font.c
