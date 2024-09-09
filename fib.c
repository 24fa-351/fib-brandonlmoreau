#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int recursiveFib(int N,int sum3, int sum2 , int sum1)
{
    if ((((N == 1) || N == 2)) && (sum2 < 2))
    {
        if (N==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }


    else if (N>=3)
    {
        sum3 = sum2 + sum1;
        sum1 = sum2;
        sum2 = sum3;

        recursiveFib(N-1,sum3,sum2,sum1);
    }
    else
    {
        return sum3;
    }
}
void iterativeFib(int N)
{
    int sum3;
    int sum2 = 1;
    int sum1 = 0;
    if (N > 3)
    {
        for (int i = 2; i < N; i++)
        {
            sum3 = sum2 + sum1;
            sum1 = sum2;
            sum2 = sum3;
        }
        printf("%d\n", sum3);

    }
    else if (N == 1)
    {
        sum3 = 0;
        printf("%d\n", sum3);

    }
    else if((N == 2)|| (N ==3 ))
    {
        sum3 = 1;
        printf("%d\n", sum3);

    }
}


int main(int argc, char *argv[]) {
    
    
    FILE* file;

    int IntegerChoice= atoi(argv[1]);
    char R_or_i_Choice = argv[2][0];
    char *FileChoice = argv[3];
    char FileInteger[100];
    int N;//prompt says to use single letter "N"

    

    //*****************************reads file data
    file = fopen(FileChoice, "r");
    fgets(FileInteger , sizeof(FileInteger) , file);
    fclose(file);
    //*********combine user and txt numeral into sum
    N = IntegerChoice;
    N = N + (atoi(FileInteger));
    //************fork into recursion or iteration
    if (R_or_i_Choice=='r')
    {
        int value = recursiveFib(N, 0 , 1 , 0);
        printf("%d\n", value);
    }
    else if (R_or_i_Choice=='i')
    {
        iterativeFib(N);
    }
    return 0;
}