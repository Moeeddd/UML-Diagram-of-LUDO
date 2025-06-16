#include "Game.h"

Game::Game()
    : dice({ ScreenWidth - CellSize * 2, CellSize * 2.5, 1.5 * CellSize, 1.5 * CellSize }),
    currentPlayer(0), gameOver(false) {

    board.SetupBoard();
    // Initialize players with their start, home, and finish positions
    players.emplace_back(PLAYER_GREEN, GREEN);
    players.emplace_back(PLAYER_RED, RED);
    players.emplace_back(PLAYER_BLUE, BLUE);
    players.emplace_back(PLAYER_YELLOW, YELLOW);

    for (int p = 0; p < players.size(); p++) {
        //auto& player = players[p];
        for (int i = 0; i < players[p].GetTokens().size(); i++) {
            Vector2 homePos = GetHomePosition(p, i);
            players[p].GetTokens()[i].SetPosition(homePos);
        }
    }
}

Game::~Game() {}

void Game::DrawUI() const {
    const char* playerColors[] = { "GREEN", "RED", "BLUE", "YELLOW" };
    DrawText(TextFormat("Current Player Turn: %s", playerColors[currentPlayer]), 780, 50, 20, WHITE);
    DrawText("Press SPACE to roll dice", 780, 100, 20, WHITE);
    
    if (dice.WasRolled()) {
        DrawText("Click on a Token to move", 780, 200, 20, WHITE);
        DrawText(TextFormat("Dice: %d", dice.GetValue()), 780, 150, 20, WHITE);
    }

    int yPos = 250;
    for (int i = 0; i < players.size(); i++) {
        
        // Player header
        DrawText(TextFormat("%s PLAYER:", playerColors[i]), 780, yPos, 20, players[i].GetColor());
        yPos += 25;

        // Token counts
        DrawText(TextFormat("Home: %d", players[i].CountTokensInState(TokenState::HOME)),
            800, yPos, 20, WHITE);
        DrawText(TextFormat("Playing: %d", players[i].CountTokensInState(TokenState::PLAYING)),
            800, yPos + 25, 20, WHITE);
        DrawText(TextFormat("Finished: %d", players[i].CountTokensInState(TokenState::FINISHED)),
            800, yPos + 50, 20, WHITE);

        yPos += 100;  // Space before next player
    }
}

void Game::NextPlayer() {
    currentPlayer = (currentPlayer + 1) % players.size();
}

Vector2 Game::GetHomePosition(int playerIndex, int TokenIndex) const {
    int homeX = 0, homeY = 0;
    
    switch (playerIndex) {
    case 0: // Green
        homeX = CellSize + (3 * (TokenIndex % 2) * CellSize);
        homeY = CellSize + (3 * (TokenIndex / 2) * CellSize);
        break;
    case 1: // Red
        homeX = CellSize * 10 + (3 * (TokenIndex % 2) * CellSize);
        homeY = CellSize + (3 * (TokenIndex / 2) * CellSize);
        break;
        
    case 2: // Blue
        homeX = CellSize * 10 + (3 * (TokenIndex % 2) * CellSize);
        homeY = CellSize * 10 + (3 * (TokenIndex / 2) * CellSize);
        break;
    case 3: // Yellow
        homeX = CellSize + (3 * (TokenIndex % 2) * CellSize);
        homeY = CellSize * 10 + (3 * (TokenIndex / 2) * CellSize);
        break;
    }
 
    return { static_cast<float>(homeX), static_cast<float>(homeY) };
}

void Game::CheckTokenCollision(Player& currentPlayerObj, int movedTokenIndex) {
    Token& movedToken = currentPlayerObj.GetTokens()[movedTokenIndex];
    if (movedToken.GetState() != TokenState::PLAYING) return;

    Vector2 currentPosition = { movedToken.GetPosition().x, movedToken.GetPosition().y };

    // Check if position is safe (star square)
    if (board.IsSafePosition(currentPosition)) {
        return;
    }

    for (int i = 0; i < players.size(); i++) {
        if (i == currentPlayer) continue;

        for (auto& token : players[i].GetTokens()) {
            if (token.GetState() == TokenState::PLAYING) {
                Vector2 tokenPosition = { token.GetPosition().x, token.GetPosition().y };

                // Simple collision detection (same cell)
                if (currentPosition.x == tokenPosition.x &&
                    currentPosition.y == tokenPosition.y) {
                    token.SendHome();

                    // Reset opponent token's position
                    for (int j = 0; j < players[i].GetTokens().size(); j++) {
                        if (&token == &players[i].GetTokens()[j]) {
                            Vector2 homePos = GetHomePosition(i, j);
                            token.SetPosition(homePos);
                            token.Draw();
                            break;
                        }
                    }
                }
            }
        }
    }
}


