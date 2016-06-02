#include "nomer6.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    char c,act[10];
    char path [200];
    int i=1;

    if(argc>=2)
    {
        for(int i=0;1;i++)
        {
            if(argv[1][i]=='\0')
            {
                path[i]='\0';
                break;
            }
            path[i]=argv[1][i];
        }
    }
    else
    {
    printf("Enter file path:\n");
    scanf("%s",path);
    }

    while(i)
    {
        menu();
        printf("Choose option:\n");
        scanf("%s",act);

        if(act[0]=='1'&& act[1]!='0')
        {

            base_create(path);
        }

        if(act[0]=='2')
        {

            base_print(path);
        }

        if(act[0]=='3')
        {

            manual_add(path);
        }

        if(act[0]=='4')
        {

            printf("Enter number of student, which you want to delete:\n");
            int n;
            scanf("%d",&n );
            deletion_by_number(path,n);
            char c,z;
            printf("\nPrint a base?[Y/n]\n");
            scanf("%c%c",&z,&c);
            if(c=='Y' || c=='y') base_print(path);

        }

        if(act[0]=='5')
        {
            char c,z;

            char sur[16];
            printf("Enter surname of student, which you want to delete(up to 15 symbols):\n");
            scanf("%s",sur);
            deletion_by_surname(path, sur);
            printf("\nPrint a base?[Y/n]\n");
            scanf("%c%c",&z,&c);
            if(c=='Y' || c=='y') base_print(path);
        }

        if(act[0]=='6')
        {

            printf("Are you sure you want to delete base %s ?[Y/n]\n",path);
            char c[10];
            scanf("%s",c);

            if(c[0]!='Y' && c[0]!='y') {}
            else delete_base(path);
        }

        if(act[0]=='7')
        {int n;char s;

            printf("Enter group:\n");
            scanf("%d%c",&n,&s);
            printf("Result: ");
            task(path, n);
        }

        if(act[0]=='8')
        {
            printf("________________________Search________________________\n");
            printf("1.________________Search  by surname__________________\n");
            printf("2._________________Search  by group___________________\n");
            char s[10];
            printf("Choose type of search:\n");
            scanf("%s",s);
            if(s[0]=='1') surname_search(path);
            if(s[0]=='2') group_search(path);
        }

        if(act[0]=='9')
        {
            printf("Enter new file path:\n");
            scanf("%s",path);
        }

        if(act[0]=='1' && act[1]=='0')
        {
            printf("Closing\n");
            return 0;
        }
        i=2;

    }
}
