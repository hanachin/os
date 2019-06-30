; FAT12っぽい
DB  0xeb, 0x4e, 0x90
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
DB  0xb8, 0x00, 0x00, 0x8e, 0xd0, 0xbc, 0x00, 0x7c
DB  0x8e, 0xd8, 0x8e, 0xc0, 0xbe, 0x74, 0x7c, 0x8a
DB  0x04, 0x83, 0xc6, 0x01, 0x3c, 0x00, 0x74, 0x09
DB  0xb4, 0x0e, 0xbb, 0x0f, 0x00, 0xcd, 0x10, 0xeb
DB  0xee, 0xf4, 0xeb, 0xfd ; ここで終わって良いのはなんでだろ
; ほんたいおわり


; あなたのCPUに話しかけています
DB  0x0a, 0x0a  ; 0x0a, 10は改行、覚えた
DB  "I love ruby <3" ; <3、記号だけど出るのかな
DB  0x0a ; かいぎょ
DB  0 ; NULLしゅうたん?

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
