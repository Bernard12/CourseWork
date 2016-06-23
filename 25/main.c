#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
//include "list.c"
#include "sor.c"



int main()
{srand(time(NULL));
	int max=0;
    int *list; int a=1;
    list=(int*)malloc( 44 );
    list[0]=0; max=10;
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
                list=create( n,1, max);
            }
            else list=create(n,0,max);
            printf("\nPrint list?[Y/n]\n");
            scanf("%s",x);

            if(x[0]=='Y' || x[0]=='y')
            {
                printf("\n");
                print(list);
            }
        }

        if(act[0]=='2')
        {
            /*if(a)
            {
                printf("You didn't create list, create it firstly.\n");
                continue;
            }*/
            int n;
            printf("How much elements do you want to add?\n");
            scanf("%d",&n);
            printf("Make values random?[Y/n]\n");
            char x[3]; int flag;
            scanf("%s",x);
            if(x[0]=='Y' || x[0]=='y') flag=1;
            else flag=0;
            for(int i=0;i<n;i++)
            {
                int val;
                printf("Choose position:  ");
                int p;
                scanf("%d",&p);
                if(flag) val=rand()%25;
                else {printf("Enter value: "); scanf("%d",&val);}
                insert(list,val,p,max);
                printf("\nPrint list?[Y/n]\n");
                scanf("%s",x);

                if(x[0]=='Y' || x[0]=='y')
                {
                    printf("\n");
                    print(list);
                }
            }
        }

        if(act[0]=='3')
        {
            int res;
            char x[3];
            printf("Enter position to delete:  ");
            scanf("%d",&res);
            res=del(list,res,max);
            printf("\nPrint list?[Y/n]\n");
            scanf("%s",x);
            if(x[0]=='Y' || x[0]=='y')
            {
                printf("\n");
                print(list);
            }
        }

        if(act[0]=='4')
        {
            print(list);
        }

        if(act[0]=='5')
        {
            insert_sort(list,max);
            printf("\nPrint list?[Y/n]\n");
            char x[3];
            scanf("%s",x);
            if(x[0]=='Y' || x[0]=='y')
            {
                printf("\n");
                print(list);
            }
        }

        if(act[0]=='6')
        {
            list=(int*)realloc(list,44);
            list[0]=0;
        }

        if(act[0]=='7') {printf("\nBye!\n");return 0;}
        a=0;
    }
}