void Game::Run() {
    InitWindow(ScreenWidth, ScreenHeight, "Ludo Game");
    SetTargetFPS(60);

    enum GameState {
        MENU,
        GAME
    };
    GameState currentState = MENU;

    Texture2D display = LoadTexture("display.jpg");
    // Load textures once
    Token::LoadTextures();
    
    while (!WindowShouldClose() && !gameOver) {
        
        // Handle input
        if (IsKeyPressed(KEY_SPACE) && !dice.WasRolled()) {
            dice.Roll();
        }

        if (dice.WasRolled() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            Player& currentPlayerObj = players[currentPlayer];
            bool moved = false;

            for (int i = 0; i < currentPlayerObj.GetTokens().size(); i++) {
                Token& token = currentPlayerObj.GetTokens()[i];
                Rectangle tokenRect = token.GetPosition();

                if (CheckCollisionPointRec(mousePos, tokenRect)) {
                    if (currentPlayerObj.CanMoveToken(i, dice.GetValue(), board)) {
                        if (currentPlayerObj.MoveToken(i, dice.GetValue(), board)) {
                            CheckTokenCollision(currentPlayerObj, i);
                            moved = true;

                            // Check win condition
                            bool allFinished = true;
                            for (auto& t : currentPlayerObj.GetTokens()) {
                                if (t.GetState() != TokenState::FINISHED) {
                                    allFinished = false;
                                    break;
                                }
                            }
                            if (allFinished) {
                                gameOver = true;
                            }

                            break; // Only move one token per click
                        }
                    }
                }
            }

            if (moved) {
                if (dice.GetValue() != 6 && !gameOver) {
                    NextPlayer();
                }
                dice.Reset();
            }
            else {
                // Check if player has no valid moves
                bool canMove = false;
                for (int i = 0; i < currentPlayerObj.GetTokens().size(); i++) {
                    if (currentPlayerObj.CanMoveToken(i, dice.GetValue(), board)) {
                        canMove = true;
                        break;
                    }
                }

                if (!canMove) {
                    NextPlayer();
                    dice.Reset();
                }
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentState == MENU) {
            // Draw the start menu
            DrawTexture(display, 50, 0, WHITE);
            DrawText("LUDO GAME!", 400, 200, 60, WHITE);
            DrawText("Press ENTER to start...", 250, 300, 60, WHITE);

            if (IsKeyPressed(KEY_ENTER)) {
                currentState = GAME;
            }

        }
        else if (currentState == GAME) {
            // Draw the main game
            board.Draw();
            for (auto& player : players) {
                for (auto& token : player.GetTokens()) {
                    token.Draw();
                }
            }
            dice.Draw();
            DrawUI();

            if (gameOver) {
                DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(BLACK, 0.5f));
                const char* playerColors[] = { "GREEN", "RED", "BLUE", "YELLOW" };
                DrawText(TextFormat("%s PLAYER WINS!", playerColors[currentPlayer]),
                    ScreenWidth / 2 - 150, ScreenHeight / 2 - 30, 40, WHITE);
                DrawText("Press ESC to exit", ScreenWidth / 2 - 100, ScreenHeight / 2 + 30, 30, WHITE);
            }
        }
       
        /*board.Draw();
        for (auto& player : players) {
            for (auto& token : player.GetTokens()) {
                token.Draw();
            }
        }
        dice.Draw();
        DrawUI();

        if (gameOver) {
            DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(BLACK, 0.5f));
            const char* playerColors[] = { "GREEN", "RED", "BLUE", "YELLOW" };
            DrawText(TextFormat("%s PLAYER WINS!", playerColors[currentPlayer]),
                ScreenWidth / 2 - 150, ScreenHeight / 2 - 30, 40, WHITE);
            DrawText("Press ESC to exit", ScreenWidth / 2 - 100, ScreenHeight / 2 + 30, 30, WHITE);
        }*/

        EndDrawing();

        if (gameOver && IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
    }

    // Unload textures
    Token::UnloadTextures();
    CloseWindow();
}