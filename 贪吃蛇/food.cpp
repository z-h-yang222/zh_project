#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>


void Food::DrawFood(Snake& csnake)//绘制食物
{
    /*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。
      同时每5颗食物就出现一颗限时食物*/
    while (true)
    {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : csnake.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        x = tmp_x;
        y = tmp_y;
        SetCursorPosition(x, y);
        SetColor(13);
        std::cout << "★";
        food_flash_flag = true;
        food_flash_cnt = 0;
        ++cnt;
        cnt %= 5;
        if (cnt == 0)
        {
            DrawBigFood(csnake);
        }
        break;
    }
}

void Food::DrawBigFood(Snake& csnake)//绘制限时食物
{
    SetCursorPosition(5, 0);
    SetColor(11);
    std::cout << "------------------------------------------";//进度条
    progress_bar = 42;
    while (true)
    {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : csnake.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(18);
        std::cout << "■";
        big_flag = true;
        flash_flag = true;
        break;
    }
}

int Food::GetCnt()
{
    return cnt;
}

void Food::FlashBigFood()//闪烁限时食物
{
    SetCursorPosition(big_x, big_y);
    SetColor(18);
    if (flash_flag)
    {
        std::cout << "  ";
        flash_flag = false;
    }
    else
    {
        std::cout << "■";
        flash_flag = true;
    }

    SetCursorPosition(26, 0);
    SetColor(11);
    for (int i = 42; i >= progress_bar; --i)//进度条缩短
        std::cout << "\b \b";
    --progress_bar;
    if (progress_bar == 0) {
        SetCursorPosition(big_x, big_y);
        std::cout << "  ";
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}

void Food::FlashFood()//闪烁普通食物
{
    if (x == 0 && y == 0) return;
    ++food_flash_cnt;
    const int kInterval = 4;//每kInterval个游戏tick切换一次显示状态
    if (food_flash_cnt % kInterval != 0) return;

    SetCursorPosition(x, y);
    SetColor(13);
    if (food_flash_flag)
    {
        std::cout << "  ";
        food_flash_flag = false;
    }
    else
    {
        std::cout << "★";
        food_flash_flag = true;
    }
}

bool Food::GetBigFlag()
{
    return big_flag;
}

int Food::GetProgressBar()
{
    return progress_bar;
}
