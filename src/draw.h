#pragma once
#include"globals.h"

void InitBoard();
void DrawChessboard(int startX, int startY, int squareSize);
void DrawPiece(ChessPiece piece, int x, int y, int squareSize);
void DrawBoard();
void DrawSelectedPiece();