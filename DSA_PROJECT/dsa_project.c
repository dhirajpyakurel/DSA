//hospital management system
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
int disease;
struct node
{
    char *name[100];
    int age;
    char *address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
    int num;
};
struct node *start= NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
int main()
{

    int option;
    do{
        system("COLOR 20");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t WELCOME TO MR NAMUS HOSPITAL!\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&option);
    switch(option)
    {
    case 1:
        start= insert(start);
        getchar();
        system("cls");
        break;
    case 2:
        start= delete(start);
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
        getchar();
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    }
}while(option!=4);
}
struct node *insert(struct node *start)
{
    int val2,val4,val6,pri;
    char val1,val3,val5;
    struct node *ptr,*p;
    char* name[100];
    char* address[100];
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %s",ptr-> name);
    printf("Enter the patient's age:");
    scanf("%d",&val2);
    printf("Enter your home address:");
    scanf(" %s",ptr->address);
    printf("Enter your phone number:");
    scanf("%d",&val4);
    printf("Enter the blood group of Patient:");
    scanf(" %s",ptr->bloodgroup);
    printf("Enter the reg no:");
    scanf("%d",&val6);
    printf("Enter your disease Number:");
    table();
    scanf("%d",&disease);
    //ptr->name=name;
    ptr->age=val2;
    //ptr->address=address;
    ptr->phone=val4;
    ptr->reg=val6;
    ptr->priority=pri;
    //ptr->disease=pri;
    if((start==NULL)||pri<start->priority)
    {
        ptr->next=start;
        start=ptr;
    }
    else
        {
            p=start;
            while(p->next!=NULL && p->next->priority <=pri)
                p=p->next;
            ptr->next=p->next;
            p->next=ptr;
        }
        return start;
};
struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return;
    }
    else
    {
        ptr= start;
        printf("\n Deleted Record is : %d",ptr->reg);
        start=start->next;
        free(ptr);
    }
    return start;
};
void display(struct node *start, int x)
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("\nTHERE IS NO PATIENT\n");
    else
    {
        printf("\Priority wise appointments are:\n");
        while(ptr!=NULL)
        {
            	printf("The name of patient is:%s\n",ptr->name);
                printf("The age of patient is:%d\n",ptr->age);
                printf("The address of patient is : %s\n",ptr->address);
                printf("Phone Number:%d\n",ptr->phone);
                printf("The blood group of patient is:%s\n",ptr->bloodgroup);
                printf("Disease of the patient is :  ");
                print_disease(disease);
                printf("---------------------------------------------------\n");
                ptr=ptr->next;
        }
    }
    getchar();
}
void table()
{
    printf("\t\t\nPlease Refer this Table for your disease!\n");
    printf("1.Heart attack\n");
    printf("2.Severe wound/Bleeding\n");
    printf("3.Cancer\n");
    printf("4.Chest pain\n");
    printf("5.Fracture\n");
    printf("6.Diabetes Checkup\n");
    printf("7.Infection\n");
    printf("8.Viral Fever\n");
    printf("9.Common Cold/Head ache\n");
}
void print_disease(int n)
{
	switch (n){
	
		case 1:
			printf("Heart attack\n");
			return;
		case 2: 
			printf("Severe wound/Bleeding\n");
			return;
		case 3:
			printf("Cancer\n");
			return;
		case 4:
			 printf("Chest pain\n");
			 return;
		case 5:
			 printf("Fracture\n");
			 return;
		case 6:
			 printf("Diabetes Checkup\n");
			 return;
	    case 7:
	    	 printf("Infection\n");
	    	 return;
	    case 8:
	    	 printf("Viral Fever\n");
	    	 return;
	    case 9:
	    	 printf("Common Cold/Head ache\n");
	    	 return;
	    default:
	    	exit(0);
	    }
}
