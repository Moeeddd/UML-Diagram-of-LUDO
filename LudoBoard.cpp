#include "LudoBoard.h"

LudoBoard::LudoBoard() {
    SetupBoard();
}
                                                                          //RED
/*void LudoBoard::SetupBoard() {                                     //GREEN        BLUE
                                                                          //YELLOW
    for (int p = 0; p < 4; p++) {
        vector<Vector2> path;

        // Green path (top-left, moves right)
        if (p == 0) {
            
            for (int i = 2; i <= 5; i++)
                path.push_back({ static_cast<float>(CellSize * i), static_cast<float>(6 * CellSize) });

            //red start
            //move up
            for (int i = 0; i <= 5; i++)
                path.push_back({ 6 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(i * CellSize) });

            // blue start
            // Move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(9 + i) * CellSize, 6 * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            // Move left
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 8 * CellSize });

            // Yellow Start
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(9 + i) * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            // Move Up
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 6 * CellSize });

            // Again Green entry)
            //move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
        }
        // Red path (top-right, moves down)
        else if (p == 1) {
         
            for (int i = 2; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(i * CellSize) });

            // blue start
            // Move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(9 + i) * CellSize, 6 * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            // Move left
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 8 * CellSize });

            // Yellow Start
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(9 + i) * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            // Move Up
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 6 * CellSize });

            // Again Green entry)
            //move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(CellSize * i), static_cast<float>(6 * CellSize) });

            //red start
            //move up
            for (int i = 0; i <= 5; i++)
                path.push_back({ 6 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
        }
        // Blue path (bottom-right, moves left)
        else if (p == 2) {
            
            for (int i = 2; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 8 * CellSize });

            // Yellow Start
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(9 + i) * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            // Move Up
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 6 * CellSize });

            // Again Green entry)
            //move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });

            for (int i = 2; i <= 5; i++)
                path.push_back({ static_cast<float>(CellSize * i), static_cast<float>(6 * CellSize) });

            //red start
            //move up
            for (int i = 0; i <= 5; i++)
                path.push_back({ 6 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(i * CellSize) });

            // blue start
            // Move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(9 + i) * CellSize, 6 * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
        }
        // Yellow path (bottom-left, moves up)
        else if (p == 3) {

            for (int i = 2; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 6 * CellSize });

            // Again Green entry)
            //move left
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });

            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(CellSize * i), static_cast<float>(6 * CellSize) });

            //red start
            //move up
            for (int i = 0; i <= 5; i++)
                path.push_back({ 6 * CellSize, static_cast<float>(5 - i) * CellSize });

            path.push_back({ 7 * CellSize, 0 });
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(i * CellSize) });

            // blue start
            // Move right
            for (int i = 0; i <= 5; i++)
                path.push_back({ static_cast<float>(9 + i) * CellSize, 6 * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
            for (int i = 2; i <= 5; i++)
                path.push_back({ static_cast<float>(14 - i) * CellSize, 8 * CellSize });

            // Yellow Start
            // Move down
            for (int i = 0; i <= 5; i++)
                path.push_back({ 8 * CellSize, static_cast<float>(9 + i) * CellSize });

            path.push_back({ 14 * CellSize, 7 * CellSize });
        }
        boardPath.push_back(path);
    }
    
    for (int p = 0; p < 4; p++) {
        vector<Vector2> path;

        // Green finish (down)
        if (p == 0) {
            for (int i = 0; i < 6; i++) {
                path.push_back({ CellSize * 7, static_cast<float>(CellSize * (2 + i)) });
            }
        }
        // Red finish (left)
        else if (p == 1) {
            for (int i = 0; i < 6; i++) {
                path.push_back({ static_cast<float>(CellSize * (12 - i)), CellSize * 7 });
            }
        }
        // Blue finish (up)
        else if (p == 2) {
            for (int i = 0; i < 6; i++) {
                path.push_back({ CellSize * 7, static_cast<float>(CellSize * (12 - i)) });
            }
        }
        // Yellow finish (right)
        else if (p == 3) {
            for (int i = 0; i < 6; i++) {
                path.push_back({ static_cast<float>(CellSize * (2 + i)), CellSize * 7 });
            }
        }

        finishPath.push_back(path);
    }
}*/

