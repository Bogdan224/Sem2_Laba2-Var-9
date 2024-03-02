#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"
#include<stdio.h>
#include<locale.h>
#include<time.h>

//‘ункци€, выполн€юща€ 1-ое задание
void Func1() {
	Binary_Tree* head = NULL;
	int size;
	printf("¬ведите кол-во элементов в дереве: ");
	scanf("%d", &size);
	int x;
	while (Size(head) < size)
	{
		x = rand() % 100 + 1;
		Push(&head, x);
	}
	PrintVos(head);
	printf("\n¬ведите элемент в дереве, который нужно удалить: ");
	scanf("%d", &x);
	Pop(&head, x);
	PrintUb(head);

	Delete_All(&head);
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Func1();
}