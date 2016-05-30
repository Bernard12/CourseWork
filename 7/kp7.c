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
        matr=(pair*)realloc(matr, (*num)*sizeof(pair));
        //int m=*num;
        *max=*num;
    }
}

void input(pair* matr, int* max, int* num, int a, int b,int n,int* flag)
{
    int scan, flag2=1;



    matr[0].column=0;
    matr[0].val=1;
    (*num)++;
    for(int i=1; i<=n;i++)
    {
        if(i!=1){
        if(matr[(*num)-1].column!=0)
        {
            matr[*num].column=0;
            matr[*num].val=i;
            (*num)++;
            if( (*num)==(*max) ) re_size(matr,max,num,1);
        }
        else
        {
             matr[(*num)-1].val=i;
        }
        }
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&scan);
                if(scan)
                {
                    matr[*num].column=j;
                    matr[*num].val=scan*a;
                    (*num)++;
                    if( (*num)==(*max) ) re_size(matr,max,num,1);
                    continue;
                    *flag=1;
                }
                if(b && i==j)
                {scan*=a;
                    scan+=b;
                    printf("%d",scan);
                    matr[*num].column=j;
                    matr[*num].val=scan;
                    (*num)++;
                    if( (*num)==(*max) ) re_size(matr,max,num,1);
                    continue;
                }
            }
        if(i==n)
        {
            if(matr[(*num)-1].column!=0)
            {
                matr[*num].column=0;
                matr[*num].val=0;
                (*num)++;
                if( (*num)==(*max) ) re_size(matr,max,num,1);
            }
            else
            {
                matr[(*num)-1].column=0;
                matr[(*num)-1].val=0;
            }
        }
    }
    if( (*num)!=(*max) ) re_size(matr,max,num,0);
}

void print1(pair* matr, int num,int n)
{
    int cnt=1;
    int col=n+1;
    for(int i=0;i<num;i++)
    {

        if(matr[i].column==0)
        {
            if(col<=n) {for(int i=0;i<=(n-col);i++) printf("0 ");}
            col=1;
            printf("\n");
            continue;
        }
        else
        {
            if(col==matr[i].column)
            {
                printf("%d ",matr[i].val);
                col++;
                continue;
            }
            else
            {
                for(col; col<matr[i].column;col++) {printf("0 ");}

                printf("%d ",matr[i].val);
                col++;
                continue;
            }
        }
    }
}

void print2(pair* matr,int num, int n)
{
    int cnt=1;
    int col=n+1;
    for(int i=0;i<num;i++)
    {
        if(matr[i].column==0)
        {
            if(col<=n) {for(int i=0;i<=(n-col);i++) printf("0 ");}
            printf("\n");
            col=1;
            if(matr[i].val!=0)cnt++;
            if(matr[i].val==0 && cnt<=n)
            {//printf("\n");
                while(cnt<=n)
                {
                    for(int z=0;z<n;z++) printf("0 ");
                    printf("\n");
                    cnt++;
                }

            }


            if(cnt<=matr[i].val)
            {
                while(cnt<=matr[i].val)
                {
                    for(int x=0;x<n;x++) printf("0 ");
                    printf("\n");
                    cnt++;
                }
            }
            continue;
        }
        else
        {
            if(col==matr[i].column)
            {
                printf("%d ",matr[i].val);
                col++;
                continue;
            }
            else
            {
                for(col; col<matr[i].column;col++) {printf("0 ");}

                printf("%d ",matr[i].val);
                col++;
                continue;
            }
        }
    }
}


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
    for(int i=0;i<num;i++)
    {
        if(matr[i].column==0)
        {
            printf("\n%d %d\n",matr[i].column,matr[i].val);
        }
        else
        {
            printf("%d %d ||",matr[i].column,matr[i].val);
        }
    }
    if(b) print1(matr,num,n);
    else print2(matr,num,n);
}

