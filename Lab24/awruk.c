#include <stdio.h>

typedef struct elem
{
    char oper;
    int value;
}elem;

typedef struct stack
{
    elem el;
    stack* next;
}stack;

stack push(stack* s, char x, int v)
{
    stack* new=(stack*)malloc(sizeof(stack))
    new->el->oper=x;
    new->el->value=v;
    new->next=s;
    return new;
}

elem top(stack* s)
{
    return(s->el);
}

elem pop(stack *s)
{
    elem e;
    e.oper=s->el->oper;
    e.value=s->el->value;
    stack* new=s;
    s=s->next;
    free(new);
    return e;
}

int is_empty(stack s;)
{
    if(s->el==NULL) return 1;
    return 0;
}
