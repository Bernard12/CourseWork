#include <stdio.h>
#include <stdlib.h>

#include "7.h"



int main()
{
    pair* matr=(pair*)malloc(40*sizeof(int));
    int max=40;
    int num=0;
    printf("This program calculate polynomial aX+bE\n");
    printf("Enter a and b:\n");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Enter size of matrix: \n");
    int n;
    scanf("%d",&n);
	printf("Enter matrix:\n");
    int flag=0;
    input(matr,&max,&num,a,b,n,&flag);
	printf("Vector before calculation\n");
    for(int i=0;i<num;i++)
    {
        if(matr[i].column==0)
        {
            printf("\n%d %d\n",matr[i].column,matr[i].val);
        }
        else
        {
            printf("%d %d ",matr[i].column,matr[i].val);
			if(matr[i+1].column!=0) {printf("|| ");}
        }
    }
int str=1;
    for(int i=0; i<num;i++)//вычисление матрочлена
    {

        if(matr[i].column==0)
        {
            str=matr[i].val;
            continue;
        }
        if(str==matr[i].column)
        {
            matr[i].val=(matr[i].val*a)+b;
        }
        if(str!=matr[i].column)
        {
            matr[i].val*=a;
        }
    }
    for(int i=0;i<num;i++)//сборка мусора
    {
        if(matr[i].column!=0 && matr[i].val==0)
        {
            for(int j=i;j<(num-1);j++)
            {
                matr[j]=matr[j+1];
            }
            num--;
        }
    }
    for(int i=0;i<num-1;i++)// сборка мусора
    {
        if(matr[i].column==0 && matr[i+1].column==0)
        {
            for(int j=i;j<(num-1);j++)
            {
                matr[j]=matr[j+1];
            }
            num--;
        }
    }
    printf("\n\n");
	printf("Vector after calculation\n");
    for(int i=0;i<num;i++)
    {
        if(matr[i].column==0)
        {
            printf("\n%d %d\n",matr[i].column,matr[i].val);
        }
        else
        {
            printf("%d %d ",matr[i].column,matr[i].val);
			if(matr[i+1].column!=0) {printf("|| ");}
        }
    }
	printf("Result:\n");
    if(b) print1(matr,num,n);
    else print2(matr,num,n);
}
