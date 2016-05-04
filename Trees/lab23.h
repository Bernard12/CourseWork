#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt=0;

typedef struct node
{
    float data;
    struct list* sons;
}node;

typedef struct list
{
    struct node* value;
    struct list* next;
}list;

typedef struct node* tree;

tree t;
int levels[16];

int has_sons(tree t)
{
    if(t->sons) return 1;
    else return 0;
}

int sons(tree t)
{
    int res=0;
    if(t->sons)
    {
        list* help=t->sons;
        while(help->next!=NULL)
        {
            help=help->next;
            res++;
        }
        return res++;
    }
    return res;
}

int tree_empty(tree t)
{
    if(t) return 0;
    else return 1;
}

int check(char* a)
{
    for(int i=0;a[i]!='\0';i++)
    {
        if( a[i]<48 || a[i]>57) return 0;
    }
    return 1;
}

int length(char* a)
{
        int i=0;
        while(a[i]!='\0') i++;
        return i;
}

tree creation(int lvls)
{
    srand(time(NULL));
    tree t=(node*)malloc(sizeof(node));
    t->data=(float)((rand()%201)/rand()%10+11.0);
    t->sons=NULL;
    int s=1+rand()%4;
    list* help=t->sons;
    lvls--;
    if(lvls>0)
    {
        list* l=(list*)malloc(sizeof(list));
        node* new=(node*)malloc(sizeof(node));
        l->value=new;
        (l->value)->data=(float)((rand()%201)/rand()%10+11.0);
        (l->value)->sons=NULL;
        l->next=NULL;
        help=l;
        t->sons=help;
        help->value=creation(lvls);


        for(int i=0;i<s-1;i++)
        {
            list* l=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));
            l->value=new;
            (l->value)->data=(float)((rand()%201)/rand()%10+11.0);
            (l->value)->sons=NULL;
            l->next=NULL;
            l->next=l;
            l=l->next;
            l->value=creation(lvls);
        }
    }
    return t;
}

void print(tree t)
{
    if(tree_empty(t)) printf("Tree is empty\n");
    else
    {
        for(int i=0;i<=cnt;i++) printf(" ");
        printf("%f\n",t->data);
        if(has_sons(t))
        {
            list* help=t->sons;
            while(help->next!=NULL)
            {
                cnt++;
                print(help->value);
                cnt--;
            }
        }
    }
}

void new_node(tree t, char* path,int random)
{
    int ns=sons(t),n=path[cnt]-'0';
    if(n>ns || n==0 || path[cnt]=='\0')
    {
        if(t->sons)
        {
            list* help=t->sons;
            while(help->next!=NULL) help=help->next;

            list* l=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));

            l->value=new;
            if(random) (l->value)->data=(float)((rand()%201)/rand()%10+11.0);
            else scanf("%f",&l->value->data);
            (l->value)->sons=NULL;
            l->next=NULL;
            help->next=l;
        }
        else
        {
            list* l=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));
            l->value=new;
            if(random) (l->value)->data=(float)((rand()%201)/rand()%10+11.0);
            else scanf("%f",&l->value->data);
            (l->value)->sons=NULL;
            t->sons=l;
        }
    }
    else
    {
        if(t->sons)
        {
            list* help=t->sons;
            for(int i=0;i<path[cnt]-'0'-1;i++) help=help->next;
            cnt++;
            new_node(help->value,path,random);
            cnt--;
        }
        else
        {
            list* l=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));

            l->value=new;
            if(random) (l->value)->data=(float)((rand()%201)/rand()%10+11.0);
            else scanf("%f",&l->value->data);
            l->value->sons=NULL;
            l->next=NULL;
            t->sons=l;

        }
    }
}

void del_sons(tree t)
{
    if(has_sons(t))
    {
        list* help=t->sons;
        int j=sons(t);
        for(int i=0;i<j-1;i++)
        {
            del_sons(help->value);
            help=help->next;
        }
    }
    else free(t);
}

tree del_tree(tree t)
{
    del_sons(t);
    t=NULL;
    return t;
}
int z=0;
void del_subtree(tree t, char* node )
{
    if(!length(node) || check(node))
        printf("Error, wrong path, try again or use help(point * of menu)");
    else
    {
        int son=node[cnt]-'0';z++;
        if(sons(t)<son || !(t->sons))
            printf("Error, wrong path, on level %d in your path there ir only %d sons",z,sons(t));
        else
        {
            list* help=t->sons;
            if(node[cnt+1]=='\0')
            {
                if(son==1)
                {
                    if(sons(t)==1)
                    {
                        t->sons=NULL;
                        del_sons(help=help->value);
                    }
                    else
                    {
                        t->sons=help->next;
                        del_sons(help->value);
                    }
                }
                else
                {
                    for(int i=0; i<num-2;i++) help=help->next;

                    list* delete=help->next;
                    help->next=delete->next;
                    del_sons(delete->value);
                    free(delete);
                }
            }
            else
            {
                cnt++;
                for(int i=0;i<num-1;i++) help=help->next;
                del_node_and_sons(help->n,path);
                cnt--;
            }
        }
    }
}

void menu()
{
    printf("_________________Menu_________________\n");
    printf("1.  Help\n");
    printf("2.  Tree creation\n");
    printf("3.  Add node with random value\n");
    printf("4.  Add node with your value\n");
    printf("5.  Delete node and its descendants\n");
    printf("6.  Delete whole tree\n");
    printf("7.  Number of nodes in tree (task 22)\n");
    printf("8.  Quit\n");
}

int c(char* action)
{
    if action[1]!='\0' return 0;
    if(action[0]>='1' && action[0]<='8') return 1;
    return 0;
}
