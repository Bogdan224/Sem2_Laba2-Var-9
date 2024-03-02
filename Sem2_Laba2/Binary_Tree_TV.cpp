#include "Binary_Tree_TV.h"

void Push(Binary_Tree_TV** head, TV* tv) {
	//���� ���������� ��������� ������, ������� ����� �������
	if ((*head) == NULL) {
		(*head) = (Binary_Tree_TV*)malloc(sizeof(Binary_Tree_TV));
		(*head)->tv = tv;
		(*head)->left = (*head)->right = NULL;
		return;
	}
	//���� ���������� �������� ������ �������� � ������, ��������� � ����� ���������
	else if (Less(tv, (*head)->tv))
		Push(&(*head)->left, tv);
	//���� ���������� �������� ������ �������� � ������, ��������� � ������ ���������
	else if (!Equals(tv, (*head)->tv))
		Push(&(*head)->right, tv);
	//���� �������� �����, �� �� ��������� ��� � ������
}
void Pop(Binary_Tree_TV** head, TV* tv) {
	if (*head == NULL) return; // ������ ������
	if (Equals((*head)->tv, tv)) // ����� �������
	{
		// ������� �������� ������
		if (((*head)->left == NULL) && ((*head)->right == NULL))
		{
			free((*head)->tv);
			free(*head);
			*head = NULL;
			return;
		}
		Binary_Tree_TV* tmp;
		// ���� ������ ������ ���������
		if ((*head)->left == NULL)
		{
			tmp = *head;
			*head = (*head)->right;
			free(tmp->tv);
			free(tmp);
			return;
		}
		//���� ������ ����� ��������� 
		if ((*head)->right == NULL)
		{
			tmp = *head;
			*head = (*head)->left;
			free(tmp->tv);
			free(tmp);
			return;
		}
		Binary_Tree_TV* pred = *head;
		tmp = (*head)->left; // ���� � ����� ��������� ������� ������ �������
		while (tmp->right != NULL)
		{
			pred = tmp;
			tmp = tmp->right;
		}
		(*head)->tv = tmp->tv; // �������� �������� �� ��������� �������
		if (pred != (*head)) // ��������� � ��������� ������� �� ���������
		{
			if (tmp->left != NULL) pred->right = tmp->left;
			else pred->right = NULL;
		}
		else (*head)->left = tmp->left;
		free(tmp->tv);
		free(tmp);
		return;
	}
	// ������������ ������ ������
	if (Less(tv, (*head)->tv))
		return Pop(&(*head)->left, tv);
	return Pop(&(*head)->right, tv);
}
void PrintVos(Binary_Tree_TV* head) {
	if (head == NULL)
		return;
	//�������� �� ����� �����
	PrintVos(head->left);
	//������� �������� �������� ��������
	PrintTV(head->tv);
	//�������� �� ������ �����
	PrintVos(head->right);
}
void PrintUb(Binary_Tree_TV* head) {
	if (head == NULL)
		return;
	//�������� �� ������ �����
	PrintUb(head->right);
	//������� �������� �������� ��������
	PrintTV(head->tv);
	//�������� �� ����� �����
	PrintUb(head->left);
}
int Size(Binary_Tree_TV* head) {
	if (head == NULL)
		return 0;
	int N_r = 0, N_l = 0;
	//�������� �� ������ �����
	if (head->left != NULL) {
		N_l = Size(head->left);
	}
	//�������� �� ����� �����
	if (head->right != NULL) {
		N_r = Size(head->right);
	}
	//���������� ����� ���-�� ��������� ������ �����, ����� ����� � ������� 
	return N_r + N_l + 1;
}
void Delete_All(Binary_Tree_TV** head) {
	if (*head == NULL)
		return;
	//������� ��� �� ����� �����
	Delete_All(&(*head)->right);
	//������� ��� �� ������ �����
	Delete_All(&(*head)->left);
	//������� �������� � ����� ������������ � NULL
	free(*head);
	*head = NULL;
}