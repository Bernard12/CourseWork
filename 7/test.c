#include <stdio.h>

int func3(int *a)
{
	int z[20];
	z[2]=228;
	int b=z[*a];
	printf("%d\n",b);
}

int func2(int* a)
{
	(*a)++;
	func3(a);
}

int func(int* a)
{
	(*a)++;
	func2(a);
}

int main()
{
 	int a=5;
	int b=4;
	int *c=&a;
	int *d=&b;
	*c=*d;
	printf("%d \n",*c);
}





void print(pair* matr, int num,int n)
{int cnt=1;
    int col=n;
    int flag=1;
    for(int i=0;i<num;i++)
    {
        if(i==0 && matr[0].column==0 && matr[0].val==0)
        {
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<n;y++) printf("0 ");
                printf("\n");
            }
            break;
        }
        if(matr[i].column==0 && matr[i-1].column!=n )
        {
            for(int z=matr[i-1].column;z<n; z++)
            printf("0 ");
        }
        if(matr[i].column==0 && matr[i].val==0)
        {
            if(cnt!=n)
            {printf("\n");
                for(cnt;cnt<n;cnt++)
                {
                    for(int x=0;x<n;x++) printf("0 ");
                    printf("\n");
                }
            }
            if(flag)
            {
                for(int x=0;x<n;x++)
                {
                    for(int y=0;y<n;y++) printf("0 ");
                    printf("\n");
                    break;
                }
            }
            else break;
        }
        if(matr[i].column==0 && matr[i].val==cnt)
        {
            //if(col==n && matr[i].column==col-1) {{printf("0 ");}}
        if(matr[i].column!=0 && matr[i].val!=0) cnt++;
            col=1;
            printf("\n");
            continue;
        }
        if(matr[i].column==0 && matr[i].val!=cnt)
        {
            printf("\n");
            while(cnt!=matr[i].val)
            {
                for(int j=1;j<=n;j++) printf("0 ");
                flag=0;
                if(matr[i].column!=0 && matr[i].val!=0) cnt++;
                printf("\n");
            }
            col=1;
            continue;
        }
        if(matr[i].column!=0)
        {
            if(matr[i].column==col)
            {
                printf("%d ",matr[i].val);
                col++;
                flag=0;
                continue;
            }
            else
            {
                //for(col;col!=matr[i].column;col++) {printf("0!%d %d %d ",col,matr[i].column,matr[i].val); }

                printf("0 ");
                i--;
                //break;
                col++;
                flag=0;
                continue;
            }
        }

    }
