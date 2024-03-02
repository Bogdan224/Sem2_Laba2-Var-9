#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Binary_Tree
{
	int value;
	Binary_Tree* right;
	Binary_Tree* left;
};

//���������� �������� � ������
void Push(Binary_Tree** head, int value);
//�������� �������� �� ������
void Pop(Binary_Tree** head, int value);
//�������� �������� ������ �� �����������
void PrintVos(Binary_Tree* head);
//�������� �������� ������ �� ��������
void PrintUb(Binary_Tree* head);
//���������� ���-�� ��������� ������
int Size(Binary_Tree* head, int x = 0);

