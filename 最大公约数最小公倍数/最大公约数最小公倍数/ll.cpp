//#include<stdio.h>
////最大公约数
//int gcd(int a, int b)
//{
//	return b==0?a:gcd(b,a%b);
//}
//
////最小公倍数
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
    printf("请输入两个整数：");
    scanf_s("%d %d", &num1, &num2);
    printf("最大公约数为：%d\n", gcd(num1, num2));
    return 0;
}