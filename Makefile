default:
	  make img

ipl.bin : ipl.nas Makefile
	  nasm ipl.nas -o ipl.bin -l ipl.lst

haribote.sys : haribote.nas Makefile
	  nasm haribote.nas -o haribote.sys -l haribote.lst

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
