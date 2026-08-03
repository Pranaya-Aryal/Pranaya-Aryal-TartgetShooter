#pragma once
#include <raylib.h>
#include "GameState.h"
#include "Target.h"
#include "GameDraw.h"
class Game {
public:
    void Run();
private:
    void Init();
    void Shutdown();
    void HandleMenu();
    void HandlePlaying();
    void HandleGameOver();

    int count = 0;
    float gameTime = 30.0f;
    bool timeStart = false;
    
    GameState state = Menu;
    GameDraw gameDraw;
    Target target;
    Texture2D background{};
    Rectangle startButton = {500, 420, 300, 80};
    Rectangle restartButton = {520, 420, 300, 80};
};
