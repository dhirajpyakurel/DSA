#include<stdio.h>   
#include<conio.h>
#include<stdlib.h>

#define MAXSIZE 10  

int STACK[MAXSIZE];  
int TOP=-1;         

int isempty();      
int isfull();
void push();
void pop();
void peek();

void main()         
{
	int choice;
	choice=1;
	
	while(choice)
	{
		printf("1 to push \n");
		printf("2 to pop \n");
		printf("3 to peek \n");
		printf("Enter Your Choice \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			default:
				printf("Invalid Choice \n");
				exit(0);
		}
	}
	getch();
}
void push()
{
	int element;
	if(isfull())
	{
		printf("STACK OVERFLOW \n");
	}
	else
	{
		TOP=TOP+1;
		printf("Enter the element \n");
		scanf("%d",&element);
		STACK[TOP]=element;
	}
}
void pop()
{
	int element;
	if(isempty())
	{
		printf("STACK UNDERFLOW \n");
	}
	else
	{
		element=STACK[TOP];
		TOP=TOP-1;
		printf("Popped element is %d \n",element);
	}	
}
void peek()
{
	int t;
	t=TOP;
	if(isempty())
	{
		printf("STACK UNDERFLOW \n");
	}
	else
	{
	printf("The element at top = %d \n",STACK[t]);
    }
}
int isempty()
{
	if(TOP==-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
int isfull()
{
	if(TOP==(MAXSIZE-1))
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
