#include<stdio.h>
#include<string.h>
#include<windows.h>
//struct game//创造结构体 包含运动员的名字、编号和成绩
//{
//	char name[20];
//	int score;
//	int num;
//};
//int main()
//{
//struct game s = { "张三",34,1};//输入一个结构体信息
//	printf("%s,%d,%d", s. name, s.score, s. num);//.左边是结构体命名、右边是结构体内的命名
//
//}
//
//int main()
//{
//	int a;
//	int* pa = &a;
//	*pa = 30;
//	return 0;
//}


//int main()//看
//{
//	int arr[10] = { 0 };
//	char* pc = arr;//加二   字符型不一样
//	int* p = arr;//加八
//	printf("%p\n", p);
//	printf("%p\n", p + 1);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	return 0;
//}
 
 
//char 一次读取一个字节*p=arr arr为数组；
//int 读取全部


//野指针 指针指向的位置是不可知的 随机的 不正确的 没有限制的
//int main()
//{
//	int* p;//p是一个局部变量指针 局部变量不初始化 默认是随机值
//	*p //非法访问
//		= 20;
//	//p就是野指针 没有 &a；
//	return 0;
//}
//2.非法访问 读取到了不属于我的位置
//3.已经还了 还要访问

//int *p=arr //将指针对应到 arr数组的第一个位置

//int main()
//{
//	int a = (int)3.14;
//	printf("%d", a);
//	return 0;//（int)强制转换类型；
//}