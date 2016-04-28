#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* prev;
    struct node* next;
}node;

typedef struct node* list;

list to_barrier(list l)
{
    while(l->prev!=NULL) l=l->prev;
    return l;
}


int empty(list l)
{
    if(l->next==NULL && l->prev==NULL && l->value==INT_MIN) return 1;
    else return 0;
}

int count(list l)
{
    int n=0;
    list help=l;

    help=to_barrier(help);
    if(empty(help)) return 0;
    else
    {
        while(help->next!=NULL)
        {
            n++;
            help=help->next;
        }
        return (n);
    }
}

list insert(list l,int a, int n)
{
    list help=(list)malloc(1*sizeof(node));
    if(n==1)
    {
        //help->value=a;
        //help->next=l;
        //help->prev=NULL;
        //return help;
        l=to_barrier(l);
        help->value=INT_MIN;
        help->prev=NULL;
        help->next=l;
        l->prev=help;
        help=help->next;
        help->value=a;
        help=help->prev;
        return(help);
    }

    else if( n<1 || n>(count(l)+1) )
    {
        printf("Error,wrong palce for inserting");
        return l;
    }

    else if(n==count(l)+1)
    {
        list help=(list)malloc(1*sizeof(node));
        help->value=a;
        help->next=NULL;
        while(l->next!=NULL)
        {
            l=l->next;
        }
        l->next=help;
        help->prev=l;
        l=to_barrier(l);
        return (l);
    }

    else
    {
        list l1=to_barrier(l);

        for(int i=0; i<n-1 ;i++)
        {
            l1=l1->next;
        }
        list l2=l1->next;
        list k=(list)malloc(1*sizeof(node));
        k->value=a;
        k->prev=l1;
        k->next=l2;
        l1->next=k;
        l2->prev=k;

        k=to_barrier(k);
        return k;
    }

}

list cut_by_value(list l, int a)
{
    list l1=to_barrier(l);
    if(empty(l1)) return l1;
    l1=l1->next;
    if(l1->value==a)
    {
        l1->value=INT_MIN;
        list del=l1->prev;
        free(del);
        l1->prev=NULL;
        return l1;
    }
    int i=1;
    while(  l1->next!=NULL )
    {
        if(l1->value==a)
        {
            list l2=(l1->next);
            l1=l1->prev;
            list del=l1->next;
            free(del);
            l1->next=l2;
            l2->prev=l1;
            l2=(to_barrier(l2));
            return l2;
        }
        l1=l1->next;
    }
    if(l1->next==NULL)
    {
        if(l1->value==a)
        {
            list l2=l1->prev;
            free(l1);
            l2->next=NULL;
            l2=to_barrier(l2);
            return l2;
        }
    }
    printf("Element with value=%d not found",a);
    return l;
}

list cut_by_number(list l, int num)
{
    list l1=to_barrier(l);

    if(num==1 && count(l)!=1)
    {
        list l2=(l1->next)->next;
        free(l1);
        list bar=(list)malloc(1*sizeof(node));
        bar->prev=NULL;
        bar->next=l2;
        l2->prev=bar;
        l2=to_barrier(l2);
        return l2;
    }

    if(num==count(l1))
    {
        while( (l1->next)->next!=NULL)
        {
            l1=l1->next;
        }
        list del=l1->next;
        free(del);
        l1->next=NULL;
        l1=(to_barrier(l1));
        return l1;
    }
    for(int i=1;i<num;i++)
    {
        l1=l1->next;
    }
    list l2=(l1->next)->next;
    list del=l1->next;
    free(del);
    l1->next=l2;
    l2->prev=l1;
    l2=to_barrier(l2);
    return l2;
}

void row_print(list l)
{int i=0;
    printf("\n\t");
    list help=l;
    help=to_barrier(help);
    while( help->next!=NULL )
    {
        int a=(help->next)->value;
        printf("%d",a);
        help=help->next;
        if(help->next!=NULL) printf(" <-> ");
        if(i==9 && help->next!=NULL)
        {
            printf("\n\t<-> ");
            i=-1;
        }

        i++;
    }
    printf("\n");
}

void column_print(list l)
{
    list help=l;
    help=to_barrier(help);
    help=help->next;
    while(help->next!=NULL)
    {
        int a=help->value;
        printf("   %d\n",a);
        help=help->next;
        if(help->next!=NULL)
        {
            printf("   |\n");
        }
    }
}

void delete_list(list l)
{
    while(count(l))
    {
        cut_by_number(l,1);
    }
}

void menu()
{
    printf("                   Menu                   \n");
    printf("1.           Add new elements             \n");
    printf("2.        Add new random elements         \n");
    printf("3.       Remove element by number         \n");
    printf("4. Remove first element with same value   \n");
    printf("5.          Print list in a row           \n");
    printf("6.        Print list in a column          \n");
    printf("7.            Delete the list             \n");
    printf("8.                 Quit                   \n");

}

void print(list l)
{
    char z[50];
    printf("Print list?[Y/n]\n");
    char f;
    scanf("%c%s",z,&f);
    if(f=='y' || f=='Y')
    {
        row_print(l);
    }
}
