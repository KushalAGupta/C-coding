#include<stdio.h>
long int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return n * fact(n-1);
}
int main()
{
    int n;
    long int f;
    printf("Enter the number whose factorial you want : ");
    scanf("%d",&n);
    f = fact(n);
    printf("The factorial of %d is %ld",n,f);
    return 0;
}