#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "raylib.h"

#define CellSize 50

enum class TokenState { HOME, PLAYING, FINISHED };

class Token {
private:
    // Add static texture declarations
    static Texture2D redTexture;
    static Texture2D blueTexture;
    static Texture2D yellowTexture;
    static Texture2D greenTexture;
    static bool texturesLoaded;

    Color color;
    Vector2 position;
    int pathIndex;
    TokenState state;


public:
    Token(Color color);

    void MoveTo(Vector2 newPosition, int newPathIndex);
    void SendHome();
    void SetFinished();
    void SetPosition(Vector2 pos);

    Rectangle GetPosition();
    int GetPathIndex() const;
    TokenState GetState() const;
    Color GetColor() const;

    void Draw() const;

    static void LoadTextures();
    static void UnloadTextures();
};

#endif