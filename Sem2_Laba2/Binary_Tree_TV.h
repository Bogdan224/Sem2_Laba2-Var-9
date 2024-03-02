#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "TV.h"

struct Binary_Tree_TV
{
	TV* tv;
	Binary_Tree_TV* right;
	Binary_Tree_TV* left;
};

//Добавление элемента в дерево
void Push(Binary_Tree_TV** head, TV* tv);
//Удаление элемента из дерева
void Pop(Binary_Tree_TV** head, TV* tv);
//Печатает элементы дерева по возрастанию размера дисплея
void PrintVos(Binary_Tree_TV* head);
//Печатает элементы дерева по убыванию размера дисплея
void PrintUb(Binary_Tree_TV* head);
//Возвращает кол-во элементов дерева
int Size(Binary_Tree_TV* head);
void Delete_All(Binary_Tree_TV** head);


