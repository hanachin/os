  ORG 0xc200

ok:
  MOV AL, 0x6F
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10

  MOV AL, 0x6B
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10

fin:
  HLT
  JMP fin
