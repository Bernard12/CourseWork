#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

int max=0;

int* create( int number, int random)
{

        float k1=1.05+(41/(2*number+1));
        int k=(int)(k1*number);

        int* z=(int*)malloc( k*sizeof(int) );

        z[0]=1;
        for(int i=1;z[0]<=number;z[0]++)
        {//printf("%d",l[0]);
            if(random) z[z[0]]=rand()%26;
            else {printf("Enter elem № %d:\n",z[0]);scanf("%d", &z[z[0]] );}
        }
        z[0]--;
        max=k;
        return z;

}

void re_size(int* l, int flag)
{
    if(flag)
    {
        float k1=1.05+(41/(2*max+1));
        int k=(int)(k1*max);
        l=(int*)realloc(l,k*sizeof(int));
        max=k;
    }
    else
    {
        if(2*l[0]<=max && max>50)
        max=(int)((max*2)/3);
        {
            l=(int*)realloc(l,max*sizeof(int));
        }
    }
}

void insert(int* l, int val, int pos)
{
    if( (l[0]+3)>=max) re_size(l,1);
    if(pos<1) pos=1;
    if(pos<=l[0])
    {
        int i=l[0]+1;
        for( i=l[0]+1;i>pos;i--)
        {
            l[i]=l[i-1];

        }
        l[i]=val;
    }

    else
    {
        if(pos>l[0] ) l[l[0]+1]=val;
    }
    l[0]++;
}

int del(int*l, int pos)
{
    if(l[0]==0) return (INT_MIN);
    if(l[0]==pos) {l[0]--;re_size(l,0);return l[l[0]+1];}
    if(pos<1) pos=1;
    int res=l[pos];
    for(int i=pos;i<=l[0];i++) l[i]=l[i+1];
    l[0]--; re_size(l,0);
    return res;

}

void print(int* list)
{
    printf("\n");
    if(list[0])
    {
        for(int i=1;i<=list[0];i++)
        {//printf("!%d!",i);
            if((i%10)==1)
            {
                printf("\n\t\t");
            }
            printf(" %d  ",list[i]);
            if(i!=list[0]) printf("<-> ");
        }
    }
    else(printf("List is empty.\n"));
    printf("\n");
}
void menu()
{
    printf("____________________Menu____________________\n");
    printf("1.    Create & fill                  \n");
    printf("2.    Add new elements                      \n");
    printf("3.    Remove element by number              \n");
    printf("4.    Print list                            \n");
    printf("5.    Sort                                  \n");
    printf("6.    Clear the list (capacity will be 10)  \n");
    printf("7.__________________Quit____________________\n");

}
