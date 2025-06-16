#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Token.h"
#include "LudoBoard.h"
#include "Dice.h"
#include <vector>
using namespace std;

#define ScreenWidth 1100
#define ScreenHeight 750
#define CellSize 50

class Game {
private:
    LudoBoard board;
    Dice dice;
    vector<Player> players;
    int currentPlayer;
    bool gameOver;

    void DrawUI() const;
    void NextPlayer();
    void CheckTokenCollision(Player& currentPlayerObj, int movedTokenIndex);
    Vector2 GetHomePosition(int playerIndex, int TokenIndex) const;

public:
    Game();
    ~Game();

    void Run();
};

#endif