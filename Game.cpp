#include "Game.h"
#include "Colors.h"

void Game::Run() {
    Init();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawTexture(background, 0, 0, Colors::white);

        if (state == Menu) {
            HandleMenu();
        }
        if (state == Playing) {
            HandlePlaying();
        }
        if (state == GameOver) {
            HandleGameOver();
        }

        gameDraw.DrawTimer(gameTime);
        DrawText(TextFormat("Score : %i", count), 20, 20, 30, WHITE);

        EndDrawing();
    }

    Shutdown();
}

void Game::Init() {
    InitWindow(1300, 700, "retro game");
    SetWindowPosition(33, 34);
    SetTargetFPS(60);

    background = LoadTexture("imageInProject/background.png");
    HideCursor();
}

void Game::HandleMenu() {
    ShowCursor();
    gameDraw.DrawMenu();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(GetMousePosition(), startButton)) {
            state = Playing;
            count = 0;
            gameTime = 30;
            timeStart = false;
        }
    }
}

void Game::HandlePlaying() {
    HideCursor();
    target.DrawTarget();
    gameDraw.DrawCrosshair();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (target.IsHit(GetMousePosition())) {
            count++;
            target.Relocate();
            if (!timeStart) {
                timeStart = true;
            }
        }
    }

    if (timeStart == true) {
        if (gameTime >= 0) {
            gameTime -= GetFrameTime();
        } else {
            gameTime = 0;
            state = GameOver;
        }
    }
}

void Game::HandleGameOver() {
    ShowCursor();
    gameDraw.DrawRestart(restartButton);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(GetMousePosition(), restartButton)) {
            count = 0;
            gameTime = 30.0f;
            timeStart = false;
            target.Relocate();
            state = Playing;
        }
    }
}

void Game::Shutdown() {
    CloseWindow();
}
