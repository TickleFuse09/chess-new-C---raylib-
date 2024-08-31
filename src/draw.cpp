#include"draw.h"
#include"globals.h"
#include"raylib.h"


void InitBoard() {
    // Initialize pawns
    for (int i = 0; i < 8; i++) {
        board[1][i] = ChessPiece(PAWN, BLACK_PIECE);
        board[6][i] = ChessPiece(PAWN, WHITE_PIECE);
    }

    // Initialize rooks
    board[0][0] = board[0][7] = ChessPiece(ROOK, BLACK_PIECE);
    board[7][0] = board[7][7] = ChessPiece(ROOK, WHITE_PIECE);

    // Add other pieces similarly...
}

void DrawChessboard(int startX, int startY, int squareSize) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Color color = (i + j) % 2 == 0 ? WHITE : GRAY;
            DrawRectangle(startX + j * squareSize, startY + i * squareSize, squareSize, squareSize, color);
        }
    }
}

void DrawPiece(ChessPiece piece, int x, int y, int squareSize) {
    if (piece.type == EMPTY) return;

    Color color = (piece.color == WHITE_PIECE) ? DARKGRAY : BLACK;

    switch (piece.type) {
        case PAWN:
            DrawCircle(x + squareSize / 2, y + squareSize / 2, squareSize / 4, color);
            break;
        case ROOK:
            DrawRectangle(x + squareSize / 4, y + squareSize / 4, squareSize / 2, squareSize / 2, color);
            break;
        // Handle other pieces similarly...
        default:
            break;
    }
}

void DrawBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            DrawPiece(board[i][j], j * 100, i * 100, 100);
        }
    }
}

void DrawSelectedPiece() {
    if (pieceSelected) {
        DrawRectangleLines(selectedPosition.x * 100, selectedPosition.y * 100, 100, 100, RED);
    }
}