#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
    int column;
    int val;
}pair;

void re_size(pair* matr, int* max, int* num, int flag)
{
    if(flag)
    {
        matr=(pair*)realloc(matr, (*max+20)*sizeof(pair) );
        (*max)+=20;
    }
    else
    {
        matr=(pair*)realloc(matr, (*num)*sizeof(pair))
        (*max)=(*num);
    }
}

void input(pair* matr, int* max, int* num )
{
    int scan, flag=0, flag2=1;
    printf("This program calculate polynomial aX=bE\n");
    printf("Enter a and b:\n")
    int a,b;
    scanf("%d %d",&a,&b);
    if(a&&b)
    flag=1;
    printf("Enter size of matrix: \n");
    int n;
    scanf("%d",&n);

    matr[0].column=0;
    for(int i=1; i<=n;i++)
    {
        if(matr[(*num)-1].column!=0)
        {
            matr[*num].column=0;
            matr[*num].val=i;
            (*num)++;
            if( (*num)==(*max) ) re_size()
        }
        else
        {
            matr[(*num)-1].val=i;
        }

        for(int j=1;j<=n;j++)
        {
            scanf("%d",&scan);
            if(scan)
            {
                matr[*num].column=j;
                matr[*num].val=scan;
                (*num)++;
            }
        }
        if(i==n)
        {
            if(matr[(*num)-1].column!=0)
            {
                matr[*num].column=0;
                matr[*num].val=i;
                (*num)++;
                if( (*num)==(*max) ) re_size(matr,max,num,1)
            }
            else
            {
                matr[(*num)-1].column=0;
                matr[(*num)-1].val=i;
            }
        }
    }

}
