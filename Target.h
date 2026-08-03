#pragma once
#include <raylib.h>

class Target {
public:
    Vector2 position;

    Target();

    Vector2 GenerateRandomPos();
    void DrawTarget();
    bool IsHit(Vector2 mousePos);
    void Relocate();
};
