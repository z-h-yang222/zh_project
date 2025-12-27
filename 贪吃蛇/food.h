#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

class Snake;

class Food
{
public:
    Food()
        : cnt(0),
          flash_flag(false),
          big_flag(false),
          food_flash_flag(true),
          food_flash_cnt(0),
          x(0),
          y(0),
          big_x(0),
          big_y(0),
          progress_bar(0) {}

    void DrawFood(Snake&);
    void FlashFood();      // 闪烁普通食物（★）
    void DrawBigFood(Snake&);
    int GetCnt();
    void FlashBigFood();   // 闪烁限时食物（■）
    bool GetBigFlag();
    int GetProgressBar();

private:
    int cnt;
    bool flash_flag;       // 闪烁限时食物标记
    bool big_flag;         // 是否有限时食物标记

    bool food_flash_flag;  // 普通食物是否显示（用于闪烁）
    int food_flash_cnt;    // 普通食物闪烁计数

    int x, y;
    int big_x, big_y;
    int progress_bar;      // 限时食物进度条

    friend class Snake;
};

#endif // FOOD_H
