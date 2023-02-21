

// hospital management system
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    char name[100];
    int age;
    char address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    int num;
    struct node *next;
    int disease;
};
struct node *head = NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
/*
pointer to function
    void fun(int a)
        printf("Value of a is %d\n", a);
    int main()
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
*/
int main()
{

    int option;
    do
    {
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
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = insert(head);
            getchar();
            system("cls");
            break;
        case 2:
            head = delete (head);
            getchar();
            system("cls");
            break;
        case 3:
            display(head);
            getchar();
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        }
    } while (option != 4);
}
struct node *insert(struct node *head)
{
    int pri;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %s", newnode->name);
    printf("Enter the patient's age:");
    scanf("%d", &newnode->age);
    printf("Enter your home address:");
    scanf(" %s", newnode->address);
    printf("Enter your phone number:");
    scanf("%d", &newnode->phone);
    printf("Enter the blood group of Patient:");
    scanf(" %s", newnode->bloodgroup);
    printf("Enter the reg no:");
    scanf("%d", &newnode->reg);
    table();
    printf("Enter your disease Number:");
    scanf("%d", &newnode->disease);
    //newnode->priority = pri;
    // newnode->disease=pri;
    if ((head == NULL))
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
    return head;
};
struct node *delete(struct node *head)
{
    struct node *newnode;
    if (head == NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return;
    }
    else
    {
        newnode = head;
        printf("\n Deleted Record is : %d", newnode->reg);
        head = head->next;
        free(newnode);
    }
    return head;
};
void display(struct node *head)
{
    struct node *newnode;
    newnode = head;
    if (head == NULL)
        printf("\nTHERE IS NO PATIENT\n");
    else
    {
        printf("\nPriority wise appointments are:\n");
        while (newnode != NULL)
        {
            printf("The name of patient is:%s\n", newnode->name);
            printf("The age of patient is:%d\n", newnode->age);
            printf("The address of patient is : %s\n", newnode->address);
            printf("Phone Number:%d\n", newnode->phone);
            printf("The blood group of patient is:%s\n", newnode->bloodgroup);
            printf("Disease of the patient is :  ");
            print_disease(newnode->disease);
            printf("---------------------------------------------------\n");
            newnode = newnode->next;
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
void print_disease(int disease)
{
    switch (disease)
    {

    case 1:
        printf("Heart attack\n");
        break;
    case 2:
        printf("Severe wound/Bleeding\n");
        break;
    case 3:
        printf("Cancer\n");
        break;
    case 4:
        printf("Chest pain\n");
        break;
    case 5:
        printf("Fracture\n");
        break;
    case 6:
        printf("Diabetes Checkup\n");
        break;
    case 7:
        printf("Infection\n");
        break;
    case 8:
        printf("Viral Fever\n");
        break;
    case 9:
        printf("Common Cold/Head ache\n");
        break;
    default:
        exit(0);
    }
}
