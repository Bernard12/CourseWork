#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char surname[20][16]=
{"Biersak","Williams","Jovi",
"Redkliff","Gates","Jobs",
"Mercury","Sykes","Greenwood",
"Skywalker", "Facker", "Stone",
"Stark", "Potter", "Weasley",
"Granger", "Snape", "Parker",
"Manson", "Lindemann"};

char inits[23][4]={"P.A","R.A","M.O","R.E",
"B.M","T.H",
"L.P",
"M.E","T.A","L.L","I.C","C.A",
"J.O", "H.N","B.O","N.N", "J.O", "V.I",
"A.M","A.R","A.N","T.H","E.E"
};

typedef struct Human
{
  char surname[16];
  char init[4];

  int group;
  int marks[4];
  char gender;
}Human;



void base_print(char* file_path) // распечатка базы
{
    FILE* f;
    f=fopen(file_path, "rb");
    if(f)
    {
        int i=1;
        Human h;
        while( ( fread(&h,sizeof(Human),1,f) )>0 )
        {
            printf("%d) ",i);
             printf("%s %c%c%c Gender: %c. Group № %d \t Marks:",h.surname,h.init[0],h.init[1],h.init[2],h.gender, h.group);
            for(int z=0; z<4; z++)
            {
                printf(" %d",h.marks[z]);
            }
            printf("\n");
            i++;
        }
        printf("\n\n\n");
    }
    else {printf("Error while opening the file.\n");}
}






Human random_add() //генерация структуры для 1 человека
{
  Human h;
  int a=rand()%20;
  for(int i=0;i<16;i++)
  {
    h.surname[i]=surname[a][i];
  }
  int b=rand()%23;
  for(int i=0;i<3;i++)
  {
     h.init[i]=inits[b][i];
  }

  for(int i=0; i<4; i++)
  {
   h.marks[i]=2+rand()%4;
  }
  h.group=101+(rand()%8);
  if((a+b)%2) h.gender='M';
  else h.gender='F';
  return h;
}


void base_create(char* file) //создание базы
{
  FILE* f;
  srand((unsigned) time(0) );
  f=fopen(file,"wb");
  if(f)
  {
    int num=0;
    printf("How much elements in base do you need?\n");
    scanf("%d",&num);
    for (int i = 0;i<num;i++)
    {

      Human a=random_add();
      fwrite(&a,sizeof(a),1,f);
    }
    fclose(f);
    printf("Creation proceeded successful\n" );
  }
  else
  {
    printf("Error while opening the file.\n");
  }
}

void manual_add(char* file) //ручное добавление в базу
{
  FILE* f;
  f=fopen(file,"a+b");
  if(f)
  {
      char x;
    printf("How much elements do you need to add?\n");
    Human h;
    int num;
    scanf("%d",&num);
    scanf("%c",&x);
    for (int i=0; i<num;i++)
    {

        int z=0;
        printf("Enter surname(up to 15 symbols):\n");
        scanf("%s",h.surname);
        scanf("%c",&x);
        printf("Enter inits(3 symbols, example: A.B):\n");
        scanf("%c%c%c",&h.init[0],&h.init[1],&h.init[2]);
        scanf("%c",&x);
        printf("Enter gender(F or M):\n");
        scanf("%c",&h.gender);
        scanf("%c",&x);
        if(h.gender=='m') h.gender='M';
        if(h.gender=='f') h.gender='F';
        if(h.gender!='M' && h.gender!='F')
        {
            if(h.gender<'F') h.gender='F';
            if(h.gender>'F') h.gender='M';
        }
        printf("Enter group(101-108):\n");
        scanf("%d",&h.group);
        scanf("%c",&x);
        printf("Enter 4 exam marks(2-5):\n");
      for (int j=0;j<4;j++)
      {
        scanf("%d", &h.marks[j]);
        if(h.marks[j]<2) h.marks[j]=2;
        if(h.marks[j]>5) h.marks[j]=5;
      }
      fwrite(&h,sizeof(Human),1,f);
    }
    fclose(f);
    printf("Addition proceeded successful\n");
  }
  else {printf("Error while opening the file.\n");}
}

void deletion_by_number(char* file_path, int n) //удаляет элемент по номеру
{
    int num=1;
    FILE* f=fopen(file_path,"rb");
    FILE* help=fopen("del.dat","w+b");
    Human h;
    if(f&&help)
    {
    while(fread(&h,sizeof(Human),1,f)>0)
    {
        if(num!=n)
        {
            fwrite(&h,sizeof(Human),1,help);
            num++;

        }
        else num++;

    }
    rewind(help);
    fclose(f);
    fopen(file_path,"wb");
    while(fread(&h,sizeof(Human),1,help)>0)
    {
        fwrite(&h,sizeof(Human),1,f);
    }
    fclose(f); fclose(help);
    remove("del.dat");
    printf("Deletion proceeded successful");
    }
    else printf("Error while opening files\n" );

}
int comparator(char* a, char* b)
{
    for(int i=0;i<16;i++)
    {
        if(a[i]!=b[i]) return 0;
        if(a[i]==b[i] && a[i]=='\0') return 1;
    }
}

