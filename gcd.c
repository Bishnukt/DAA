#include<stdio.h>
#include<stdlib.h>
int gcd(int ,int );
int main()
{
	int a,b,res;
	printf("Enter two elements: ");
	scanf("%d%d",&a,&b);
	res=gcd(a,b);
	printf("GCD of %d and %d is %d.\n",a,b,res);
	return 0;
}
int gcd(int a,int b)
{
	if(a==0)
		return b;
		gcd(b%a,a);
}

