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
  MOV ES, AX

  MOV SI, msg

  MOV AH, 0x00
  MOV AL, 0x13
  INT 0x10
putloop:
  MOV AL, [SI]
  ADD SI, 1
  CMP AL, 0
  JE  fin
  MOV AH, 0x0e
  MOV BX, 12
  INT 0x10
  JMP putloop

fin:
  HLT
  JMP fin

msg:
; あなたのCPUに話しかけています
DB  0x0a, 0x0a  ; 0x0a, 10は改行、覚えた
DB  "I love ruby <3 <3" ; <3、記号だけど出るのかな
DB  0x0a ; かいぎょ
DB  0 ; NULLしゅうたん?
; ほんたいおわり


; RESB 0x1fe-$ ;0x001feまで0うめ、なるほど-$
; ↑うまくいかなかったのでここ参考に書き換え
; https://qiita.com/duloxetine/items/ce1fc1d861f0c3d33651
TIMES 0x1fe-($-$$) DB 0

DB  0x55, 0xaa
; CPUへの伝言おわり

; ブートセクタ以外を埋めてる、のかな?

DB  0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00
RESB 4600
DB  0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00
RESB 1469432
