#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "raylib.h"
//#include "MyVector.h"
#include <vector>
#include "Token.h"
#include "LudoBoard.h"
using namespace std;

enum PlayerID {
    PLAYER_GREEN = 0,
    PLAYER_RED = 1,
    PLAYER_BLUE = 2,
    PLAYER_YELLOW = 3
};

class Player {
private:
    PlayerID playerID;
    Color color;
    std::vector<Token> tokens;

public:
    Player(PlayerID id, Color color);//, int startIndex, int homeIndex, int finishStart);
    int CountTokensInState(TokenState state) const;
    PlayerID GetID() const;
    Color GetColor() const;
    std::vector<Token>& GetTokens();
    

    void Reset();
    void DrawTokens() const;

    bool CanMoveToken(int TokenIndex, int diceValue, const LudoBoard& board) const;
    bool MoveToken(int TokenIndex, int diceValue, const LudoBoard& board);//const vector<Vector2>& boardPath,
       // const vector<Vector2>& finishPaths);
};

#endif