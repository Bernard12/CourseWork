#include "nomer6.h"
#include <stdio.h>

/*char Check(char* path,int i)
{
    char c,n;
    if(i==1)
    {
        printf("Enter file path:\n");
        scanf("%s",path);
    }
    if(i==2)
    {
        printf("Use pervious filename?[Y/n]\n");

        {
            while(1)
            {
                scanf("%c%c",&c,&n);
                if(c=='N' || c=='n' || c=='Y' || c=='y') break;
                else printf("Error, enter [Y/n]\n");
            }
        }
        if(c=='n' || c=='N')
        {
            printf("Enter path: \n");
            scanf("%s",path);
        }
    }

}
*/

int main()
{
    char c,act[10];
    char path [200];
    int i=1;
    printf("Enter file path:\n");
    scanf("%s",path);

    while(i)
    {
        menu();
        printf("Choose option:\n");
        scanf("%s",act);

        //if(action>8 || action<1)
        //{
            //while(1)
            //{
            //    printf("Error, option must be a number [1..8]\n");
            //    scanf("%d",&action);
            //    if(action>=1 || action<=9) break;
            //}

        //}
        if(act[0]=='1'&& act[1]!='0')
        {
        //    Check(path,i);
            base_create(path);
        }

        if(act[0]=='2')
        {
        //    Check(path,i);
            base_print(path);
        }

        if(act[0]=='3')
        {
        //    Check(path,i);
            manual_add(path);
        }

        if(act[0]=='4')
        {
            //Check(path,i);
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
            //Check(path,i);
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
            //Check(path, i);
            printf("Are you sure you want to delete base %s ?[Y/n]\n",path);
            char c[10];
            scanf("%s",c);

            if(c[0]!='Y' && c[0]!='y') {}
            else delete_base(path);
        }

        if(act[0]=='7')
        {int n;char s;
            //Check(path,i);
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
            printf("Closing");
            return 0;
        }
        i=2;

    }
}
