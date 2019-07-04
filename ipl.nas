CYLS EQU 10 ; 10シリンダあるの定義、CYLSで参照できる

ORG 0x7c00
; FAT12っぽい
JMP entry
DB  0x90
DB  "KONITIWA"    ; おなまえ、適当にかえてみた
DW  512           ; せくた
DB  1             ; くらすたは1
DW  1             ; FATがどこからはじまるか (1セクタ目
DB  2             ; FAT個数は2
DW  224           ; ルートディレクトリ領域、224エントリ
DW  2880          ; このドライブの大きさ、2880セクタ
DB  0xf0          ; メディアのタイプ、これは仕様あとで読むか
DW  9             ; FAT領域の長さは9セクタ
DW  18            ; 1トラック18セクタ
DW  2             ; ヘッドは2つ
DD  0             ; パーティションがないとき0(?)
DD  2880          ; このドライブの大きさをもう一度かく、大事なことなので二度言う感
DB  0, 0, 0x29    ; え、よくわからないけどこの値にしておくといいと書かれていてよく分からない!!
DD  0xffffffff    ; たぶんボリュームシリアル番号、ボリュームシリアル番号とは、たぶん、とは...
DB  "HANACHINOS!" ; ディスクの名前、11バイト
DB  "FAT12   "    ; フォーマットの名前8バイト

; RESB  18          ; RESBすると間が空くのか、ここ18かくと18バイトあく
; ↑うまくいかなかったのでここ参考に書き換え
; https://qiita.com/duloxetine/items/ce1fc1d861f0c3d33651
TIMES 18 DB 0

; ほんたい
entry:
  MOV AX, 0
  MOV SS, AX
  MOV SP, 0x7c00
  MOV DS, AX

read_sectors:
  MOV AX, 0x0820
  MOV ES, AX
  MOV CH, 0 ; しりんだ
  MOV DH, 0 ; 裏表
  MOV CL, 2 ; セクタ

readloop:
  MOV SI, 0 ; エラーカウント
retry:
  MOV AH, 0x02
  MOV AL, 1
  MOV BX, 0
  MOV DL, 0x00
  INT 0x13

  JNC next

  ADD SI, 1
  CMP SI, 5
  JAE error

  MOV AH, 0x00 ; リセット命令?
  MOV DL, 0x00 ; Aドライブ
  INT 0x13
  JMP retry

next:
  MOV AX, ES
  ADD AX, 0x20
  MOV ES, AX
  ADD CL, 1
  CMP CL, 18
  JBE readloop

  MOV CL, 1
  ADD DH, 1
  CMP DH, 2
  JB readloop

  MOV DH, 0
  ADD CH, 1
  CMP CH, CYLS
  JB readloop

  JMP 0xc200

error:
  MOV AL, 0x65
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10

  MOV AL, 0x72
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10

  MOV AL, 0x72
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10

fin:
  HLT
  JMP fin

; RESB 0x1fe-$ ;0x001feまで0うめ、なるほど-$
; ↑うまくいかなかったのでここ参考に書き換え
; https://qiita.com/duloxetine/items/ce1fc1d861f0c3d33651
TIMES 0x1fe-($-$$) DB 0

DB  0x55, 0xaa
