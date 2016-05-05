#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab23.h"

int main()
{tree t;
    srand(time(NULL));
    char act[20];
    while(1)
    {printf("\n\n");
        menu();
        scanf("%s",act);
        if(!check_menu(act)) {printf("Incorrect input, use numbers [1..8]"); continue;}
        if(act[0]=='1')
        {
            printf("Maximum number sons in each node: 10.\n");
            printf("Path to node: example: 324 thats mean than you need firstly choose 3rd son of root, than second son of current node, and, finally, choose 4th son and delete it or add brother to it\n");
        }

        if(act[0]=='2')
        {
            int l;
            printf("How much levels in tree do you want?[1..15]\n");
            scanf("%d",&l);
            t=creation(l);
            printf("Process sucsessfully endend\n");
        }

        if(act[0]=='3')
        {
            print(t);
        }

        if(act[0]=='4')
        {
            printf("Enter path to node(Use help for more information):\n");
            char path[20];
            scanf("%s",path);
            new_node(t,path,1);
            printf("Process sucsessfully endend\n");
        }

        if(act[0]=='5')
        {
            printf("Enter path to node(Use help for more information):\n");
            char path[20];
            scanf("%s",path);
            new_node(t,path,0);
            printf("Process sucsessfully endend\n");
        }

        if(act[0]=='6')
        {
            printf("Enter path to node(Use help for more information):\n");
            char path[20];
            scanf("%s",path);
            del_subtree(t,path);
            printf("Process sucsessfully endend\n");
        }

        if(act[0]=='7')
        {
            printf("Are you sure you want to delete tree?[Y/n]\n");
            char x[3];
            scanf("%s",x);
            if(x[0]=='n' || x[0]=='N') continue;
            t=del_tree(t);
            printf("Process sucsessfully endend\n");

        }

        if(act[0]=='8')
        {
            result=0;
            int a=task(t);
            printf("There is(are) %d node(s) in the tree\n",a );
        }

        if(act[0]=='9')
        {
            printf("Sure you want to quit?[Y/n]\n");
            char x[3];
            scanf("%s",x);
            if(x[0]=='n' || x[0]=='N') continue;
            printf("Bye!\n");
            return 0;
        }
    }
}
