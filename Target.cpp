#include "Target.h"
#include "Colors.h"

Target::Target() {
    position = GenerateRandomPos();
}

Vector2 Target::GenerateRandomPos() {
    Vector2 pos;
    pos.x = GetRandomValue(50, GetScreenWidth() - 50);
    pos.y = GetRandomValue(50, GetScreenHeight() - 50);
    return pos;
}

void Target::DrawTarget() {
    DrawCircle(position.x, position.y, 40, Colors::red);
    DrawCircleLines(position.x, position.y, 40, Colors::black);
    DrawCircle(position.x, position.y, 30, Colors::white);
    DrawCircleLines(position.x, position.y, 30, Colors::black);
    DrawCircle(position.x, position.y, 20, Colors::red);
    DrawCircleLines(position.x, position.y, 20, Colors::black);
    DrawCircle(position.x, position.y, 10, Colors::white);
    DrawCircleLines(position.x, position.y, 10, Colors::black);
    DrawCircle(position.x, position.y, 5, Colors::black);
    DrawCircleLines(position.x, position.y, 5, Colors::black);
}

bool Target::IsHit(Vector2 mousePos) {
    return CheckCollisionPointCircle(mousePos, position, 40);
}

void Target::Relocate() {
    position = GenerateRandomPos();
}
