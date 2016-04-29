#include <stdio.h>
#include <stdlib.h>
#include "nomer8.h"
#include <time.h>
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

    if(c[0]=='1' && c[1]!='0')
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
        printf("\nProcess successfuly ended\n");
        print(l);
    }

    if(c[0]=='2')
    {long long n;
        srand(time(NULL));
        printf("How much elements you want to add in the end?\n");
        scanf("%lld",&n);
        for(long long j=0;j<n;j++)
        {
            int a;
            a=rand()%26;
            insert(l,a,count(l)+1);
        }
        printf("\nProcess successfuly ended\n");
        print(l);
    }

    if(c[0]=='3')
    {int n;
        printf("Enter number of element to delete:\n");
        scanf("%d",&n);
        cut_by_number(l,n);
        printf("\nProcess successfuly ended\n");
        print(l);

    }

    if(c[0]=='4')
    {
        printf("Enter value of element to delete(first element with the same value will be deleted):\n");
        int a;
        scanf("%d",&a);
        cut_by_value(l,a);
        printf("\nProcess successfuly ended\n");
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
        printf("List contains %d elements\n\n",count(l));
    }

    if(c[0]=='8')
    {
        l=reverse(l);
        printf("\nProcess successfuly ended\n");
        print(l);
    }

    if(c[0]=='9')
    {
        delete_list(l);
        printf("List successful deleted\n");
    }

    if(c[0]=='1' && c[1]=='0')
    {
        printf("\nBye!");
        return 0;
    }

}
}
