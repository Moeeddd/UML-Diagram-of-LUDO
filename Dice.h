#ifndef DICE_H
#define DICE_H
#include "raylib.h"

class Dice {
private:
    int value;
    Rectangle bounds;
    bool rolled;

public:
    Dice(Rectangle bounds);
    void Roll();
    void Draw() const;
    int GetValue() const;
    bool WasRolled() const;
    void Reset();
    bool CheckClick(Vector2 point) const;
};

#endif