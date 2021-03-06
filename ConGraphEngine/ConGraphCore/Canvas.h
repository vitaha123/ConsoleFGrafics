#ifndef CANVAS_H
#define CANVAS_H

#include <windows.h>
#include <string>
#include "../ConGraphCore/Macros.h"
#include "../ConGraphCore/Utils.h"
#include "../ConGraphCore/Console.h"


class Canvas
{
  //msdn
  struct Cell
  {
    CHAR_INFO *info_ = nullptr;
    void set(char character, COLOR color, COLOR background);
  };

  //wchar, char & attributes
  CHAR_INFO* charInfo_ = nullptr;
  Cell **cells_ = nullptr;
  int width_ = 0;
  int height_ = 0;

  //Small point of display (like a pixel)
  void cell(int x, int y, char character, COLOR color, COLOR background, BaseDrawElement clipRect);

  //char setup widht & hight
  void resizeCharInfo(int width, int height);

  void resizeCells(int width, int height);

public:
  Canvas();
  Canvas(int width, int height);
  ~Canvas();
  //return width
  int getWidth();
  //return height
  int getHeight();

  //resize screen width heihgt 
  void resize(int width, int height);

  //filling points " ";
  void clear(COLOR color);

  //clear, resize rect
  void clear(COLOR color, BaseDrawElement rect);

  //Rectangle Drowing
  void drawRect(BaseDrawElement rect, char character, COLOR color, COLOR background);

  //
  void drawText(int x, int y, std::string str, COLOR color, COLOR background);

  void drawCell(int x, int y, char character, COLOR color, COLOR background);

  void drawCircle(int x, int y, int radius, char character, COLOR drowColor, COLOR background, bool isFill=true);
 
  void display(Console &console);
};

#endif // CANVAS_H