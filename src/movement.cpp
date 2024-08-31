#include"movement.h"
#include"globals.h"
#include<math.h>

bool IsValidPawnMove(ChessPiece piece, Vector2 startPos, Vector2 endPos) {
    int direction = (piece.color == WHITE_PIECE) ? -1 : 1;

    // Standard forward move
    if (endPos.x == startPos.x && board[(int)endPos.y][(int)endPos.x].type == EMPTY) {
        // Single square move
        if (endPos.y == startPos.y + direction) return true;

        // Double square move from starting position
        if (startPos.y == ((piece.color == WHITE_PIECE) ? 6 : 1) && endPos.y == startPos.y + 2 * direction) {
            return board[(int)(startPos.y + direction)][(int)startPos.x].type == EMPTY;
        }
    }

    // Diagonal capture
    if (abs(endPos.x - startPos.x) == 1 && endPos.y == startPos.y + direction && board[(int)endPos.y][(int)endPos.x].color != piece.color && board[(int)endPos.y][(int)endPos.x].color != NONE_COLOR) {
        return true;
    }

    return false;
}


bool IsValidMove(ChessPiece piece, Vector2 startPos, Vector2 endPos) {
    if (piece.type == PAWN) {
        return IsValidPawnMove(piece, startPos, endPos);
    }

    // Implement other pieces here...
    
    return false;
}


void HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 pos = GetMousePosition();
        int squareX = pos.x / 100;
        int squareY = pos.y / 100;

        if (!pieceSelected) {
            // Select a piece if it's a valid piece to move
            if (board[squareY][squareX].type != EMPTY) {
                selectedPiece = board[squareY][squareX];
                selectedPosition = {(float)squareX, (float)squareY};
                pieceSelected = true;
            }
        } else {
            // Try to move the piece
            if (IsValidMove(selectedPiece, selectedPosition, {(float)squareX, (float)squareY})) {
                // Move the piece
                board[squareY][squareX] = selectedPiece;
                board[(int)selectedPosition.y][(int)selectedPosition.x] = ChessPiece(); // Empty the old square
                pieceSelected = false;
            }
        }
    }
}