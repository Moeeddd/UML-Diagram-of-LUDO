#include "Token.h"

Texture2D Token::redTexture = { 0 };
Texture2D Token::blueTexture = { 0 };
Texture2D Token::yellowTexture = { 0 };
Texture2D Token::greenTexture = { 0 };
bool Token::texturesLoaded = false;

Token::Token(Color color) : color(color), position({-1, -1}), pathIndex(-1), state(TokenState::HOME) {}

void Token::MoveTo(Vector2 newPosition, int newPathIndex) {
    position = newPosition;
    pathIndex = newPathIndex;
    state = TokenState::PLAYING;
}

void Token::LoadTextures() {
    if (!texturesLoaded) {
        redTexture = LoadTexture("red.png");
        blueTexture = LoadTexture("blue.png");
        yellowTexture = LoadTexture("yellow.png");
        greenTexture = LoadTexture("green.png");
        texturesLoaded = true;
    }
}

void Token::UnloadTextures() {
    if (texturesLoaded) {
        UnloadTexture(redTexture);
        UnloadTexture(blueTexture);
        UnloadTexture(yellowTexture);
        UnloadTexture(greenTexture);
        texturesLoaded = false;
    }
}

void Token::SendHome() {
    state = TokenState::HOME;
    pathIndex = -1;
}

void Token::SetFinished() {
    state = TokenState::FINISHED;
    pathIndex = -1;
}

Rectangle Token::GetPosition() {
    Rectangle textureRect = { position.x, position.y, 50, 50 };
    return textureRect;
}
int Token::GetPathIndex() const { return pathIndex; }
TokenState Token::GetState() const { return state; }
Color Token::GetColor() const { return color; }

void Token::Draw() const {
    if (!texturesLoaded) return;
    //if (state == TokenState::FINISHED) return;
    float tokenSize = CellSize * 0.8f;
    float offset = (CellSize - tokenSize) / 2;

    if (ColorIsEqual(color, RED)) {
        DrawTextureEx(redTexture, { position.x + offset, position.y + offset },
            0, tokenSize / redTexture.width, WHITE);
    }
    else if (ColorIsEqual(color, BLUE)) {
        DrawTextureEx(blueTexture, { position.x + offset, position.y + offset },
            0, tokenSize / blueTexture.width, WHITE);
    }
    else if (ColorIsEqual(color, YELLOW)) {
        DrawTextureEx(yellowTexture, { position.x + offset, position.y + offset },
            0, tokenSize / yellowTexture.width, WHITE);
    }
    else if (ColorIsEqual(color, GREEN)) {
        DrawTextureEx(greenTexture, { position.x + offset, position.y + offset },
            0, tokenSize / greenTexture.width, WHITE);
    }
    /*if (ColorIsEqual(color, RED)) {
        DrawTexture(redToken, position.x, position.y, RED);
    }
    else if (ColorIsEqual(color, BLUE)) {
        DrawTexture(blueToken, position.x, position.y, BLUE);
    }
    else if (ColorIsEqual(color, YELLOW)) {
        DrawTexture(yellowToken, position.x, position.y, YELLOW);
    }
    else if (ColorIsEqual(color, GREEN)) {
        DrawTexture(greenToken, position.x, position.y, GREEN);
    }*/
}

void Token::SetPosition(Vector2 pos) {
    position = pos;
}