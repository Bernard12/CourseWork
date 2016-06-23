#include <stdio.h>
#include <stdlib.h>


#include "list.c"
//include "main.c"

int insert_help(int* l, int* max)
{
    for(int i=2;i<=l[0];i++)
    {
        if(l[i]<l[i-1])
        {
            int a=del(l,i, max);
            for(int j=i;j>0;j--)
            {
                if(j==1 || a>=l[j-1])
                {
                    insert(l,a,j,max);
                    break;
                }
            }
            return 1;
        }
    }
    return 0;
}

void insert_sort(int* list, int* max)
{
    int a=1;
    while(a)
    {
        a=insert_help(list, max);
    }
}
