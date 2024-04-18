#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	void swap(char* a, char* b);
		char s1[50], s2[50],s3[50];
		printf("输入三个字符串：\n");
		gets_s(s1);
		gets_s(s2);
		gets_s(s3);
		if (strcmp(s1, s2) > 0)
			swap(s1, s2);
		if (strcmp(s2, s3) > 0)
			swap(s2, s3);
		if (strcmp(s1, s3) > 0)
			swap(s1, s3);
		printf("由大到小是：\n");
		printf("%s\n%s\n%s\n", s1, s2, s3);
		return 0;
}
void swap(char* a, char* b)
{
	char s[50];
	strcpy(s, a);
	strcpy(s, b);
	strcpy(a, b);
}