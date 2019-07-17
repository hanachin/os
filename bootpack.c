#include "font.h"
#include "mathfont_f.inc"
#include "mathfont.h"

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

struct BOOTINFO {
  char cyls, leds, vmode, reserve;
  short scrnx, scrny;
  char *vram;
};

void io_hlt(void);
void io_cli(void);
void io_out8(int port, int data);
int io_load_eflags(void);
void io_store_eflags(int eflags);

void init_palette();
void set_palette(int start, int end, unsigned char *rgb);
void boxfill8(unsigned char *vram, int xsize, unsigned char color, int x0, int y0, int x1, int y1);
Font *getfont(unsigned char c);
void putstring(unsigned char *vram, int xsize, int x, int base, unsigned char color, unsigned char *s);
void putfont(unsigned char *vram, int xsize, int x, int base, unsigned char color, Font *f);
void init_mouse_cursor8(char *mouse, char bc);
void putblock(char *vram, int vxsize, int pxsize, int pysize, int px0, int py0, char *buf, int bxsize);

void putstring2(unsigned char *vram, int xsize, int x, int y, unsigned char color, char *s);
void putfont2(unsigned char *vram, int xsize, int x, int y, unsigned char color, char c);


#define FONT_SIZE 16
#define MOUSE_SIZE 105

void HariMain(void)
{
  init_palette();

  struct BOOTINFO *binfo = (struct BOOTINFO *)0x0ff0;

  char *vram = binfo->vram;
  int xsize = binfo->scrnx, ysize = binfo->scrny;

  boxfill8(vram, 320, COLOR_DARK_LIGHT_BLUE, 0, 0, xsize -1, ysize - 29); // 背景

  boxfill8(vram, 320, COLOR_GRAY, 0, ysize - 28, xsize -1, ysize - 28); // タスクバーのボーダー
  boxfill8(vram, 320, COLOR_WHITE, 0, ysize - 27, xsize -1, ysize - 27); // タスクバーのボーダーハイライト
  boxfill8(vram, 320, COLOR_GRAY, 0, ysize - 26, xsize -1, ysize - 1); // タスクバーのボーダー

  boxfill8(vram, 320, COLOR_WHITE,     3,  ysize - 24, 59, ysize - 24); // スタートボタンのボーダー↑
  boxfill8(vram, 320, COLOR_WHITE,     2,  ysize - 24,  2, ysize - 4); // スタートボタンのボーダー←
  boxfill8(vram, 320, COLOR_DARK_GRAY, 3,  ysize -  4, 59, ysize - 4); // スタートボタンのボーダー↓
  boxfill8(vram, 320, COLOR_DARK_GRAY, 59, ysize - 23, 59, ysize - 4); // スタートボタンのボーダー→

  boxfill8(vram, 320, COLOR_BLACK,     2,  ysize -  3, 59, ysize - 3); // スタートボタンの影↓
  boxfill8(vram, 320, COLOR_BLACK,    60,  ysize - 24, 60, ysize - 3); // スタートボタンの影→

  boxfill8(vram, 320, COLOR_DARK_GRAY, xsize - 47,  ysize - 24, xsize - 4, ysize - 24); // 時計とかでるとこ↑
  boxfill8(vram, 320, COLOR_DARK_GRAY, xsize - 47,  ysize - 23, xsize - 47, ysize - 4); // 時計とかでるとこ←
  boxfill8(vram, 320, COLOR_WHITE, xsize - 47,  ysize - 3, xsize - 4, ysize - 3); // 時計とかでるとこ→
  boxfill8(vram, 320, COLOR_WHITE, xsize - 3,  ysize - 24, xsize - 3, ysize - 3); // 時計とかでるとこ↓

  putfont2(vram, xsize, 20, 26, COLOR_WHITE, 'c');

  // putstring2(vram, xsize, 20, 26, COLOR_WHITE, "hello, world!");
  // x, yおちる
  // c, g画面が壊れる
  putstring2(vram, xsize, 20, 46, COLOR_WHITE, "abcdefghijklmnopqrstuvwxyz");

  char mcursor[MOUSE_SIZE * MOUSE_SIZE];
  init_mouse_cursor8(mcursor, COLOR_DARK_LIGHT_BLUE);
  putblock(vram, xsize, MOUSE_SIZE, MOUSE_SIZE, 140, 20, mcursor, MOUSE_SIZE);

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

Font *getfont(unsigned char c) {
  extern Font hankaku[256];
  return hankaku + c;
}

void putstring(unsigned char *vram, int xsize, int x, int base, unsigned char color, unsigned char *s) {
  while (*s) {
    Font *f = getfont(*s);
    putfont(vram, xsize, x, base, color, f);
    x += f->width + 2;
    s++;
  }
}

void putstring2(unsigned char *vram, int xsize, int x, int base, unsigned char color, char *s) {
  while (*s) {
    putfont2(vram, xsize, x, base, color, *s);
    x += FONT_SIZE;
    s++;
  }
}

void putfont(unsigned char *vram, int xsize, int x, int base, unsigned char color, Font *f) {
  for (int i = 0; i < f->height; i++) {
    unsigned char *p = vram + (base - f->height + i - f->offset_y) * xsize + x + f->offset_x;
    for (int j = 0; j < f->width; j++) {
      if ((f->bitmap[i]) & (0b10000000 >> j)) {
        *(p + j) = color;
      }
    }
  }
}

void putfont2(unsigned char *vram, int xsize, int x, int y, unsigned char color, char c) {
  for (int i = 0; i < FONT_SIZE; i++) {
    unsigned char *p = vram + (y + i) * xsize + x;
    for (int j = 0; j < FONT_SIZE; j++) {
      int paint=0;
      switch(c) {
#include "mathfont.inc"
      }
      if (paint) {
        *(p + j) = color;
      }
    }
  }
}

void putblock(char *vram, int vxsize, int pxsize, int pysize, int px0, int py0, char *buf, int bxsize) {
  for (int y = 0; y < pysize; y++) {
    for (int x = 0; x < pxsize; x++) {
      vram[(py0 + y) * vxsize + (px0 + x)] = buf[y * bxsize + x];
    }
  }
  return;
}

void init_mouse_cursor8(char *mouse, char bc) {
  int size = MOUSE_SIZE;
  for (int x = 0; x < MOUSE_SIZE; x++) {
    for (int y = 0; y < MOUSE_SIZE; y++) {
      float a=0.1+(y-1.8*x)/size;
      float b=1.2-(x+1.8*y)/size;
      float c=b+(a<0?-a:a);
      float d=(b+c-1.4);
      d=d*d*d*d;d=d*d;
      float e=a/((1.2-c)/(1+d)+0.1-b/6);
      float f=a/((1.2-c*0.8)/(1+d)+0.15-b/6);
      if(e*e*e*e+b*b*b*b<1) mouse[y * MOUSE_SIZE + x] = COLOR_BLACK;
      else if(f*f*f*f+b*b*b*b<1.5) mouse[y * MOUSE_SIZE + x] = COLOR_YELLOW;
      else mouse[y * MOUSE_SIZE + x] = bc;
    }
  }
}