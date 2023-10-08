#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int lotto[6]={0,0,0,0,0,0};
lottoBall[5]={0,0,0,0,0};
int reward=0;
int numbers[6];


int main()
{
    system("color 1F");

    mainMenu();
    return 0;
}


void mainMenu()
 {
    int secim;

    system("cls");

    printf("\t\tLOTTERY GAMES MENU\n\n");
    printf("1 - Play Numarical Lotto \n2 - Play Lucky Ball \n3 - Play Super Lotto \n4 - Exit \n\n");

    printf("Your total reward: %d\n\n",reward);
    printf("Enter your choice:");
    scanf("%d",&secim);

    system("cls");

    switch(secim)
        {
           case 1 : playNumericalLotto(); break;
           case 2 : playLuckyBall(); break;
           case 3 : playSuperLotto(); break;
           case 4: exit(0);
           default: printf("Invalid Choice"); break;
        }

    }



void playNumericalLotto()
{
    system("cls");
    int i=0;
    srand(time(NULL));

    while(i<6)
    {
        int number= rand() % 49 + 1;
        if(lotto[0] != number &&
           lotto[1] != number &&
           lotto[2] != number &&
           lotto[3] != number &&
           lotto[4] != number &&
           lotto[5] != number )
        {
        lotto[i] = number;
        i++;
        }
    }

    i=0;
    while(i<6)
    {
        printf("\nNumber %d:",i+1);
        scanf("%d",&numbers[i]);

        if(numbers[i]<=49 && numbers[i]>=1)
        {
            i++;
        }
        else
            printf("The Entered Value Must Be Between [1-49] !  \n");
    }

    bubbleSortSmToL(lotto,6);
    bubbleSortSmToL(numbers,6);

    int correctGuess=Karsilastir(lotto,6,numbers,6);

    system("cls");


    printf("\n*********************************************\n");
    for(int i=0; i<6;i++)
    {
        printf("%d\t",lotto[i]);
    }
    printf("\n");

    for(int i=0; i<6;i++)
    {
        printf("%d\t",numbers[i]);
    }
    printf("\n*********************************************\n");


    if(correctGuess==3)
    {
        reward+=32;
    }
    else if(correctGuess==4)
    {
        reward+=64;
    }
    else if(correctGuess==5)
    {
        reward+=128;
    }
    else if(correctGuess==6)
    {
        reward+=256;
    }
    else
    {
        printf("\nYou didn't win an reward\n");
    }

    printf("\nYou guessed %d numbers correctly\n\n",correctGuess);
    printf("Total Score: %d\n",reward);

    playCheckNumericalLotto();
}



void playLuckyBall()
{
    system("cls");

    int i=0;
    int extraGuess;

    srand(time(NULL));

    while(i<5)
    {
        int number= rand() % 34 + 1;

        if(lottoBall[0] != number &&
           lottoBall[1] != number &&
           lottoBall[2] != number &&
           lottoBall[3] != number &&
           lottoBall[4] != number  )
        {
            lottoBall[i] = number;
            i++;
        }
    }

    int extraNumber = rand() % 14 + 1;
    printf("+%d",extraNumber);

    i=0;
    while(i<5)
    {
        printf("\nNumber %d:",i+1);
        scanf("%d",&numbers[i]);
        if(numbers[i]<=34 && numbers[i]>=1)
        {
            i++;
        }
        else
        {
            printf("The Entered Value Must Be Between [1-34] ! \n");
        }
    }

    i=0;
    while(i<1)
    {
        printf("\nExtra Number: ");
        scanf("%d",&extraGuess);
        if(extraGuess>=1 && extraGuess<=14)
        {
            i++;
        }

    }

    bubbleSortSmToL(lottoBall,5);
    bubbleSortSmToL(numbers,5);

    int correctGuess = Karsilastir(lottoBall,5,numbers,5);
    int correctExtraGuess=0;

    system("cls");


    printf("\n*********************************************\n");

    for(int i=4 ; i>=0 ; i--)
    {
        printf("%d\t",lottoBall[i]);
    }
    printf("+ %d",extraNumber);
    printf("\n");

    for(int i=4; i>=0 ; i--)
    {
        printf("%d\t",numbers[i]);
    }
    printf("+ %d",extraGuess);

    printf("\n*********************************************\n\n");


    if(extraGuess == extraNumber)
    {
        correctExtraGuess++;
    }


    if(correctGuess==1 && extraGuess == extraNumber)
    {
        reward+=2;
    }
    else if(correctGuess==2 && extraGuess == extraNumber)
    {
        reward+=4;
    }

    else if(correctGuess==3 && extraGuess != extraNumber)
    {
        reward+=8;
    }
    else if(correctGuess==3 && extraGuess == extraNumber)
    {
        reward+=16;
    }
    else if(correctGuess==4 && extraGuess != extraNumber)
    {
        reward+=32;
    }
    else if(correctGuess==4 && extraGuess == extraNumber)
    {
        reward+=64;
    }
    else if(correctGuess==5 && extraGuess != extraNumber)
    {
        reward+=128;
    }
    else if(correctGuess==5 && extraGuess == extraNumber)
    {
        reward+=256;
    }
    else
    {
        printf("You didn't win an reward.\n");
    }

    printf("\nYou guessed %d + %d numbers correctly\n\n",correctGuess,correctExtraGuess);
    printf("Total Score: %d\n",reward);

    playCheckLuckyBall();
}



