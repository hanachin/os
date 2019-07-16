#define FONT_WIDTH_MAX 6
typedef struct font {
  unsigned char height;
  unsigned char width;
  signed char offset_x;
  signed char offset_y;
  unsigned char bitmap[8];
} Font;
