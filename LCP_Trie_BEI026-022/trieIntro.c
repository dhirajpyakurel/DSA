#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define NUM_CHARS 26

/* Defines tree and children */
typedef struct trie {

	struct trie* children[NUM_CHARS]; /* Pointer to children actually */
	bool word_State;
}trie;


/* Returns pointer to created node */
struct trie *give_me_node ()
{
	struct trie* new_node = (struct trie *) malloc(sizeof(struct trie));

	if(new_node)
		new_node -> word_State = false;

	for(int i = 0; i < NUM_CHARS; ++i)
		new_node -> children[i] = NULL;

	return new_node;
}


/* Using pointer to root so as to be able to change node and not its copy */

void insert_trie (struct trie *root_Node, char *str)
{
	struct trie *temp_node = root_Node;
	while(*str)
	{
		if(temp_node -> children[*str - 'a'] == NULL)
			temp_node -> children[*str - 'a'] = give_me_node();

		temp_node = temp_node -> children[*str - 'a'];

		str++;
	}

	temp_node -> word_State = true; // Leaf node is a word!
}


bool search_tree(struct trie *root_Node, char* str)
{
	if(root_Node == NULL) {
		printf("Empty tree. Nothing to search!!\n");
		return 0;
	}

	struct trie *temp = root_Node;
	while(*str) {
		temp = temp -> children[*str - 'a'];
		if(temp == NULL)
			return 0; /* This means end of the path in trie */

		str++;
	}
	return (temp -> word_State);
}

/* Checks if the given node has a children further */
bool tree_has_children(struct trie* temp_node)
{
	for (int i = 0; i < NUM_CHARS; ++i) {

		if(temp_node -> children[i])
			return true; /* child exists */
	}
}

/* Using recursion to delete the whole word, not just 1 node */

//Insert delete function




/* This ia a lemma function for traverse function */
bool is_leaf(struct trie *root)
{
	return (root -> word_State != false); /* Returns true if word state is != false or 0 */
}

/* Recurcive function to show tree nodes in succession */
void traverse(struct trie *root, char *str, int level)
{
	if(is_leaf(root)){
		
		str[level] = '\0'; /* Displaying NULL terminator for a word end */
		printf("%s", *str);
	}

	for(int i = 0; i < NUM_CHARS; ++i) {
	  if(root -> children[i]) {

	    		str[level] = 'a' + i;
			traverse(root -> children[i], str, level++);
			level--;
			
	  }
	}
}



int main(int argc, char *argv[])
{
	int choice;
	char words[36], s_string[36];
	struct trie* head = give_me_node();

omg:
	printf("\nEnter your word: ");
	scanf("%s", &words);
	insert_trie(head, words);

	printf("Do you want to insert more words? 1 for yes 0 for no: ");
	scanf("%d", &choice);

	if(choice == 1)
		goto omg;
	else
		printf("\nOk, no more words for now!\n");
search_again:
	printf("Enter the word to search: ");
	scanf("%s", &s_string);

	printf("%s", (search_tree(head, s_string)) ? "true" : "false");
	printf("\n");
	printf("Do you want to search again? 1 for yes 0 for no: ");
	scanf("%d", &choice);
	if(choice == 1)
		goto search_again;
	else {
		printf("\nDo you want to print the tree? 1 for yes and 0 for no: ");
		scanf("%d", &choice);
		if(choice == 1)
			traverse(head, words, 0); /* initial level is 0 */
		else
			exit(0);
	}
	return 0;
}
