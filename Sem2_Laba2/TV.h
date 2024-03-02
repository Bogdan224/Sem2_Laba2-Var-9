#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TV
{
	char _model[20];
	int _displaySize;
	bool _haveWIFI;
};

//Инициализирует поля структуры
TV* Init(const char model[20], int displaySize, bool haveWIFI);
//Выводит все элементы tv в консоли
void PrintTV(TV* tv);
//Сравнивает tv1 и tv2
bool Equals(TV* tv1, TV* tv2);
//Находит меньшее мз значений полей _displaySize у tv1 и tv2
bool Less(TV* tv1, TV* tv2);
