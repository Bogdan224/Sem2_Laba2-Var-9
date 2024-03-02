#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"
#include"Binary_Tree_TV.h"
#include<stdio.h>
#include<locale.h>
#include<time.h>

//Функция, выполняющая 1-ое задание
void Func1() {
	Binary_Tree* head = NULL;
	int size;
	printf("Введите кол-во элементов в дереве: ");
	scanf("%d", &size);
	int x;
	while (Size(head) < size)
	{
		x = rand() % 100 + 1;
		Push(&head, x);
	}
	PrintVos(head);
	printf("\nВведите элемент в дереве, который нужно удалить: ");
	scanf("%d", &x);
	Pop(&head, x);
	PrintUb(head);

	Delete_All(&head);
	printf("\n");
}
//Функция, выполняющая 2-ое задание
void Func2() {
	Binary_Tree_TV* head = NULL;
	int size;
	printf("Введите кол-во элементов в дереве: ");
	scanf("%d", &size);
	char model[20];
	int displaySize;
	int wifi;
	while (Size(head) < size)
	{
		printf("Введите модель телевизора: ");
		scanf("%s", &model);
		printf("Введите размер дисплея телевизора: ");
		scanf("%d", &displaySize);
		printf("Есть ли в телевизоре WIFI(1-Да, 0-Нет): ");
		scanf("%d", &wifi);
		if (wifi != 0) 
			wifi = true;
		Push(&head, Init(model, displaySize, wifi));
		system("cls");
	}
	PrintVos(head);
	printf("\nВведите элемент в дереве, который нужно удалить\n");
	printf("Введите модель телевизора: ");
	scanf("%s", &model);
	printf("Введите размер дисплея телевизора: ");
	scanf("%d", &displaySize);
	printf("Есть ли в телевизоре WIFI(1-Да, 0-Нет): ");
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