#include "Binary_Tree.h"

void Push(Binary_Tree** head, int value) {
	if ((*head) == NULL) {
		(*head) = (Binary_Tree*)malloc(sizeof(Binary_Tree));
		(*head)->value = value;
		(*head)->left = (*head)->right = NULL;
		return;
	}
	else if(value < (*head)->value)
		Push(&(*head)->left, value);
	else if (value > (*head)->value)
		Push(&(*head)->right, value);
}
void Pop(Binary_Tree** head, int value) {
	if (*head == NULL) return; // ������ ������
	if ((*head)->value == value) // ����� �������
	{
		// ������� �������� ������
		if (((*head)->left == NULL) && ((*head)->right == NULL))
		{
			free(*head);
			*head = NULL;
			return;
		}
		Binary_Tree* tmp;
		// ���� ������ ������ ���������
		if ((*head)->left == NULL)
		{
			tmp = *head;
			*head = (*head)->right;
			free(tmp);
			return;
		}
		//���� ������ ����� ��������� 
		if ((*head)->right == NULL)
		{
			tmp = *head;
			*head = (*head)->left;
			free(tmp);
			return;
		}
		Binary_Tree* pred = *head; // ���� ��� �������
		tmp = (*head)->left; // ���� � ����� ��������� ������� ������ �������
		while (tmp->right != NULL)
		{
			pred = tmp;
			tmp = tmp->right;
		}
		(*head)->value = tmp->value; // �������� �������� �� ��������� �������
		if (pred != (*head)) // ��������� � ��������� ������� �� ���������
		{
			if (tmp->left != NULL) pred->right = tmp->left;
			else pred->right = NULL;
		}
		else (*head)->left = tmp->left;
		free(tmp);
		return;
	}
	// ������������ ������ ������
	if ((*head)->value < value) 
		return Pop(&(*head)->right, value);
	return Pop(&(*head)->left, value);
}
void PrintVos(Binary_Tree* head) {
	if (head == NULL)
		return;
	PrintVos(head->left);
	printf("%d ", head->value);
	PrintVos(head->right);
	
}
void PrintUb(Binary_Tree* head) {
	if (head == NULL)
		return;
	PrintUb(head->right);
	printf("%d ", head->value);
	PrintUb(head->left);
}
int Size(Binary_Tree* head, int x) {
	if (head == NULL)
		return x;
	Size(head->right, x++);
	x++;
	Size(head->left, x++);
}
