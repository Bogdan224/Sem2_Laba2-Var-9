#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"
#include<stdio.h>
#include<locale.h>
#include<time.h>

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Binary_Tree* head = NULL;
	int size;
	printf("¬ведите кол-во элементов в дереве: ");
	scanf("%d", &size);
	int x;
	for (int i = 0; i < size; i++)
	{
		x = rand() % 100+1;
		Push(&head, x);
	}
	PrintVos(head);
	printf("\n¬ведите элемент в дереве, который нужно удалить: ");
	scanf("%d", &x);
	Pop(&head, x);
	PrintUb(head);
	printf("\nSize: %d", Size(head));
}