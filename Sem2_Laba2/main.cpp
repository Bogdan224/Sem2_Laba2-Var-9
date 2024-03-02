#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"
#include"Binary_Tree_TV.h"
#include<stdio.h>
#include<locale.h>
#include<time.h>

//�������, ����������� 1-�� �������
void Func1() {
	Binary_Tree* head = NULL;
	int size;
	printf("������� ���-�� ��������� � ������: ");
	scanf("%d", &size);
	int x;
	while (Size(head) < size)
	{
		x = rand() % 100 + 1;
		Push(&head, x);
	}
	PrintVos(head);
	printf("\n������� ������� � ������, ������� ����� �������: ");
	scanf("%d", &x);
	Pop(&head, x);
	PrintUb(head);

	Delete_All(&head);
	printf("\n");
}
//�������, ����������� 2-�� �������
void Func2() {
	Binary_Tree_TV* head = NULL;
	int size;
	printf("������� ���-�� ��������� � ������: ");
	scanf("%d", &size);
	char model[20];
	int displaySize;
	int wifi;
	while (Size(head) < size)
	{
		printf("������� ������ ����������: ");
		scanf("%s", &model);
		printf("������� ������ ������� ����������: ");
		scanf("%d", &displaySize);
		printf("���� �� � ���������� WIFI(1-��, 0-���): ");
		scanf("%d", &wifi);
		if (wifi != 0) 
			wifi = true;
		Push(&head, Init(model, displaySize, wifi));
		system("cls");
	}
	PrintVos(head);
	printf("\n������� ������� � ������, ������� ����� �������\n");
	printf("������� ������ ����������: ");
	scanf("%s", &model);
	printf("������� ������ ������� ����������: ");
	scanf("%d", &displaySize);
	printf("���� �� � ���������� WIFI(1-��, 0-���): ");
	scanf("%d", &wifi);
	if (wifi != 0) 
		wifi = true;
	TV* tv = Init(model, displaySize, wifi);
	Pop(&head, tv);
	free(tv);
	PrintUb(head);

	Delete_All(&head);
	printf("\n");
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Func1();
	system("pause");
	system("cls");
	Func2();
}