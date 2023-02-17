// BY: BHAWANA(009) AND RENSA(028)-BEI
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define max 10
char stackQ[max][256];
    int stackAns[max];
    int top=-1;
    void pushAns(int a)
    {
    top=top+1;
    stackAns[top]=a;
    }    
    int main()
    {
    printf("A miniproject brought to you by\n Bhawana adhikari and Rensa neupane\n");
    printf("A quiz using STACK as the data structure to pop the first and most valued question at last.\n");
    int points=0,i,ans;
    char name[100];
    char stackQ[max][256] = {
        "Final Question!!\nWhich of the following is linear data structure?\n1)tree\t2)graph\t3)none\t4)array",
        "9th Question!!\nWhich of the following is non-linear data structure?\n1)none\t2)array\t3)list\t4)Stack",
        "8th Question!!\nStack is based on which principle?\n1)LIFO\t2)FIFO\t3)PUSH\t4)none",
        "7th Question!!\nWe use theta notation for \n1)worst case\t2)Best case\t3)average case\t4)none",
        "6th Question!!\nMinimum how many stacks are needed to implement a queue\n1)2\t2)12\t3)0\t4)10",
        "5th Question!!\n Queue is based on which principle? \n1)FIFO\t2)LIFO\t3)PULL\t4)none",
        "4th Question!!\nFunction is to specify the data type\n1)typedef\t2)arr\t3)none\t4)id",
        "3rd Question!!\nA function which calls itself is called \n1)iteration\t2)algorithm\t3)recursion\t4)none",
        "2nd Question!!\nrecursion is based on \n1)stack\t2)queue\t3)none\t4)tree",
        "1st Question!!\nLinear Search is best for \n1)large arrays\t2)small arrays\t3)none\t4)sorted arrays"};
    pushAns(4);                //push 10 ans.
    pushAns(1);
    pushAns(1);
    pushAns(3);
    pushAns(1);
    pushAns(1);
    pushAns(1);
    pushAns(3);
    pushAns(1);
    pushAns(1);
    printf("\nWelcome to Quiz.\n");
    printf("Enter your name.  \n");
    scanf("%s",name);
    printf("Welcome %s\n",name);
    for(i=9;i>=0;i--)
    {
        printf("\n\nThis question is for %d points\n",(10-i)*10);
        printf("%s\n",stackQ[i]);
        printf("Enter your ans :\n");
        scanf("%d",&ans);
        if(ans==stackAns[i])
        {
            points=points+(10-i)*10;
            printf("Congrats!!!\t You earn %d points\n",(10-i)*10);
        }
        else if(ans==0)
        {
            printf("You choose to quit\n");
            break;
        }
        else
        {
            printf("Sorry, the correct answer is %d. \n",stackAns[i]);
            break;
        }
        }
        if(points==550)
        {
            printf("You are the winner of the quizeria with %d points!!!\n",points);
        }
        else {
            printf("Sorry, the correct answer is %d. \n",stackAns[i]);
        }
         printf("You scored %d points!!!\n",points);       
    }
