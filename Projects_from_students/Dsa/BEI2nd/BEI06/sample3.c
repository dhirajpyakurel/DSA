 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_NUMBER 10

struct contact {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
    struct contact *next;
    struct contact*prev;
    struct contact *ptr;
};
int result,choose,choice;



struct contact *head = NULL;
int check(const char *filename) {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        
        return -1;
    }
    int result = 0;  
    if (fgetc(fp) == EOF) {
    
        result = 1;
    }
    fclose(fp);
    return result;
}
 void add() {
    struct contact *newcontact = (struct contact *)malloc(sizeof(struct contact));
    printf("Enter the details in the order as below:\nName: ");
    scanf("%s", newcontact->name);
    printf("\nPhone number: ");
    scanf("%s", newcontact->number);

    if (head == NULL) {
        head = newcontact;
        newcontact->next = NULL;
        newcontact->prev = NULL;
        FILE *fp = fopen("contacts.txt", "a");
        if (fp == NULL) {
            printf("\nError opening file!\n");
            return;
        }
        fprintf(fp, "%s %s\n", newcontact->name, newcontact->number);
        fclose(fp);
        return;
    }

    struct contact *ptr = head;
    struct contact *prev = NULL;
    while (ptr != NULL && strcmp(ptr->name, newcontact->name) < 0) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL) {
        head = newcontact;
        newcontact->prev = NULL;
    } else {
        prev->next = newcontact;
        newcontact->prev = prev;
    }
    newcontact->next = ptr;
    if (ptr != NULL) {
        ptr->prev = newcontact;
    }

    FILE *fp = fopen("contacts.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    ptr = head;
    while (ptr != NULL) {
        fprintf(fp, "%s %s\n", ptr->name, ptr->number);
        ptr = ptr->next;
    }
    fclose(fp);
    printf("\nYour contact has been added successfully!\n");
}


void deletes() {
     
    printf("SEE THERE IS A CHOICE\n");
    printf("IF YOU WANT TO DELETE ALL CONTACTS PRESS 1\n");
    printf("IF YOU WANT TO DELTE SPECIFIC CONTACT PRESS 2\n");
    scanf("%d", &choose);
    if (choose == 1) {
        FILE *f = fopen("contacts.txt", "w");
        fclose(f);
        printf("ALL CONTACTS DELTED FORM FILE\n");
        head = NULL;
    } 
    else if(choose == 2) {
        
    printf("Enter the name of the contact to delete: ");
    char name[MAX_NAME];
    scanf("%s", name);
     FILE *fp = fopen("contacts.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct contact *prev = NULL;
    struct contact *ptr = head;
    
     
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("%s HEREBY THE REQUIED CONTACT DISSAPPEARED.\n", name);

            
            FILE *fp = fopen("contacts.txt", "w");
            if (fp == NULL) {
                printf("Error opening file\n");
                return;
            }
            ptr = head;
            while (ptr != NULL) {
                fprintf(fp, "%s %s\n", ptr->name, ptr->number);
                ptr = ptr->next;
            }
            fclose(fp);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    printf("%s WAS NOT FOUND IN THE LIST\n", name);
}
}

void display() {
    FILE *fp = fopen("contacts.txt", "r");
   

    printf("\nContacts:\n");
    char name[MAX_NAME], number[MAX_NUMBER];
    while (fscanf(fp, "%s %s", name, number) == 2) {
        printf("%s\t%s\n", name, number);
    }
    fclose(fp);
}

int main() {
    printf("\nWELCOME TO CONTACTS\n");

    FILE *fp = fopen("contacts.txt", "r");
    if (fp != NULL) {
        char name[MAX_NAME], number[MAX_NUMBER];
        while (fscanf(fp, "%s %s", name, number) == 2) {
            struct contact *newcontact = malloc(sizeof(struct contact));
            strcpy(newcontact->name, name);
            strcpy(newcontact->number, number);
            newcontact->next = head;
            head = newcontact;
        }
        fclose(fp);
    }

    int choice;
    do {
        printf("\nTHIS CONTACTS WILL GIVE YOU FOLLOWING OPTIONS\n CHOOSE FROM BELOW\n");
        printf("1. ADD A CONTACT\n2. DELETE A CONTACT\n3. DISPLAY AVAILABLE CONTACT\n4. EXIT FROM CONTACT LIST\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                deletes();
                break;
            case 3:
                display();
                 break;

            case 4:
                exit(1);
                break;  
            default:
            printf("ENTER CORRECT OPTION");
            break;
        }
    }
    while(choice!=4);
    return 0;
}