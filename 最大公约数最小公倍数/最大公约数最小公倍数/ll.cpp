//#include<stdio.h>
////���Լ��
//int gcd(int a, int b)
//{
//	return b==0?a:gcd(b,a%b);
//}
//
////��С������
//int lcm(int a, int b)
//{
//	return a*b/gcd(a,b);
//}
//
//int main()
//{
//	int a,b;
//	scanf_s("%d%d",&a,&b);
//	printf("%d %d\n",gcd(a,b),lcm(a,b));
//	return 0;
//}
//
//
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp =b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    printf("����������������");
    scanf_s("%d %d", &num1, &num2);
    printf("���Լ��Ϊ��%d\n", gcd(num1, num2));
    return 0;
}