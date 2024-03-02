#include "Binary_Tree_TV.h"

void Push(Binary_Tree_TV** head, TV* tv) {
	//Если переданное поддерево пустое, создаем новый элемент
	if ((*head) == NULL) {
		(*head) = (Binary_Tree_TV*)malloc(sizeof(Binary_Tree_TV));
		(*head)->tv = tv;
		(*head)->left = (*head)->right = NULL;
		return;
	}
	//Если переданное значение меньше значения в дереве, переходим в левое поддерево
	else if (Less(tv, (*head)->tv))
		Push(&(*head)->left, tv);
	//Если переданное значение больше значения в дереве, переходим в правое поддерево
	else if (!Equals(tv, (*head)->tv))
		Push(&(*head)->right, tv);
	//Если значения равны, то не добавляем его в дерево
}
void Pop(Binary_Tree_TV** head, TV* tv) {
	if (*head == NULL) return; // пустое дерево
	if (Equals((*head)->tv, tv)) // нашли вершину
	{
		// вершина является листом
		if (((*head)->left == NULL) && ((*head)->right == NULL))
		{
			free((*head)->tv);
			free(*head);
			*head = NULL;
			return;
		}
		Binary_Tree_TV* tmp;
		// есть только правое поддерево
		if ((*head)->left == NULL)
		{
			tmp = *head;
			*head = (*head)->right;
			free(tmp->tv);
			free(tmp);
			return;
		}
		//Есть только левое поддерево 
		if ((*head)->right == NULL)
		{
			tmp = *head;
			*head = (*head)->left;
			free(tmp->tv);
			free(tmp);
			return;
		}
		Binary_Tree_TV* pred = *head;
		tmp = (*head)->left; // ищем в левом поддереве крайнюю правую вершину
		while (tmp->right != NULL)
		{
			pred = tmp;
			tmp = tmp->right;
		}
		(*head)->tv = tmp->tv; // копируем значение из найденной вершины
		if (pred != (*head)) // удаляемая и найденная вершины не совпадают
		{
			if (tmp->left != NULL) pred->right = tmp->left;
			else pred->right = NULL;
		}
		else (*head)->left = tmp->left;
		free(tmp->tv);
		free(tmp);
		return;
	}
	// декомпозиция общего случая
	if (Less(tv, (*head)->tv))
		return Pop(&(*head)->left, tv);
	return Pop(&(*head)->right, tv);
}
void PrintVos(Binary_Tree_TV* head) {
	if (head == NULL)
		return;
	//Проходим по левой ветке
	PrintVos(head->left);
	//Выводим значение текущего элемента
	PrintTV(head->tv);
	//Проходим по правой ветке
	PrintVos(head->right);
}
void PrintUb(Binary_Tree_TV* head) {
	if (head == NULL)
		return;
	//Проходим по правой ветке
	PrintUb(head->right);
	//Выводим значение текущего элемента
	PrintTV(head->tv);
	//Проходим по левой ветке
	PrintUb(head->left);
}
int Size(Binary_Tree_TV* head) {
	if (head == NULL)
		return 0;
	int N_r = 0, N_l = 0;
	//Проходим по правой ветке
	if (head->left != NULL) {
		N_l = Size(head->left);
	}
	//Проходим по левой ветке
	if (head->right != NULL) {
		N_r = Size(head->right);
	}
	//Возвращаем сумму кол-ва элементов правой ветки, левой ветки и вершины 
	return N_r + N_l + 1;
}
void Delete_All(Binary_Tree_TV** head) {
	if (*head == NULL)
		return;
	//Удаляем все из левой ветки
	Delete_All(&(*head)->right);
	//Удаляем все из правой ветки
	Delete_All(&(*head)->left);
	//Удаляем верхушку и затем приравниваем к NULL
	free(*head);
	*head = NULL;
}