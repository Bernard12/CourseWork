#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab23.h"

int main()
{
    srand(time(NULL));
    char act[20];
    while(1)
    {
        scanf("%s",act);
        if(!c(act)) {printf("Incorrect input, use numbers [1..8]"); continue;}
        if(act[0]=='1')
        {
            printf("Maximum number sons in each node: 15.");
            printf("Path to node: example: 324 thats mean than you need firstly choose 3rd son of root, than second son of current node, and, finally, choose 4th son and delete it or add brother to it");
        }
    }
}
