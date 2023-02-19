//Made by Isha pant,Apurba Subedi and Apeksha Shrestha.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[20];
    float per;
    struct node *prev; // points towards prev
    struct node *next; // points toward next
};

struct node *head = NULL;

void create() //to add the student's information using insertion at beginning
{
    char name[20];
    float a, b, c, d, e;
    float per;

    fflush(stdin);
    printf("Enter name:\n\n");
    gets(name);

    printf("Enter marks of 5 subjects:\n");
    scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
    per = (a + b + c + d + e) / 5;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->per = per;
    newNode->next = newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
   
    
}


void display() //to display the total data
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        printf("\nThe list is empty\n");
        exit(0);
    }
    else
    {
        printf("Roll No.\t\tName\t\t\tPercentage\n");
        while (ptr != NULL)
        {
            printf("%-20d%-30s%-8.2f%%\n", ptr->roll, ptr->name, ptr->per);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void del_pos() //to delete a certain position of data
{
    struct node *ptr = head;
    int i, pos;
    printf("enter the position");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty.\n");
        exit(0);
    }
    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(ptr);
        printf("Student deleted successfully.\n");
        return;
    }
    for (i = 1; i < pos && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Position not found.\n");
        return;
    }
    ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Student deleted successfully.\n");
}

void search_name() //to search for the information of a specific student using name 
{
    int test=0;
    char tempname[100] ;
    struct node * ptr;
    ptr= head;
   if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        exit(0);
    }
    fflush(stdin);
    printf("Enter the name of student to search:\n");
     gets(tempname);
    while(ptr!=NULL){
        if (strcmp(ptr->name,tempname)==0){
           printf("Roll No.\t\tName\t\t\tPercentage\n");
           printf("%-20d%-30s%-8.2f%%\n", ptr->roll, ptr->name, ptr->per);
            test++;
        }
        ptr=ptr->next;
        if(test==1)
        {
            return;
        }
    }
    if (test==0)
    {
        printf("The name could not be found.\n");
        return;
    }
}

void search_roll() //to search for the information of a specific student using roll number 
{
    int k=1,r,test=0;
    struct node* ptr=head;

    if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        exit(0);
    }

    printf("Enter the roll number of student to search: ");
    scanf("%d",&r);
    
    while(ptr!=NULL)
    {
        if (k==r)
        {
         printf("Roll No.\t\tName\t\t\tPercentage\n");
         printf("%-20d%-30s%-8.2f%%\n", ptr->roll, ptr->name, ptr->per);
            test++;
        }
        ptr=ptr->next;
        k++;
    if(test==1)
    {
        return;
    }
    }
    if(test==0)
    {
        printf("The roll no. could not be found.\n");
        return;
    }
}

void overview() //to display the brief information of the total data 
    {
        struct node *ptr;
        ptr = head;
        int i, count = 0;
        float avg = 0, pass_rate = 0, total = 0, per;int pass_num=0;
        if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        exit(0);
    }
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        ptr = head;
        for (i = 0; i < count; i++)
        {
            if ((ptr->per) >= 40)
            {
                pass_num++;
            }
            ptr=ptr->next;
        }
       
        ptr = head;
        for (i=0;i<count;i++)
        {
            total = total + ptr->per;
            ptr = ptr->next;
        }
        avg = total / count;
        pass_rate = ( (float)pass_num / count) * 100;
        printf("\n======CLASS OVERVIEW======\n");
        printf("Total number of students is %d\n", count);
        printf("The total number of students who have passed are %d\n",pass_num);
        printf("The average percentage of the students is %.2f\n", avg);
        printf("The pass rate of the students is %.2f%%\n", pass_rate);
    }

void writedata() //to write the information into a .txt file 
{
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("\nUnable to open file!\n");
        return;
    }
    struct node* current = head;
    while (current != NULL) {
        fprintf(fp, "%s %d %.2f\n", current->name, current->roll, current->per);
        current = current->next;
    }
    fclose(fp);
    printf("\nData written to file successfully!\n");
}


void sorting_alpha() //to sort the data alphabetically using bubble sort 
{
    if (head == NULL) {
        printf("\nNo data to sort!\n");
        exit(0);
    }
    struct node *i, *j;
    char tempName[50];
    int tempRoll;
    float tempPercentage;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(tempName, i->name);
                tempRoll = i->roll;
                tempPercentage = i->per;
                strcpy(i->name, j->name);
                i->roll = j->roll;
                i->per = j->per;
                strcpy(j->name, tempName);
                j->roll = tempRoll;
                j->per = tempPercentage;
            }
        }
    }

}


int count() //to count the total number of entries
{
    struct node *ptr;
    ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void roll() //to assign roll number alphabetically
{
    int k=1;
   struct node * ptr=head;
      while (ptr!=NULL)
      {
       ptr->roll= k;
     ptr=ptr->next;
       k++;
      }
}


int main() 
{
    int choice;
    char c;
        
    while (1)
    {
    	
		system("cls");
		printf("\t\t\t\t\tStudent Database Management System");
        printf("\n\t\t\t\t==================================================\n");

        printf("\n\t\t\t\t\t\tChoose an option:\n\n");
        printf("1. Add a student to the list\n");
        printf("2. Display the list of students\n");
        printf("3. Delete a student from the list\n");
        printf("4. Search for a specific students' details:\n");
        printf("5. Print the overview of the students.\n");
        printf("6. Write to file\n");
        printf("7. Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
                roll();
            sorting_alpha();
            break;
        case 2:
                roll();
                sorting_alpha();
            display();
            getch();
            
            break;
        case 3:
           del_pos();
           getch();
          break;
               
            case 4:
                printf("Do you want to search using roll no. or name?\n Press 'R' for roll no. and 'N' for name: ");
                scanf("%s", &c);
                roll();
                sorting_alpha();

                if(c=='R'|| c=='r')
                {
                    search_roll();
                    getch();
                    break;
                }
             else if(c=='N'|| c=='n')
               {
                    search_name();
                    getch();
                    break;
               }
                else{
                    printf("Invalid option.\n");
                    getch();
                    break;
                }
        case 5:
            overview();
            getch();
            break;
        case 6:
            writedata();
            getch();
            break;
        case 7:
            
          exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            getch();
            break;
        }
    }
    return 0;
}
