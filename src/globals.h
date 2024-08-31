#pragma once
#include"raylib.h"

enum PieceType { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };
enum PieceColor { NONE_COLOR, WHITE_PIECE, BLACK_PIECE };
struct ChessPiece {
    PieceType type;
    PieceColor color;

    ChessPiece(PieceType t = EMPTY, PieceColor c = NONE_COLOR){
        type = t;
        color = c;
    }
};
extern ChessPiece board[8][8];
extern ChessPiece selectedPiece;
extern bool pieceSelected;
extern Vector2 selectedPosition;