#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int max=0;

void create(int* l, int number, int random)
{
        float k1=1.05+(41/(2*number+1));
        int k=(int)(k1*number);
        l=(int*)malloc( k*sizeof(int) );
        l[0]=1;
        for(l[0];l[0]<=number;l[0]++)
        {
            if(random) l[l[0]]=rand()%26;
            else {printf("Enter elem № %d:\n",l[0]);scanf("%d", l[l[0]] );}
        }
        max=k;
}

void resize(int* l, int flag)
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
    if( (l[0]+1)>=max) resize(l,1)
    if(pos<1) pos=1;
    if(pos<=l[0])
    {
        int i=l[0]+1;
        for(i;i>pos;i--)
        {
            l[i]=l[i-1];
        }
        l[i]=val;
    }
    else
    {
        if(pos>l[0] ) l[l[0]]=val;
    }
    l[0]++;
}

int delete(int*l, int pos)
{
    if(l[0]==pos) {l[0]--;resize(l,0);return l[l[0]+1];}
    if(pos<1) pos=1
    int res=l[pos];
    for(int i=pos;i<l[0];i++) l[i]=l[i+1];
    l[0]--; resize(l,0);
    return res;

}

void print(int* l)
{
    for(int i=0;i<=l[0];i++)
    {
        if(!(i%10))
        {
            printf("\n\t\t\t");
        }
        printf("%d  <->  ",l[i]);
    }
}
