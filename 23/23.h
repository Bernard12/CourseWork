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
        res++;
        return res;
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
{lvls--;
    //srand(time(NULL));
    tree t=(node*)malloc(sizeof(node));
    t->data=((float)(rand()%201))/(rand()%10+11.0);
    t->sons=NULL;
    int s=1+(rand()%3);
    list* help=t->sons;

    if(lvls>0)
    {
        list* l=(list*)malloc(sizeof(list));
        node* new=(node*)malloc(sizeof(node));
        l->value=new;
        (l->value)->data=((float)(rand()%201))/(rand()%10+11.0);
        (l->value)->sons=NULL;
        l->next=NULL;
        help=l;
        t->sons=help;
        help->value=creation(lvls);


        for(int i=0;i<s;i++)
        {
            list* ll=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));
            ll->value=new;
            (ll->value)->data=(float)((rand()%201)/rand()%10+11.0);
            (ll->value)->sons=NULL;
            ll->next=NULL;
            l->next=ll;
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
        for(int i=0;i<=cnt;i++) printf("  ");

        printf("%d %f\n",cnt,t->data);
        if(has_sons(t))
        {
            list* help=t->sons;
            while(help->next!=NULL)
            {
                cnt++;
                print(help->value);
                help=help->next;
                cnt--;
            }
            cnt++;
            print(help->value);
            cnt--;
        }
    }
}

void new_node(tree t, char* path,int random)
{
    int ns=sons(t), n=path[cnt]-'0';
    if(n>ns|| n==0 || path[cnt]=='\0')
    {
        if(t->sons)
        {
            list* help=t->sons;

            while(help->next!=NULL) help=help->next;

            list* l=(list*)malloc(sizeof(list));
            node* new=(node*)malloc(sizeof(node));
            l->value=new;

            if(random) l->value->data=((float)(rand()%201))/(rand()%10+11.0);
            else {printf("Enter value:\n"); scanf("%f",&l->value->data);}
            l->value->sons=NULL;
            l->next=NULL;
            help->next=l;
        }
        else
        {
            list* help=(list*)malloc(sizeof(list));
            node* new=(node*) malloc(sizeof(node));
            help->value=new;

            if(random) help->value->data=((float)(rand()%201))/(rand()%10+11.0);
            else{printf("Enter value:\n"); scanf("%f",&help->value->data);}
            help->value->sons=NULL;
            help->next=NULL;
            t->sons=help;
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

            if(random) l->value->data=((float)(rand()%201))/(rand()%10+11.0);
            else {printf("Enter value:\n"); scanf("%f",&l->value->data);}

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
            tree tr=help->value;
            del_sons(tr);
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
    if(length(node)==0 || check(node)==0)
        printf("Error, wrong path, try again or use help(point 1 of menu)");
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
                        del_sons(help->value);
                    }
                    else
                    {
                        t->sons=help->next;
                        del_sons(help->value);
                    }
                }
                else
                {
                    for(int i=0; i<son-2;i++) help=help->next;

                    list* delete=help->next;
                    help->next=delete->next;
                    del_sons(delete->value);
                    free(delete);
                }
            }
            else
            {
                cnt++;
                for(int i=0;i<son-1;i++) help=help->next;
                del_subtree(help->value,node);
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
    printf("3.  Print tree\n");
    printf("4.  Add node with random value\n");
    printf("5.  Add node with your value\n");
    printf("6.  Delete node and its descendants\n");
    printf("7.  Delete whole tree\n");
    printf("8.  Number of nodes in tree (task 22)\n");
    printf("9.  Quit\n");
}

int check_menu(char* action)
{
    if(action[0]>='1' && action[0]<='9' && action[1]=='\0') return 1;
    return 0;
}
int result=0;
int task(tree t)
{
    if(tree_empty(t)) return 0;
    else
    {
        result++;
        if(has_sons(t))
        {
            list* help=t->sons;
            while(help->next!=NULL)
            {
                cnt++;
                task(help->value);
                help=help->next;
                cnt--;
            }
            cnt++;
            task(help->value);
            cnt--;
        }
    }
    return result;
}
