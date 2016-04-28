#include <stdio.h>
#include "nomer8.h"

int main()
{
node create;
create.value=INT_MIN;
create.prev=NULL;
create.next=NULL;
list l=&create;
int i=1;

while(i)
{char c[20];
    menu();
    printf("Choose option (number [1..8]): \n");
    scanf("%s",c);

    if(c[0]=='1')
    {
        int k;
        printf("How much elements you want to add?\n");
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int val,num;
            printf("Enter value of element:\n");
            scanf("%d",&val);
            printf("Enter number of position:\n");
            scanf("%d",&num);
            insert(l,val,num);
        }
        printf("\nInsertion successful\n");
        print(l);
    }

    if(c[0]=='2')
    {int n;
        printf("How much elements you want to add in the end?\n");
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int a;
            a=rand()%26;
            insert(l,a,count(l)+1);
        }
        printf("\nInsertion successful\n");
        print(l);
    }

    if(c[0]=='3')
    {int n;
        printf("Enter number of element to delete:\n");
        scanf("%d",&n);
        cut_by_number(l,n);
        printf("\nDeletion successful\n");
        print(l);

    }

    if(c[0]=='4')
    {
        printf("Enter value of element to delete(first element with the same value will be deleted):\n");
        int a;
        scanf("%d",&a);
        cut_by_value(l,a);
        printf("\nDeletion successful\n");
        print(l);
    }

    if(c[0]=='5')
    {
        row_print(l);
    }

    if(c[0]=='6')
    {
        column_print(l);
    }

    if(c[0]=='7')
    {
        delete_list(l);
        printf("List successful deleted");
    }
    if(c[0]=='8')
    {
        return 0;
    }

}
}
