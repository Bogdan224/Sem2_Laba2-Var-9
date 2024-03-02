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

//���������� �������� � ������
void Push(Binary_Tree_TV** head, TV* tv);
//�������� �������� �� ������
void Pop(Binary_Tree_TV** head, TV* tv);
//�������� �������� ������ �� ����������� ������� �������
void PrintVos(Binary_Tree_TV* head);
//�������� �������� ������ �� �������� ������� �������
void PrintUb(Binary_Tree_TV* head);
//���������� ���-�� ��������� ������
int Size(Binary_Tree_TV* head);
void Delete_All(Binary_Tree_TV** head);


