#include "Player.h"
#include "LudoBoard.h"

Player::Player(PlayerID id, Color color)
    : playerID(id), color(color) {
    for (int i = 0; i < 4; i++) {
        tokens.emplace_back(color);
    }
}

int Player::CountTokensInState(TokenState state) const {
    int count = 0;
    for (const auto& token : tokens) {
        if (token.GetState() == state) count++;
    }
    return count;
}

PlayerID Player::GetID() const { return playerID; }
Color Player::GetColor() const { return color; }
std::vector<Token>& Player::GetTokens() { return tokens; }

void Player::Reset() {
    for (auto& token : tokens) {
        token.SendHome();
    }
}

void Player::DrawTokens() const {
    for (const auto& token : tokens) {
        token.Draw();
    }
}

bool Player::CanMoveToken(int tokenIndex, int diceValue, const LudoBoard& board) const {
    const Token& token = tokens[tokenIndex];
    if (token.GetState() == TokenState::FINISHED) {
        return false;
    }

    const auto& mainPath = board.GetBoardPath(static_cast<int>(playerID));
    const auto& finishPath = board.GetFinishPath(static_cast<int>(playerID));
    int currentIndex = token.GetPathIndex();

    if (token.GetState() == TokenState::HOME) {
        return (diceValue == 6);
    }

    // Check if token is in finish path
    if (currentIndex >= mainPath.size()) {
        int finishIndex = currentIndex - mainPath.size();
        return (finishIndex + diceValue < finishPath.size());
    }

    // Check if token can enter finish path
    int newIndex = currentIndex + diceValue;
    if (newIndex >= mainPath.size() && newIndex < mainPath.size() + finishPath.size()) {
        return true;
    }

    // Normal movement
    return (newIndex < mainPath.size());
}

bool Player::MoveToken(int tokenIndex, int diceValue, const LudoBoard& board) {
    Token& token = tokens[tokenIndex];
    const auto& mainPath = board.GetBoardPath(static_cast<int>(playerID));
    const auto& finishPath = board.GetFinishPath(static_cast<int>(playerID));
    int mainPathSize = mainPath.size();
    int finishPathSize = finishPath.size();

    if (token.GetState() == TokenState::HOME) {
        if (diceValue != 6) return false;
        token.MoveTo(mainPath[0], 0);
        return true;
    }

    int currentIndex = token.GetPathIndex();

    // Handle movement in finish path
    if (currentIndex >= mainPathSize) {
        int finishIndex = currentIndex - mainPathSize;
        int newFinishIndex = finishIndex + diceValue;

        if (newFinishIndex < finishPathSize) {
            token.MoveTo(finishPath[newFinishIndex], mainPathSize + newFinishIndex);
            if (newFinishIndex == finishPathSize - 1) {
                token.SetFinished();
            }
            return true;
        }
        return false; // Overshot finish path
    }

    // Main path movement
    int newIndex = currentIndex + diceValue;

    // Check if can enter finish path
    if (newIndex >= mainPathSize && newIndex < mainPathSize + finishPathSize) {
        int finishIndex = newIndex - mainPathSize;
        token.MoveTo(finishPath[finishIndex], newIndex);
        if (finishIndex == finishPathSize - 1) {
            token.SetFinished();
        }
        return true;
    }

    // Normal movement on main path
    if (newIndex < mainPathSize) {
        token.MoveTo(mainPath[newIndex], newIndex);
        return true;
    }

    return false; // Invalid move
}