void playSuperLotto()
{
    system("cls");

    int i=0;

    srand(time(NULL));

    while(i<6)
    {
        int number= rand() % 54 + 1;
        if(lotto[0] != number &&
           lotto[1] != number &&
           lotto[2] != number &&
           lotto[3] != number &&
           lotto[4] != number &&
           lotto[5] != number )
        {
            lotto[i] = number;
            i++;
        }
    }

    i=0;
    while(i<6)
    {
        printf("\nNumber %d:",i+1);
        scanf("%d",&numbers[i]);
        if(numbers[i]<=54 && numbers[i]>=1)
        {
            i++;
        }
        else
            printf("The Entered Value Must Be Between [1-54] ! \n");
    }


    bubbleSortSmToL(lotto,6);
    bubbleSortSmToL(numbers,6);

    int correctGuess=Karsilastir(lotto,6,numbers,6);
    system("cls");

    printf("\n*********************************************\n");

    for(int i=0; i<6;i++)
    {
        printf("%d\t",lotto[i]);
    }
        printf("\n");
    for(int i=0; i<6;i++)
    {
        printf("%d\t",numbers[i]);
    }

    printf("\n*********************************************\n\n");


    if(correctGuess==3)
    {
        reward+=32;
    }
    else if(correctGuess==4)
    {
        reward+=64;
    }
    else if(correctGuess==5)
    {
        reward+=128;
    }
    else if(correctGuess==6)
    {
        reward+=256;
    }
    else
    {
        printf("You didn't win an reward\n");
    }


    printf("\nYou guessed %d numbers correctly\n\n",correctGuess);
    printf("Total Score: %d\n",reward);

    playCheckSuperLotto();
}




void bubbleSortSmToL(int array[], int n)
{
    int swap;

    for (int c = 0 ; c < n - 1; c++)
    {
        for (int d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] > array[d+1])
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }
}



void bubbleSortLToSm(int array[], int n)
{
    int swap;

    for (int c = 0 ; c < n - 1; c++)
    {
        for (int d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] < array[d+1])
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }

}



int KarsilastirLToS(int array1[],int len1, int array2[],int len2)
{
    int i=len1, j=len2,counter=0;

    while (i >= 0 && j >= 0)
    {
        if(array1[i] == array2[j] )
        {
            counter++;
            i--;
            j--;
        }
        else if( array1[i] >array2[j] )
        {
            i--;
        }
        else
            j--;
    }

    return counter;
}



int Karsilastir(int array1[],int len1, int array2[],int len2)
{
    int i=0, j=0,counter=0;
        while (i < len1 && j < len2)
        {
            if(array1[i] == array2[j] )
            {
                counter++;
                i++;
                j++;
            }
            else if( array1[i] < array2[j] )
            {
                i++;
            }
            else
                j++;
        }

        return counter;
}


void playCheckNumericalLotto()
{
    char desicion;

    printf("\nDo you Want To Play Again?\nYes->Y/y\tNo->N/n\n");
    scanf("%s",&desicion);

    if(desicion=='N' || desicion=='n')
    {
        mainMenu();
    }
    else if(desicion=='Y' || desicion=='y')
    {
        playNumericalLotto();
    }
}



void playCheckLuckyBall()
 {
    char desicion;

    printf("\nDo you Want To Play Again?\nYes->Y/y\tNo->N/n\n");
    scanf("%s",&desicion);

    if(desicion=='N' || desicion=='n')
    {
        mainMenu();
    }
    else if(desicion=='Y' || desicion=='y')
    {
        playLuckyBall();
    }

 }



 playCheckSuperLotto()
 {
    char desicion;

    printf("\nDo you Want To Play Again?\nYes->Y/y\tNo->N/n\n");
    scanf("%s",&desicion);

    if(desicion=='N' || desicion=='n')
    {
        mainMenu();
    }
    else if(desicion=='Y' || desicion=='y')
    {
        playSuperLotto();
    }

 }
