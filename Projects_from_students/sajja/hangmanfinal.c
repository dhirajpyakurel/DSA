#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

void clearScreen();
void printMan(int);
void printWord(const char[], const char[]);
int getGuess(char[]);
void welcome();


// Define a linked list node for storing words
struct word_node {
    char word[MAX_WORD_LENGTH+1];
    struct word_node* next;
};

// Function to insert a word into the linked list
void insert_word(struct word_node** head, const char* word) {
    struct word_node* new_node = (struct word_node*) malloc(sizeof(struct word_node));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

// Function to select a random word from the linked list
void select_word(const struct word_node* head, char* word) 
{
    int count = 0;
    const struct word_node* node = head;
    
    while (node != NULL) {
        count++;
        if (rand() % count == 0) {
            strcpy(word, node->word);
        }
        node = node->next;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    

    ////////////////////////Insert in the list////////////
    int i;
    char dictionary[][15] = {"banana","pomegranate","nectarine","grape","strawberry","kiwi","melon","peach","pear","watermelon","mango","papaya","cherry","blackberry","pineapple"};

    struct word_node* head = NULL;
    for (i = 0; i < 15; i++)
    {
        insert_word(&head, dictionary[i]);
    }
    
    // Select a random word from the linked list
    char word[MAX_WORD_LENGTH+1];
    select_word(head, word);
    
  //  printf("The selected word is: %s\n", word);
//////////////////////////////////////////
int length = strlen(word);
    char display[length + 1];
    char used[26];
    int tries = 0;
    int correct_guesses = 0;
    welcome();


    for (int i = 0; i < length; i++)
    {
        display[i] = '_';
    }
    display[length] = '\0';
    for (int i = 0; i < 26; i++)
    {
        used[i] = '\0';
    }
    clearScreen();
    while (tries < MAX_TRIES && correct_guesses < length)
    {
        printMan(tries);
        printWord(display, used);
        char guess = getGuess(used);
        int good_guess = 0;
        for (int i = 0; i < length; i++)
        {
            if (guess == word[i])
            {
                display[i] = guess;
                ++correct_guesses;
                good_guess = 1;
            }
        }
        if (!good_guess)
        {
            ++tries;
        }
        clearScreen();
    }
    printMan(tries);
    if (correct_guesses == length)
    {
        printf("\n\nCongratulations! You won! The word was ~ *%s*\n", word);
    }
    else
    {
        printf("\n\nSorry, you lost. The word was %s\n", word);
    }
    return 0;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void welcome()
{
    int exit;
    printf("\t************************************************************\t\t\n\n");
	printf("\t\t\tWELCOME TO HANGMAN GAME\n\n");
	printf("\t************************************************************\t\t\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t Project By:-\n\n");
	printf("\t\t\t\t\t\t\t\t-Sajja Aryal\n");
	printf("\t\t\t\t\t\t\t\t-Anjita Poudel\n");
	printf("\t\t<Enjoy the game>\n\n");

	printf("\tPress ANY KEY to ENTER \n");
	exit = getchar();
}

void printMan(int tries)
{
    switch (tries)
    {
    case 0:
        printf("\n\n\n\n\n\n");
        break;
    case 1:
        printf("\n\n\n\n\n O\n");
        break;
    case 2:
        printf("\n\n\n\n\n O\n |\n");
        break;
    case 3:
        printf("\n\n\n\n\n O\n/|\n");
        break;
    case 4:
        printf("\n\n\n\n\n O\n/|\\\n");
               break;
    case 5:
        printf("\n\n\n\n\n O\n/|\\\n/\n");
        break;
    case 6:
        printf("\n\n\n\n\n O\n/|\\\n/ \\\n");
        break;
    }
}

void printWord(const char display[], const char used[])
{
    printf("\n\nCurrent word: ");
    for (int i = 0; i < strlen(display); i++)
    {
        printf("%c ", display[i]);
    }
    printf("\n\nUsed letters: ");
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(used[i]))
        {
            printf("%c ", used[i]);
        }
    }
    printf("\n\n\nGuess a letter: ");
}

int getGuess( char used[])
{
    char guess;
    int good_input = 0;
    while (!good_input)
    {
        scanf(" %c", &guess);
        guess = tolower(guess);
        if (isalpha(guess) && !strchr(used, guess))
        {
            good_input = 1;
        }
        else
        {
            printf("Re-entered letter, try other letter: ");

        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (used[i] == '\0')
        {
            used[i] = guess;
            break;
        }
    }
    return guess;
}
