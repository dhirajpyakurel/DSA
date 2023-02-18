#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Contact{
    struct Contact *prev,*next;
    char name[50];
    char phone[10];
    // unsigned long long int phone;
};
struct Contact *head = NULL;
char info[50];
char number[10];
int i;



void selectionSort()
{
    struct Contact *temp;
    int count=0,i;
    temp=head;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
   

    if(count)
    {
        for(i=0;i<count;i++)
        {
           temp=head;
           while(temp->next!=NULL)
           {
                if(strcmp(temp->name,temp->next->name)>0)
                {
                    strcpy(info,temp->name);
                    strcpy(number,temp->phone);
                    strcpy(temp->name,temp->next->name);
                    strcpy(temp->phone,temp->next->phone);
                    strcpy(temp->next->name,info);
                    strcpy(temp->next->phone,number);            
                }
                temp=temp->next;
           }
        }
    }
    
}

void addContact(){
    struct Contact *newnode,*temp;
    newnode = (struct Contact *)malloc(sizeof(struct Contact));
    printf("\nEnter contact name: ");
    fflush(stdin);
    gets(info);
     for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
    printf("Phone Number: ");
    fflush(stdin);
    gets(number);
    if(head==NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        strcpy(newnode->name,info);
        strcpy(newnode->phone,number);
    }else{

        temp=head;
       
        do{
            if(strcmp(temp->name,info)==0)
            {
                printf("\n********************************************\n");
                printf("Duplicate Contact");
                printf("\n********************************************\n"); 
                return;
            }
            temp=temp->next;
        }
        while(temp!=NULL);
        temp=head;
          while(temp->next!=NULL)
        {
            temp=temp->next; 
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        strcpy(newnode->name,info);
        strcpy(newnode->phone,number);
        }
        printf("\n********************************************\n");
        printf("Contact Added Successfully");
        printf("\n********************************************\n"); 
        
    
}
void deleteContactBeg(){
    struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else{
        // selectionSort();
        temp=head;
        head=temp->next;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
        printf("\n********************************************\n");

    free(temp);
}
}
void deleteContactEnd(){
    struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else if(head->next==NULL)
    {
        // selectionSort();
        temp=head;
        head=NULL;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
        printf("\n********************************************\n");
        free(temp);
    }else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
        printf("\n********************************************\n");
        free(temp);
    }
    
}
void findContact(){
    struct Contact *temp;
   
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n"); 
    }else{
         printf("Enter contact name: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Contact Found:\n");
            printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
            printf("\n********************************************\n");
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}
void updateContact(){
     struct Contact *temp;
   
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n");
    }else{
         printf("Enter contact name: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Contact Found:\n");
            printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
            printf("\n********************************************\n");
            printf("\nEnter Contact Updates:\n");
            printf("\nContact name: ");
            fflush(stdin);
            gets(temp->name);
            printf("Phone Number: ");
            fflush(stdin);
            gets(temp->phone);
            printf("\n********************************************\n");
            printf("Contact Updated Successfully");
            printf("\n********************************************\n");
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}
void deleteContactByName(){
     struct Contact *temp;
    if(head==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is Empty");
        printf("\n********************************************\n");
    }else{
         printf("Enter contact name to be deleted: ");
         fflush(stdin);
         gets(info);
          for (i = 0; info[i]; i++) {
        if (info[i] >= 'A' && info[i] <= 'Z') {
            info[i] = info[i] - 'A' + 'a';
        }
    }
         temp=head;
    do{
        if((strcmp(temp->name,info)==0))
        {
            printf("\n********************************************\n");
            printf("Deleting Contact:\n");
            printf("Name: %s\nPhone Number: %s",temp->name,temp->phone);
            printf("\n********************************************\n");
            if(temp->prev==NULL)
            {
            head=temp->next;
            free(temp);
            printf("\n********************************************\n");
            printf("Contact Deleted Successfully");
            printf("\n********************************************\n");
            return;
            }
            temp->prev->next=temp->next;
            printf("\n********************************************\n");
            printf("Contact Deleted Successfully");
            printf("\n********************************************\n");
            free(temp);
            return;
            // break;
        }
        temp=temp->next;
    }while(temp!=NULL);
        printf("\n********************************************\n");
        printf("Contact not found");
        printf("\n********************************************\n");

    }
    
}


void display()
{
    struct Contact *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("\n********************************************\n");
        printf("Contact is empty");
        printf("\n********************************************\n");

    }else{
        selectionSort();
        i=0;
        printf("\n********************************************\n");
        printf("Contacts are: \n");
        do{
            printf("\nName: %s\nPhone Number: %s\n",temp->name,temp->phone);
            temp=temp->next;
        }while(temp!=NULL);
        printf("\n********************************************\n");
    }
    

}
void deleteSpecificContact()
{
    int j=0,k;
    struct Contact *ptr;
    display();
    if(head==NULL)
    {
        return;
    }
    printf("\nEnter the index of the contact that you want to delete: ");
    scanf("%d",&i);
    printf("After taking i");
    ptr=head;
    do{
        j++;   
        ptr=ptr->next;
    }while(ptr!=NULL);
    printf("After do while loop\n");
    ptr=head;
    printf("Value of j is: %d\n",j);
    if(i<=j && i>0)
    {
        if(i==1)
        {
            deleteContactBeg();
            return;
        }
        if(i==j)
        {
        deleteContactEnd();
        return;
        }
        for(k=1;k<i;k++)
        {
            ptr=ptr->next;
        } 
        
        printf("\n********************************************\n");
        printf("Deleted Contact\n");
        printf("Name: %s\nPhone Number: %s",ptr->name,ptr->phone);
        printf("\n********************************************\n");
        ptr->prev->next=ptr->next;
        free(ptr);
    }else{
        printf("\n********************************************\n");
        printf("No Contact Exist At That Index");
        printf("\n********************************************\n");
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter\n1. Add Contact\n2. Delete Contact From Beginning\n3. Delete Contact From End\n4. Delete Contact By Name\n5. Delete Specific Contact\n6. Find Contact\n7. Update Contact\n8. Display Contacts\n9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addContact();
                    getch();
                    break;
            case 2: deleteContactBeg();
                    getch();
                    break;
            case 3: deleteContactEnd();
                    getch();
                    break;
            case 4: deleteContactByName();
                    getch();
                    break;
            case 5: deleteSpecificContact();
                    getch();
                    break;
            case 6: findContact();
                    getch();
                    break;
            case 7: updateContact();
                    getch();
                    break;
            case 8: display();
                    getch();
                    break;
            case 9: exit(1);
                    break;
            default: printf("Invalid Input");
        }
    }
    return 0;
}