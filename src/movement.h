#pragma once
#include"globals.h"

void HandleInput();
bool IsValidMove(ChessPiece piece, Vector2 startPos, Vector2 endPos);
bool IsValidPawnMove(ChessPiece piece, Vector2 startPos, Vector2 endPos);