void deletion_by_surname(char* path, char* surname)
{
    Human h;
    FILE* f=fopen(path,"rb");
    FILE* delete=fopen("name.dat","w+b");
    if(f&&delete)
    {
        while(fread(&h,sizeof(Human),1,f)>0)
        {
            if(comparator(h.surname,surname))
            {
                char c,n;
                printf("\n");
                printf("%s %c%c%c Gender: %c Group № %d Marks: %d %d %d %d\n",h.surname,h.init[0],h.init[1],h.init[2],h.gender,h.group,h.marks[0],h.marks[1],h.marks[2],h.marks[3]);
                printf("Delete this student?[Y/n]\n");
                while(1)
                {
                    scanf("%c%c",&n,&c);
                    if(c=='N' || c=='n' || c=='Y' || c=='y') break;
                    else printf("Error,enter[Y/n]\n");
                }
                if(c=='N' || c=='n')
                {
                    fwrite(&h,sizeof(Human),1,delete);
                }
            }
            else
            {
                fwrite(&h,sizeof(Human),1,delete);
            }
        }
        fclose(f);
        rewind(delete);
        fopen(path, "wb");
        while(fread(&h,sizeof(Human),1,delete)>0)
        {
            fwrite(&h,sizeof(Human),1,f);
        }
        fclose(f);fclose(delete);
        remove("name.dat");
        printf("Deletion proceeded successful");
    }
    else {printf("Error while opening files\n");}
}

    int task(char* path, int n)
    {
        FILE* f=fopen(path,"rb");
        if(f)
        {
            int res=0; Human h;
            while(fread(&h,sizeof(Human),1,f)>0)
            {
                if(h.group==n && h.gender=='F')
                {
                    int flag=1;
                    for(int i=0;i<4;i++)
                    {
                        if(h.marks[i]<4) flag=0;
                    }
                    if(flag) res++;
                }
            }
        printf("%d\n",res);
        }
        else {printf("Error while opening file"); return -1;}
    }

void menu()
{
printf("________________________Menu________________________\n");
printf("1.____________Base create & random fill_____________\n");
printf("2.___________________Print base_____________________\n");
printf("3.__________________Add  to base____________________\n");
printf("4._______________Deletion by number_________________\n");
printf("5.______________Deletion  by surname________________\n");
printf("6._________________Base  deletion___________________\n");
printf("7.____________________Task  12______________________\n");
printf("8._____________________Search_______________________\n");
printf("9._________________Change   file____________________\n");
printf("10._____________________Quit________________________\n");
}





void delete_base(char* path)
{
    FILE* f=fopen(path,"wb");
    if(f)
    {
		fclose(f);
    }
	else printf("I can not find or open the file.\n");

}

void surname_search(char* path)
{
    FILE* f;
    f=fopen(path, "rb");
    if(f)
    {
        char surname[16];
        printf("Enter surname(up to 15 symbols):\n");
        scanf("%s",surname);
        int i=1;
        Human h;
        while( ( fread(&h,sizeof(Human),1,f) )>0 )
        {
            if(comparator(h.surname,surname))
            {
                printf("%d) %s %c%c%c Gender: %c Group № %d Marks: %d %d %d %d\n",i,h.surname,h.init[0],h.init[1],h.init[2],h.gender,h.group,h.marks[0],h.marks[1],h.marks[2],h.marks[3]);
            }
            i++;
        }
        printf("\n\n\n");
    }
    else {printf("Error while opening the file.\n");}
}

void group_search(char* path)
{int i=1;
    FILE* f;
    Human h;
    f=fopen(path,"rb");
    if(f)
    {int g;
        printf("Enter number of group:\n");
        scanf("%d",&g);
        while( ( fread(&h,sizeof(Human),1,f) )>0 )
        {
            if(g==h.group)
            {
                printf("%d) %s %c%c%c Gender: %c Group № %d Marks: %d %d %d %d\n",i,h.surname,h.init[0],h.init[1],h.init[2],h.gender,h.group,h.marks[0],h.marks[1],h.marks[2],h.marks[3]);
            }
            i++;
        }
        printf("\n\n\n");
    }
    else {printf("Error while opening the file.\n");}
}
