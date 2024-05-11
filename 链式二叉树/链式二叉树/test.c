#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//�������Ľṹ��
typedef struct Tree
{
	struct Tree *left;
	struct Tree *right;
	int val;
}Tree;

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
int TreeKLevel(Tree* root,int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k==1)
	{
		return 1;
	}
	return TreeKLevel(root->left,k-1) + TreeKLevel(root->right,k-1);

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
	root1->left= root2;
	root1->right = root4;
	root2->left = root3;
	root4->right = root6;
	root4->left = root5;

	//������
	prevOrder(root1);
	printf("\n");
	InOrder(root1);
	printf("\n");
	postOrder(root1);
	printf("\n");
	printf("%d\n",Treesize(root1));
	printf("%d\n", TreeLeafSize(root1));
	printf("%d\n", TreeKLevel(root1, 2));
	return 0;
}