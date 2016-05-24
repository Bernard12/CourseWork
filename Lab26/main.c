#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "list.c"

int main()
{
    int* list;
    char act[3];
    while(1)
    {
        menu();
        printf("\nChoose point:  ");
        scanf("%s",act);
        if(act[0]=='1')
        {
            int n;
            char x[3];
            printf("How much elements do you need?\n");
            scanf("%d",&n);
            printf("Fill it automaticaly?[Y/n]\n");
            scanf("%s",x);
            if(x[0]=='y' || x[0]=='Y')
            {
                create(n,1);
            }
            else list=create(n,0);
            printf("\n%d\n",list[0]);
            printf("ok");
        }



        if(act[0]=='4')
        {
            print(list);
        }
    }
}