void LudoBoard::SetupBoard() {
    // Clear existing paths
    boardPath.clear();
    finishPath.clear();

    // Define the main track positions (clockwise from GREEN start)
    vector<Vector2> mainTrack;

    for (int i = 1; i <= 5; i++)
        mainTrack.push_back({ static_cast<float>(CellSize * i), static_cast<float>(6 * CellSize) });

    //red start
    //move up
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ 6 * CellSize, static_cast<float>(5 - i) * CellSize });

    mainTrack.push_back({ 7 * CellSize, 0 });
    // Move down
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ 8 * CellSize, static_cast<float>(i * CellSize) });

    // blue start
    // Move right
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ static_cast<float>(9 + i) * CellSize, 6 * CellSize });

    mainTrack.push_back({ 14 * CellSize, 7 * CellSize });
    // Move left
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ static_cast<float>(14 - i) * CellSize, 8 * CellSize });

    // Yellow Start
    // Move down
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ 8 * CellSize, static_cast<float>(9 + i) * CellSize });

    mainTrack.push_back({ 7 * CellSize, 14 * CellSize });
    // Move Up
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ 6 * CellSize, static_cast<float>(14 - i) * CellSize });

    // Again Green entry)
    //move left
    for (int i = 0; i <= 5; i++)
        mainTrack.push_back({ static_cast<float>(5 - i) * CellSize, 8 * CellSize });

    mainTrack.push_back({ 0, 7 * CellSize });
    mainTrack.push_back({ 0, 6 * CellSize });

    // Create paths for each player by rotating the main track
    for (int player = 0; player < 4; player++) {
        vector<Vector2> path;
        int startIndex = player * 13;  // 52 steps / 4 players = 13 steps offset

        for (int i = 0; i < 52; i++) {
            int index = (startIndex + i) % mainTrack.size();  // Safe modulo
            path.push_back(mainTrack[index]);
        }
        boardPath.push_back(path);
    }

    // Create finish paths for each player (unchanged)
    for (int player = 0; player < 4; player++) {
        vector<Vector2> path;

        switch (player) {
        case 0: // GREEN - finish upwards
            for (int i = 1; i <= 6; i++) {
                path.push_back({ static_cast<float>(CellSize * i), CellSize * 7 });
            }
            break;
        case 1: // RED - finish rightwards
            for (int i = 1; i <= 6; i++) {
                path.push_back({ CellSize * 7, static_cast<float>(CellSize * i) });
            }
            break;
        case 2: // BLUE - finish downwards
            for (int i = 0; i < 6; i++) {
                path.push_back({ static_cast<float>(CellSize * (13 - i)), CellSize * 7 });
            }
            break;
        case 3: // YELLOW - finish leftwards
            for (int i = 0; i < 6; i++) {
                path.push_back({ CellSize * 7, static_cast<float>(CellSize * (13 - i)) });
            }
            break;
        }
        finishPath.push_back(path);
    }

    // Define safe positions (star squares) - unchanged
    safePositions = {
        {CellSize, 6 * CellSize},       // Green Home Safe
        {2 * CellSize, 8 * CellSize},   // Green Grey Safe
        {8 * CellSize, CellSize},       // Red Home Safe
        {6 * CellSize, 2 * CellSize},   // Red Grey Safe
        {13 * CellSize, 8 * CellSize},  // Blue Home Safe
        {12 * CellSize, 6 * CellSize},  // Blue Grey Safe
        {6 * CellSize, 13 * CellSize }, // Yellow Home Safe
        {8 * CellSize, 12 * CellSize}   // Yellow Grey Safe   
    };
}

// Helper function remains unchanged
bool LudoBoard::IsSafePosition(Vector2 position) const {
    for (const auto& safePos : safePositions) {
        if (position.x == safePos.x && position.y == safePos.y) {
            return true;
        }
    }
    return false;
}

const vector<Vector2>& LudoBoard::GetBoardPath(int playerIndex) const {
    return boardPath[playerIndex];
}

const vector<Vector2>& LudoBoard::GetFinishPath(int playerIndex) const { 
    return finishPath[playerIndex];
}

