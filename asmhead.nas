BOTPAK  EQU  0x00280000 ; これどうやって求めるんだっけ
DSKCAC  EQU  0x00100000 ; これはキメっぽい
DSKCAC0 EQU  0x00008000 ; real modeの場所

CYLS  EQU 0x0ff0
LEDS  EQU 0x0ff1
VMODE EQU 0x0ff2
SCRNX EQU 0x0ff4
SCRNY EQU 0x0ff6
VRAM  EQU 0x0ff8

  ORG 0xc200

vga:
  MOV AL, 0x13 ;  320x200x8bit
  MOV AH, 0x00
  INT 0x10
  MOV BYTE [VMODE], 8
  MOV BYTE [SCRNX], 320
  MOV BYTE [SCRNY], 200
  MOV DWORD [VRAM], 0x000a0000

  MOV AH, 0x02 ; キーボードおしえてもらう?
  INT 0x16
  MOV [LEDS], AL

disable_pic_interrupt:
  MOV AL, 0xFF
  OUT 0x21, AL
  NOP
  OUT 0xA1, AL

disable_hardware_interrupt:
  CLI

; CPUから1MB以上のメモリにアクセスできるようにする
; キーボードな理由はここにあるけど、ウケる
; http://www.hazymoon.jp/OpenBSD/annex/gate_a20.html

  CALl waitkbdout
  MOV AL, 0xD1
  OUT 0x64, AL
  CALl waitkbdout
  MOV AL, 0xDF
  OUT 0x60, AL
  CALL waitkbdout

; 32 bit移行!

  LGDT [GDTR0]
  MOV  EAX, CR0
  AND  EAX, 0x7FFFFFF ; 31bit目0にしてページングを無効
  OR   EAX, 0x0000001 ; bit0をたてる、protect modeだと0らしい
  MOV  CR0, EAX
  JMP  pipelineflush ; jumpすることでなんか飛ばしてるっぽい

pipelineflush:
  MOV AX, 1*8 ; null descriptorを飛ばすため8のよう
  MOV DS, AX
  MOV ES, AX
  MOV FS, AX
  MOV GS, AX
  MOV SS, AX ; ここではCS設定していないのでコードの実行はふつうに動く

; bootpackでてこいや
  MOV ESI, bootpack
  MOV EDI, BOTPAK
  MOV ECX, 512*1024/4 ; この分コピーする, 32bitずつコピーできるから4で割ってる
  CALL memcpy

; ブートセクタコピる
  MOV ESI, 0x7c00
  MOV EDI, DSKCAC
  MOV ECX, 512/4 ; 512byte / 32bit
  CALL memcpy

; のこり
  MOV  ESI, DSKCAC0+512 ; bootsector分読み飛ばしたところから
  MOV  EDI, DSKCAC+512  ; bootsectorつめたとこから
  MOV  ECX, 0
  MOV  CL, BYTE [CYLS]  ; シリンダー10の情報ここに入れてればとれるはず(いれてたっけ...)
  IMUL ECX, 512*18*2/4  ; シリンダ数 * セクターのバイト数 * セクターの数 * 裏表のヘッダー / 32bit
  SUB  ECX, 512/4       ; IPLはコピらない感じか?
  CALL memcpy

; bootpack呼ぶ!

  MOV EBX, BOTPAK
  MOV ECX, [EBX+16] ; ヘッダーの.dataのサイズ読んでる
  ADD ECX, 3 ; += 3 ; 0 -> 11 -> 00, 1 -> 100 -> 1, 11 -> 110 -> 1、データあるか見るのとコピーする数きめるためのあれっぽい
  SHR ECX, 2 ; /=4、右シフトか
  JZ  skip
  MOV ESI, [EBX+20] ; ファイル位置
  ADD ESI, EBX
  MOV EDI, [EBX+12] ; スタックとdataここから!の位置なるほど
  CALL memcpy
skip:
  MOV ESP, [EBX+12] ; スタックを設定しなおす
  JMP DWORD 2*8:0x00000001b ; GDT0の2番めで設定したセグメント?使ってジャンプしてるっぽいような。GDT0の2番めのやつも使える範囲同じにしてるから.dataのはじまりからはじまるかんじか！CSはせっていしないんやろうか

waitkbdout:
  IN  AL, 0x64
  AND AL, 0x02
  JNZ waitkbdout
  RET

memcpy:
  MOV EAX, [ESI]
  ADD ESI, 4
  MOV [EDI], EAX
  ADD EDI, 4
  SUB ECX, 1
  JNZ memcpy
  RET

  ALIGNB 16

GDT0:
  RESB  8
  DW    0xffff, 0x0000, 0x9200, 0x00cf
  DW    0xffff, 0x0000, 0x9a28, 0x0047

  DW    0

GDTR0:
  DW  8*3-1 ; 23 bytes, テーブルのバイト数-1
  DD  GDT0

  ALIGNB 16

; このあとにbootpackのオブジェクト直結してるので、そこに飛べるようにシンボルつけとく
bootpack:
