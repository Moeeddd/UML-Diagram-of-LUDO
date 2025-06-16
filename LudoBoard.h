#ifndef LUDOBOARD_H
#define LUDOBOARD_H
#include "raylib.h"
#include <vector>

using namespace std;

#define ScreenWidth 1200
#define ScreenHeight 900
#define CellSize 50
#define RecWidth 300
#define RecHeight 300


class LudoBoard {
    std::vector<vector<Vector2>> boardPath;
    std::vector<vector<Vector2>> finishPath;
    std::vector<Vector2> safePositions;

public:
    LudoBoard();
    void SetupBoard();
    void Draw() const;
    bool IsSafePosition(Vector2 position) const;

    //const vector<Vector2>& GetBoardPath() const;
    const vector<Vector2>& GetBoardPath(int playerIndex) const;
    const vector<Vector2>& GetFinishPath(int playerIndex) const;
};

#endif