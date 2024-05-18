#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//�������Ľṹ��
typedef struct Tree
{
	struct Tree* left;
	struct Tree* right;
	int val;
}Tree;

#include"Q.h"

//�������ĺ���
Tree* createTree(int x)
{
	Tree* root = (Tree*)malloc(sizeof(Tree));
	if (root == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	root->val = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}
//ǰ�����
void prevOrder(Tree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	prevOrder(root->left);
	prevOrder(root->right);
}

//�������
void InOrder(Tree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

//�������
void postOrder(Tree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->val);
}

//���Ľڵ����
int Treesize(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + Treesize(root->left) + Treesize(root->right);
}

//����Ҷ�ӽڵ����
int TreeLeafSize(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);

}


//���k��ڵ����
int TreeKLevel(Tree* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);

}

//���� ����
void TreeDestory(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}
//����
Tree* Find(Tree* root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	Tree* ret = NULL;
	ret = Find(root->left, x);
	if (ret)
	{
		return ret;
	}
	ret = Find(root->right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
//����
int TreeLevel(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int Lheight = TreeLevel(root->left);
	int Rheight = TreeLevel(root->right);
	return Lheight > Rheight ? Lheight + 1 : Rheight + 1;
}
//�������
void LevelOrder(Tree* root)
{
	Que q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		Tree* front = QueueFront(&q);
		printf("%d ", front->val);
		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);

		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}
//��ȫ������
void FullTree(Tree* root)
{
	Que q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}
	bool full = false;
	while (!QueueEmpty(&q))
	{
		Tree* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			full = true;
		}
		else 
		{
		if (full)
		{
			printf("������ȫ������");
			QueueDestroy(&q);
			return;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		}
	}
	printf("����ȫ������");
	QueueDestroy(&q);
}



int main()
{
	//������
	Tree* root1 = createTree(1);
	Tree* root2 = createTree(2);
	Tree* root3 = createTree(3);
	Tree* root4 = createTree(4);
	Tree* root5 = createTree(5);
	Tree* root6 = createTree(6);

	//������
	root1->left = root2;
	root1->right = root4;
	root2->left = root3;
	root4->right = root6;
	root4->left = root5;

	//������
	printf("ǰ��");
	prevOrder(root1);
	printf("\n");
	printf("����");
	InOrder(root1);
	printf("\n");
	printf("����");
	postOrder(root1);
	printf("\n");
	printf("���ڵ㣺%d\n", Treesize(root1));
	printf("Ҷ�ӽڵ㣺%d\n", TreeLeafSize(root1));
	printf("��k�㣬�ڵ㣺%d\n", TreeKLevel(root1, 2));
	Tree* find=Find(root1, 3);
	printf("%d", find->val);
	printf("\n");
	LevelOrder(root1);
	printf("����Ϊ��%d", TreeLevel(root1));
	printf("\n");
	FullTree(root1);
	return 0;
}