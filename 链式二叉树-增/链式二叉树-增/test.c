#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//创建树的结构体
typedef struct Tree
{
	struct Tree* left;
	struct Tree* right;
	int val;
}Tree;

#include"Q.h"

//创建树的函数
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
//前序遍历
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

//中序遍历
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

//后序遍历
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

//树的节点个数
int Treesize(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + Treesize(root->left) + Treesize(root->right);
}

//树的叶子节点个数
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


//求第k层节点个数
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

//销毁 后序
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
//查找
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
//层数
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
//层序遍历
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
//完全二叉树
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
			printf("不是完全二叉树");
			QueueDestroy(&q);
			return;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		}
	}
	printf("是完全二叉树");
	QueueDestroy(&q);
}



int main()
{
	//创建树
	Tree* root1 = createTree(1);
	Tree* root2 = createTree(2);
	Tree* root3 = createTree(3);
	Tree* root4 = createTree(4);
	Tree* root5 = createTree(5);
	Tree* root6 = createTree(6);

	//连接树
	root1->left = root2;
	root1->right = root4;
	root2->left = root3;
	root4->right = root6;
	root4->left = root5;

	//遍历树
	printf("前序：");
	prevOrder(root1);
	printf("\n");
	printf("中序：");
	InOrder(root1);
	printf("\n");
	printf("后序：");
	postOrder(root1);
	printf("\n");
	printf("树节点：%d\n", Treesize(root1));
	printf("叶子节点：%d\n", TreeLeafSize(root1));
	printf("第k层，节点：%d\n", TreeKLevel(root1, 2));
	Tree* find=Find(root1, 3);
	printf("%d", find->val);
	printf("\n");
	LevelOrder(root1);
	printf("层数为：%d", TreeLevel(root1));
	printf("\n");
	FullTree(root1);
	return 0;
}