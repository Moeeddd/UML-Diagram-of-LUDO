#include "Dice.h"
#include "raylib.h"

Dice::Dice(Rectangle bounds) : value(1), bounds(bounds), rolled(false) {}

void Dice::Roll() {
    value = GetRandomValue(1, 6);
    rolled = true;
}

void Dice::Draw() const {
    DrawRectangleRec(bounds, BEIGE);
    DrawRectangleLinesEx(bounds, 2, BLACK);

    // Draw dots based on value
    float centerX = bounds.x + bounds.width / 2;
    float centerY = bounds.y + bounds.height / 2;
    float offset = bounds.width / 4;

    if (value % 2 == 1) // Center dot for odd numbers
        DrawCircle(centerX, centerY, 5, BLACK);

    if (value >= 2) {
        DrawCircle(centerX - offset, centerY - offset, 5, BLACK);
        DrawCircle(centerX + offset, centerY + offset, 5, BLACK);
    }

    if (value >= 4) {
        DrawCircle(centerX + offset, centerY - offset, 5, BLACK);
        DrawCircle(centerX - offset, centerY + offset, 5, BLACK);
    }

    if (value == 6) {
        DrawCircle(centerX - offset, centerY, 5, BLACK);
        DrawCircle(centerX + offset, centerY, 5, BLACK);
    }
}

int Dice::GetValue() const { return value; }
bool Dice::WasRolled() const { return rolled; }
void Dice::Reset() { rolled = false; }

bool Dice::CheckClick(Vector2 point) const {
    return CheckCollisionPointRec(point, bounds);
}