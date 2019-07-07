bits 32

section .text

        GLOBAL io_hlt
        GLOBAL io_cli
        GLOBAL io_sti
        GLOBAL io_stihlt
        GLOBAL io_in8
        GLOBAL io_in16
        GLOBAL io_in32
        GLOBAL io_out8
        GLOBAL io_out16
        GLOBAL io_out32
        GLOBAL io_load_eflags
        GLOBAL io_store_eflags

write_mem8:	; void write_mem8(int addr, int data);
		MOV		ECX,[ESP+4]		; [ESP+4]にaddrが入っているのでそれをECXに読み込む
		MOV		AL,[ESP+8]		; [ESP+8]にdataが入っているのでそれをALに読み込む
		MOV		[ECX],AL
		RET

io_hlt:
  HLT
  RET

io_cli:
  CLI
  RET

io_sti:
  STI
  RET

io_stihlt:
  STI
  RET

io_in8:
  MOV EAX, [ESP+4]
  MOV EAX, 0
  IN AL, DX
  RET

io_in16:
  MOV EAX, [ESP+4]
  MOV EAX, 0
  IN AX, DX
  RET

io_in32:
  MOV EAX, [ESP+4]
  MOV EAX, 0
  IN EAX, DX
  RET

io_out8:
  MOV EDX, [ESP+4]
  MOV AL, [ESP+8]
  OUT DX,AL
  RET


io_out16:
  MOV EDX, [ESP+4]
  MOV AX, [ESP+8]
  OUT DX,AX
  RET


io_out32:
  MOV EDX, [ESP+4]
  MOV EAX, [ESP+8]
  OUT DX,EAX
  RET

io_load_eflags:
  PUSHFD
  POP EAX
  RET

io_store_eflags:
  MOV EAX, [ESP+4]
  PUSH EAX
  POPFD
  RET
