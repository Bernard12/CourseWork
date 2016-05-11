#include <stdio.h>

typedef struct elem
{
    char op;
    int val;
}elem;

int isoper(char a)
{
    if(a=='*' || a=='-' || a=='/' || a=='*' || a=='^' ) return 1;
    return 0;
}

int isopen(char a)
{
    if(a=='(') return 1;
    return 0;
}

int isclose(char a)
{
    if(a==')') return 1;
    return 0;
}

int isnum(char a)
{
    if( a>=48 && a<=57 ) return 1;
    return 0;
}

int istemp(char a)
{
    if(a>=65 && a<=90) return 1;
    if(a>=97 && a<=122) return 1;
    return 0;
}

int main()
{
    char input[100];
    elem output[100];
    scanf("%s",input);
    int cnt=0;
int open=0, close=0;
    for(int i=0;input[i+1]!='\0';i++)
    {
        if(isopen(input[i]))
        {open++;
            if( !(input[i+1]=='-' || isnum(input[i+1]) || istemp(input[i+1]) || isopen(input[i+1]))  ) {printf("Wrong input\n"); return 0;}
            continue;
        }
        if(isclose(input[i]))
        {close++;
            if( !(isoper(input[i+1]) || isclose(input[i+1]) || isnum(input[i+1]) || istemp(input[i+1])) ) {printf("Wrong input\n"); return 0;}
            continue;
        }
        if(isoper(input[i]))
        {
            if( isclose(input[i+1]) ) {printf("Wrong input\n"); return 0;}
            continue;
        }
        if(isnum(input[i]))
        {
            if( istemp(input[i+1]) || isopen(input[i+1]) ) {printf("Wrong input\n"); return 0;}
            continue;
        }
        if(istemp(input[i]))
        {
            if( istemp(input[i+1]) ) {printf("Wrong input, name of variables must consist of 1 char"); return 0;}
            if( isnum(input[i+1]) || isopen(input[i+1]) ) {printf("Wrong input\n"); return 0;}
            continue;
        }

    }
    //printf("%d  %d",open, close);
if(open!=close) {printf("Wrong input\n"); return 0;}
    for (int i=0;input[i]!='\0';i++)
    {//printf("\n%d\n",i);
        if(i==0)
        {
            if(istemp(input[i]))
            {
                output[cnt].op=input[i];
                cnt++;
                continue;
            }
                if( isnum(input[i]) )
                {
                    int res=0;
                    while(isnum(input[i]))
                    {
                        res*=10;
                        res+=(input[i]-'0');
                        i++;
                    }
                    output[cnt].op='?';
                    output[cnt].val=res; cnt++;
                    i--; continue;
                }
                if( input[i]=='-' )
                {
                    i++;
                    if( isnum(input[i]) )
                    {
                        int res=0;
                        while(isnum(input[i]))
                        {
                            res*=10;
                            res+=(input[i]-'0');
                            i++;
                        }
                        output[cnt].op='?';
                        output[cnt].val=(-1)*res; cnt++;
                        i--; continue;
                    }
                    if(istemp(input[i]))
                    {
                        output[cnt].op=input[i];
                        cnt++;
                        continue;
                    }

                }

                if( input[i]!='-' && !isopen(input[i]) ) {printf("Wrong input\n"); return 0;}
        }



        if(input[i]=='(') {output[cnt].op='('; cnt++; continue;}
        if(input[i]==')') {output[cnt].op=')'; cnt++; continue;}

        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='/' && (isnum(input[i+1]) || istemp(input[i-1]) ) ) {output[cnt].op='/'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='/' && isopen(input[i+1]) ){output[cnt].op='/'; cnt++; continue;}
        if( isclose(input[i-1]) && input[i]=='/' && (isnum(input[i+1]) || istemp(input[i-1])) ) {output[cnt].op='/'; cnt++; continue;}
        if( isopen(input[i+1])  && input[i]=='/' && isclose(input[i-1])){output[cnt].op='/'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='/' && input[i+1]=='-' )   {output[cnt].op='/'; cnt++; continue;}
        if(isclose(input[i-1])  && input[i]=='/' && input[i+1]=='-' )   {output[cnt].op='/'; cnt++; continue;}

        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='*' && (isnum(input[i+1]) || istemp(input[i-1])) ) {output[cnt].op='*'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='*' && isopen(input[i+1]) ){output[cnt].op='*'; cnt++; continue;}
        if( isclose(input[i-1]) && input[i]=='*' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='*'; cnt++; continue;}
        if( isopen(input[i+1])  && input[i]=='*' && isclose(input[i-1])){output[cnt].op='*'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='*' && input[i+1]=='-' )   {output[cnt].op='*'; cnt++; continue;}
        if(isclose(input[i-1])  && input[i]=='*' && input[i+1]=='-' )   {output[cnt].op='*'; cnt++; continue;}


        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='+' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='+'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='+' && isopen(input[i+1]) ){output[cnt].op='+'; cnt++; continue;}
        if( isclose(input[i-1]) && input[i]=='+' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='+'; cnt++; continue;}
        if( isopen(input[i+1])  && input[i]=='+' && isclose(input[i-1])){output[cnt].op='+'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='+' && input[i+1]=='-' )   {output[cnt].op='+'; cnt++; continue;}
        if(isclose(input[i-1])  && input[i]=='+' && input[i+1]=='-' )   {output[cnt].op='+'; cnt++; continue;}


        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='-' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='-'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='-' && isopen(input[i+1]) ){output[cnt].op='-'; cnt++; continue;}
        if( isclose(input[i-1]) && input[i]=='-' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='-'; cnt++; continue;}
        if( isopen(input[i+1])  && input[i]=='-' && isclose(input[i-1])){output[cnt].op='-'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='-' && input[i+1]=='-' )   {output[cnt].op='-'; cnt++; continue;}
        if(isclose(input[i-1])  && input[i]=='-' && input[i+1]=='-' )   {output[cnt].op='-'; cnt++; continue;}


        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='^' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='^'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='^' && isopen(input[i+1]) ){output[cnt].op='^'; cnt++; continue;}
        if( isclose(input[i-1]) && input[i]=='^' && (isnum(input[i-1]) || istemp(input[i-1])) ) {output[cnt].op='^'; cnt++; continue;}
        if( isopen(input[i-1]) && input[i]=='^' && isclose(input[i+1])){output[cnt].op='^'; cnt++; continue;}
        if(  (isnum(input[i-1]) || istemp(input[i-1])) && input[i]=='^' && input[i+1]=='-' )   {output[cnt].op='^'; cnt++; continue;}
        if(isclose(input[i-1]) && input[i]=='^' && input[i+1]=='-' )   {output[cnt].op='^'; cnt++; continue;}

        if( (isoper(input[i-1]) || isopen(input[i-1])) && input[i]=='-' && isnum(input[i+1]) )
        {
            int res=0;
            i++;
            while(isnum(input[i]))
            {
                res*=10;
                res+=(input[i]-'0');
                i++;
            }
            output[cnt].op='?';
            output[cnt].val=(-1)*res; cnt++;
            i--; continue;

        }

        if( (isoper(input[i-1]) || isopen(input[i-1])) && input[i]=='-' && istemp(input[i+1]) )
        {
            output[cnt].op='(';
            cnt++;
            output[cnt].op='?';
            output[cnt].val=0;
            cnt++;
            output[cnt].op='-';
            cnt++;
            output[cnt].op=input[i+1];
            cnt++;
            output[cnt].op=')';
            cnt++;
            i++; continue;
        }

        if( (isopen(input[i-1]) || isoper(input[i-1])) && isnum(input[i]) )
        {
            int res=0;
            while(isnum(input[i]))
            {
                res*=10;
                res+=(input[i]-'0');
                i++;
            }
            output[cnt].op='?';
            output[cnt].val=res; cnt++;
            i--; continue;

        }

        if( (isopen(input[i-1]) || isoper(input[i-1])) && istemp(input[i]) )
        {
                output[cnt].op=input[i];
                cnt++;
                continue;
        }

        if( isopen(input[i-2]) && input[i-1]=='-' && isnum(input[i]) )
        {
            int res=0;
            while(isnum(input[i]))
            {
                res*=10;
                res+=(input[i]-'0');
                i++;
            }
            output[cnt].op='?';
            output[cnt].val=(-1)*res; cnt++;
            i--; continue;
        }

        if( isoper(input[i-2])&& input[i-1]=='-' && isnum(input[i]) )
        {
            int res=0;
            while(isnum(input[i]))
            {
                res*=10;
                res+=(input[i]-'0');
                i++;
            }
            output[cnt].op='?';
            output[cnt].val=(-1)*res; cnt++;
            i--; continue;

        }

        if( isoper(input[i-2]) && input[i-1]=='-' && istemp(input[i]) )
        {
            output[cnt].op='(';
            cnt++;
            output[cnt].op='?';
            output[cnt].val=0;
            cnt++;
            output[cnt].op='-';
            cnt++;
            output[cnt].op=input[i+1];
            cnt++;
            output[cnt].op=')';
            cnt++;
            i++; continue;
        }


        if( (isnum(input[i-1]) || istemp(input[i-1]) || isclose(input[i-1])) && isoper(input[i]) && (input[i+1]=='-') )
        {
            continue;
        }


        printf("Error, wrong input\n"); return 0;
    }
    printf("\n");
    for(int i=0;i<cnt;i++)
    {
        if(output[i].op=='?') printf("%d   ",output[i].val);
        else printf("%c   ",output[i].op);

    }
printf("\n");
}
