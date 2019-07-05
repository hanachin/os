default:
	  make img

ipl.bin : ipl.nas Makefile
	  nasm ipl.nas -o ipl.bin -l ipl.lst

asmhead.bin : asmhead.nas Makefile
	  nasm asmhead.nas -o asmhead.bin -l asmhead.lst

bootpack.hrb : bootpack.c har.ld Makefile
	gcc -fno-pic -march=i486 -m32 -nostdlib -T har.ld bootpack.c -o bootpack.hrb

haribote.sys : asmhead.bin bootpack.hrb Makefile
	  cat asmhead.bin bootpack.hrb > haribote.sys

haribote.img : ipl.bin haribote.sys Makefile
		mformat -f 1440 -C -B ipl.bin -i haribote.img ::
	 	mcopy haribote.sys -i haribote.img ::

asm :
	  make -r ipl.bin

img :
	  make -r haribote.img

run :
	  make img
		qemu-system-i386 -fda haribote.img
