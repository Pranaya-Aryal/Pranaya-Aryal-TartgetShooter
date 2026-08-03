#pragma once
#include <raylib.h>

class GameDraw {
public:
    void DrawMenu();
    void DrawTimer(float gameTime);
    void DrawRestart(Rectangle restartButton);
    void DrawCrosshair();
};
