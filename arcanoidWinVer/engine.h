#pragma once

#include <Windows.h>

enum EKeyType {
	EKTLeft,
	EKTRight,
	EKTSpace
};

void init(HWND hWnd);
void drawFrame(HDC hdc);

int onKeyDown(EKeyType keyType);