void LudoBoard::Draw() const {
   
    // Draw corner home areas
    DrawRectangle(0, 0, RecWidth, RecHeight, DARKGREEN);                        // Top-left (DARKGREEN)
    DrawRectangle(CellSize * 9, 0, RecWidth, RecHeight, RED);                   // Top-right (Red)
    DrawRectangle(0, CellSize * 9, RecWidth, RecHeight, GOLD);                  // Bottom-left (GOLD)
    DrawRectangle(CellSize * 9, CellSize * 9, RecWidth, RecHeight, DARKBLUE);   // Bottom-right (DARKBLUE)

    // Draw colored paths leading to center
    DrawRectangle(CellSize, CellSize * 7, CellSize * 5, CellSize, DARKGREEN);   // Left (DARKGREEN)
    DrawRectangle(CellSize * 7, CellSize, CellSize, CellSize * 5, RED);         // Top (Red)
    DrawRectangle(CellSize * 7, CellSize * 9, CellSize, CellSize * 5, GOLD);    // Bottom (GOLD)
    DrawRectangle(CellSize * 9, CellSize * 7, CellSize * 5, CellSize, DARKBLUE);// Right (DARKBLUE)

    // Draw starting positions (just outside home areas)
    DrawRectangle(CellSize, CellSize * 6, CellSize, CellSize, DARKGREEN);       // DARKGREEN start
    DrawRectangle(CellSize * 8, CellSize, CellSize, CellSize, RED);             // Red start
    DrawRectangle(CellSize * 6, CellSize * 13, CellSize, CellSize, GOLD);       // GOLD start
    DrawRectangle(CellSize * 13, CellSize * 8, CellSize, CellSize, DARKBLUE);   // DARKBLUE start

    // Draw safe squares (dark gray)
    DrawRectangle(CellSize * 6, CellSize * 2, CellSize, CellSize, DARKGRAY);
    DrawRectangle(CellSize * 12, CellSize * 6, CellSize, CellSize, DARKGRAY);
    DrawRectangle(CellSize * 2, CellSize * 8, CellSize, CellSize, DARKGRAY);
    DrawRectangle(CellSize * 8, CellSize * 12, CellSize, CellSize, DARKGRAY);

    // Draw player token positions (white squares)
    // DARKGREEN positions
    DrawRectangle(CellSize, CellSize, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize, CellSize * 4, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 4, CellSize * 4, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 4, CellSize, CellSize, CellSize, WHITE);

    // Red positions
    DrawRectangle(CellSize * 10, CellSize, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 10, CellSize * 4, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 13, CellSize * 4, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 13, CellSize, CellSize, CellSize, WHITE);

    // DARKBLUE positions
    DrawRectangle(CellSize * 10, CellSize * 10, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 10, CellSize * 13, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 13, CellSize * 10, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 13, CellSize * 13, CellSize, CellSize, WHITE);

    // GOLD positions
    DrawRectangle(CellSize, CellSize * 10, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize, CellSize * 13, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 4, CellSize * 10, CellSize, CellSize, WHITE);
    DrawRectangle(CellSize * 4, CellSize * 13, CellSize, CellSize, WHITE);

    // Draw colored triangles in the center
    DrawTriangle(
        { 6 * CellSize, 6 * CellSize },
        { 6 * CellSize, 9 * CellSize },
        { 7.5f * CellSize, 7.5f * CellSize },
        DARKGREEN
    );
    DrawTriangle(
        { 6 * CellSize, 6 * CellSize },
        { 7.5f * CellSize, 7.5f * CellSize },
        { 9 * CellSize, 6 * CellSize },
        RED
    );
    DrawTriangle(
        { 7.5f * CellSize, 7.5f * CellSize },
        { 6 * CellSize, 9 * CellSize },
        { 9 * CellSize, 9 * CellSize },
        GOLD
    );
    DrawTriangle(
        { 7.5f * CellSize, 7.5f * CellSize },
        { 9 * CellSize, 9 * CellSize },
        { 9 * CellSize, 6 * CellSize },
        DARKBLUE
    );

    // Draw grid lines for the central path
    // Left-middle section (6 rows x 3 columns)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            DrawRectangleLines(j * CellSize, (6 + i) * CellSize, CellSize, CellSize, BLACK);
        }
    }
    // Right-middle section (6 rows x 3 columns)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            DrawRectangleLines((9 + j) * CellSize, (6 + i) * CellSize, CellSize, CellSize, BLACK);
        }
    }
    // Top-middle section (3 rows x 6 columns)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            DrawRectangleLines((6 + i) * CellSize, j * CellSize, CellSize, CellSize, BLACK);
        }
    }
    // Bottom-middle section (3 rows x 6 columns)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            DrawRectangleLines((6 + i) * CellSize, (9 + j) * CellSize, CellSize, CellSize, BLACK);
        }
    }
    //DrawRectangleLines(0, 0, 750, 750, BLACK);
    Texture2D pic = LoadTexture("profile.jpg");
    DrawTexture(pic, 750, 0, DARKBLUE);
}