#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Binary_Tree
{
	int value;
	Binary_Tree* right;
	Binary_Tree* left;
};

//Добавление элемента в дерево
void Push(Binary_Tree** head, int value);
//Удаление элемента из дерева
void Pop(Binary_Tree** head, int value);
//Печатает элементы дерева по возрастанию
void PrintVos(Binary_Tree* head);
//Печатает элементы дерева по убыванию
void PrintUb(Binary_Tree* head);
//Возвращает кол-во элементов дерева
int Size(Binary_Tree* head, int x = 0);

