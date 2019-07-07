#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3

#define COLOR_BLUE 4
#define COLOR_PURPLE 5
#define COLOR_LIGHT_BLUE 6
#define COLOR_WHITE 7

#define COLOR_GRAY 8
#define COLOR_DARK_RED 9
#define COLOR_DARK_GREEN 10
#define COLOR_DARK_YELLOW 11

#define COLOR_DARK_BLUE 12
#define COLOR_DARK_PURPLE 13
#define COLOR_DARK_LIGHT_BLUE 14
#define COLOR_DARK_GRAY 15

void io_hlt(void);
void io_cli(void);
void io_out8(int port, int data);
int io_load_eflags(void);
void io_store_eflags(int eflags);

void init_palette();
void set_palette(int start, int end, unsigned char *rgb);
void boxfill8(unsigned char *vram, int xsize, unsigned char color, int x0, int y0, int x1, int y1);

void HariMain(void)
{
  init_palette();

  char *p = (char *)0xa0000;
  int xsize = 320, ysize = 200;

  boxfill8(p, 320, COLOR_DARK_LIGHT_BLUE, 0, 0, xsize -1, ysize - 29); // 背景

  boxfill8(p, 320, COLOR_GRAY, 0, ysize - 28, xsize -1, ysize - 28); // タスクバーのボーダー
  boxfill8(p, 320, COLOR_WHITE, 0, ysize - 27, xsize -1, ysize - 27); // タスクバーのボーダーハイライト
  boxfill8(p, 320, COLOR_GRAY, 0, ysize - 26, xsize -1, ysize - 1); // タスクバーのボーダー

  boxfill8(p, 320, COLOR_WHITE,     3,  ysize - 24, 59, ysize - 24); // スタートボタンのボーダー↑
  boxfill8(p, 320, COLOR_WHITE,     2,  ysize - 24,  2, ysize - 4); // スタートボタンのボーダー←
  boxfill8(p, 320, COLOR_DARK_GRAY, 3,  ysize -  4, 59, ysize - 4); // スタートボタンのボーダー↓
  boxfill8(p, 320, COLOR_DARK_GRAY, 59, ysize - 23, 59, ysize - 4); // スタートボタンのボーダー→

  boxfill8(p, 320, COLOR_BLACK,     2,  ysize -  3, 59, ysize - 3); // スタートボタンの影↓
  boxfill8(p, 320, COLOR_BLACK,    60,  ysize - 24, 60, ysize - 3); // スタートボタンの影→

  boxfill8(p, 320, COLOR_DARK_GRAY, xsize - 47,  ysize - 24, xsize - 4, ysize - 24); // 時計とかでるとこ↑
  boxfill8(p, 320, COLOR_DARK_GRAY, xsize - 47,  ysize - 23, xsize - 47, ysize - 4); // 時計とかでるとこ←
  boxfill8(p, 320, COLOR_WHITE, xsize - 47,  ysize - 3, xsize - 4, ysize - 3); // 時計とかでるとこ→
  boxfill8(p, 320, COLOR_WHITE, xsize - 3,  ysize - 24, xsize - 3, ysize - 3); // 時計とかでるとこ↓

  for(;;) {
    io_hlt();
  }
}

void init_palette() {
  auto unsigned char table_rgb[16*3] = {
    0x00, 0x00, 0x00, // COLOR_BLACK
    0xff, 0x00, 0x00, // COLOR_RED
    0x00, 0xff, 0x00, // COLOR_GREEN
    0xff, 0xff, 0x00, // COLOR_YELLOW

    0x00, 0x00, 0xff, // COLOR_BLUE
    0xff, 0x00, 0xff, // COLOR_PURPLE
    0x00, 0xff, 0xff, // COLOR_LIGHT_BLUE
    0xff, 0xff, 0xff, // COLOR_WHITE

    0xc6, 0xc6, 0xc6, // COLOR_GRAY
    0x84, 0x00, 0x00, // COLOR_DARK_RED
    0x00, 0x84, 0x00, // COLOR_DARK_GREEN
    0x84, 0x84, 0x00, // COLOR_DARK_YELLOW

    0x00, 0x00, 0x84, // COLOR_DARK_BLUE
    0x84, 0x00, 0x84, // COLOR_DARK_PURPLE
    0x00, 0x84, 0x84, // COLOR_DARK_LIGHT_BLUE
    0x84, 0x84, 0x84  // COLOR_DARK_GRAY
  };
  set_palette(0, 15, table_rgb);
  return;
}

void set_palette(int start, int end, unsigned char *rgb) {
  int eflags = io_load_eflags();
  io_cli();
  io_out8(0x03c8, start);
  for (int i = start; i <= end; i++) {
    // 4で割ってるのは
    // > 書き込むときは上位2ビットを0に、読み込むときは上位2bitを0と見なす
    // http://oswiki.osask.jp/?cmd=read&page=VGA&word=32%20bit
    // これが理由
    io_out8(0x03c9, rgb[0] / 4);
    io_out8(0x03c9, rgb[1] / 4);
    io_out8(0x03c9, rgb[2] / 4);
    rgb += 3;
  }
  io_store_eflags(eflags);
  return;
}

void boxfill8(unsigned char *vram, int xsize, unsigned char color, int x0, int y0, int x1, int y1) {
  for (int y = y0; y <= y1; y++) {
    for (int x = x0; x <= x1; x++) {
      vram[y * xsize + x] = color;
    }
  }
}
