#include <stdio.h>
#include <stdlib.h>

#include "7.h"



int main()
{
    pair* matr=(pair*)malloc(20*sizeof(int));
    int max=20;
    int num=0;
    printf("This program calculate polynomial aX+bE\n");
    printf("Enter a and b:\n");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Enter size of matrix: \n");
    int n;
    scanf("%d",&n);
    int flag=0;
    input(matr,&max,&num,a,b,n,&flag);
    /*for(int i=0;i<num;i++)
    {
        if(matr[i].column==0)
        {
            printf("\n%d %d\n",matr[i].column,matr[i].val);
        }
        else
        {
            printf("%d %d ||",matr[i].column,matr[i].val);
        }
    }*/
    if(b) print1(matr,num,n);
    else print2(matr,num,n);
}
