#pragma once

#include <Windows.h>

enum EKeyType {
	EKTLeft,
	EKTRight,
	EKTSpace
};

void init();
void drawFrame(HDC hdc);

int onKeyDown(EKeyTab keyType);