#include "GameDraw.h"

void GameDraw::DrawMenu() {
    DrawRectangle(500, 420, 300, 80, DARKBLUE);
    DrawText("START", 585, 445, 35, WHITE);
}

void GameDraw::DrawTimer(float gameTime) {
    DrawText(TextFormat("TIME: %.0f", gameTime), 20, 60, 35, WHITE);
}

void GameDraw::DrawRestart(Rectangle restartButton) {
    DrawRectangleRec(restartButton, DARKBLUE);
    DrawText("RESTART", 585, 445, 35, WHITE);
}

void GameDraw::DrawCrosshair() {
    Vector2 mouse = GetMousePosition();

    // Outer ring
    DrawCircleLines(mouse.x, mouse.y, 18, BLACK);
    DrawCircleLines(mouse.x, mouse.y, 17, WHITE);

    // Left line
    DrawLine(mouse.x - 28, mouse.y, mouse.x - 8, mouse.y, RED);
    // Right line
    DrawLine(mouse.x + 8, mouse.y, mouse.x + 28, mouse.y, RED);
    // Top line
    DrawLine(mouse.x, mouse.y - 28, mouse.x, mouse.y - 8, RED);
    // Bottom line
    DrawLine(mouse.x, mouse.y + 8, mouse.x, mouse.y + 28, RED);

    // Small centre circle
    DrawCircle(mouse.x, mouse.y, 3, RED);
    // Black outline
    DrawCircleLines(mouse.x, mouse.y, 3, BLACK);
}
