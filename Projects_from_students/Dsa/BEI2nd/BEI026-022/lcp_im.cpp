#include <unordered_map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdbool>
#include <fstream>


// #include <termios.h>
// #include <unistd.h>


using namespace std;


#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

/*
 * 
 *
 *
 * LCP 
 *
 *
 * */
struct trie_word
{
	bool wordState;
	unordered_map<char, trie_word*> character;

	trie_word() {
		wordState = 0;
	}
};

void insert(trie_word* root, std::string str)
{

	trie_word* temp = root;
 
	for (char char_val: str)
	{
		
		if (temp -> character . find(char_val) == temp -> character . end()) {
			temp -> character[char_val] = new trie_word();
		}
 
		temp = temp -> character[char_val];
	}
 
	temp -> wordState = true;
}
 

std::string findLCP(vector<std::string> dict)
{

	trie_word* head = new trie_word();
	
	for (std::string s: dict) {
		insert(head, s);
	}

	std::string lcp;
	
	trie_word* temp = head;
 
	// Loop only if wordState = true || node has > 1 child
	while (temp && !temp -> wordState && (temp -> character.size() == 1))
	{
		// Assign iterator unordered_map
		auto i = temp -> character.begin();
 

		lcp += i -> first; // Add to current charVal
 

		temp = i -> second;
	}
 
	return lcp;
}

/*
 *
 * LCP
 *
 *
 * */


/*
 *
 * Autocomplete
 *
 * */


 
struct compl_trie {
	
	struct compl_trie* kids[52];
 
	bool word_end;
};
 
struct compl_trie* getNode(void)
{
	struct compl_trie* new_node = new compl_trie;
	new_node -> word_end = false;
 
	for (size_t i = 0; i < 52; ++i)
		new_node -> kids[i] = NULL;
 
	return new_node;
}
 
void ins_auto(struct compl_trie* root, const std::string key_val)
{
	struct compl_trie* traverse_node = root;
 
	for (size_t lvl = 0; lvl < key_val . length(); ++lvl) {
		int index = CHAR_TO_INDEX(key_val[lvl]);
		if (!traverse_node -> kids[index])
			traverse_node -> kids[index] = getNode();
 
		traverse_node = traverse_node -> kids[index];
	}
	traverse_node -> word_end = true;
}
 
bool isLeaf(struct compl_trie* root)
{
	for (size_t i = 0; i < 52; ++i)
		if (root -> kids[i])
			return 0;
	return 1;
}
 
void compl_oper(struct compl_trie* root, std::string currPrefix)
{
	if (root -> word_end)
		std::cout << currPrefix << endl;
 
	for (size_t i = 0; i < 52; ++i)

		if (root -> kids[i]) {
	  
			char child = 'a' + i;
			compl_oper(root -> kids[i], currPrefix + child);
		}
}
 
int compl_io(compl_trie* root, const std::string query)
{
	struct compl_trie* traverse_node = root;
	for (char c : query) {
		int ind = CHAR_TO_INDEX(c);
 
		if (!traverse_node->kids[ind])
			return 0;
 
		traverse_node = traverse_node->kids[ind];
	}
	if (isLeaf(traverse_node)) {
		std::cout << query << endl;
		return -1;
	}
	compl_oper(traverse_node, query);
	return 1;
}





/*
 *
 * Autocomplete
 *
 * */




/*

  Set terminal attributes for better user experience

 */


int main(int argc, char **argv)
{

	std::string choice;

coolLoop:

	std::cout<<"\nAutocomplete(1) or LCP(2) ? -> ";
	std::cin>>choice;

	if (choice == "2") {
		
		vector<std::string> word_l;	// Keys

		std::string str_Val, filename;
		fstream file;
	
		filename = "wordList.txt";


		file.open(filename . c_str());
		while(file >> str_Val) {
			word_l.push_back(str_Val);
		}
		std::cout <<std::endl<<"LCP: " << findLCP(word_l)<<"\n";
	}
	else if(choice == "1") {

		struct compl_trie* root = getNode();
		std::string fileWord, fileName;
		fstream file;
		fileName = "dictionary.txt";
		file.open(fileName . c_str());
		while(file >> fileWord) {
			ins_auto(root, fileWord);
		}
		std::string termCap;
		std::cout<<"Insert word for auto complete suggestion: ";
		std::cin>> termCap;
		int comp = compl_io(root, termCap);

		if (comp == -1 || comp == 0)
			std::cout << "Match not found\n";
 
		return 0;
	}
	else {
		fputs("The choices are limited you know!!!!\n", stdout);
		goto coolLoop;
	}
	
	
	return 0;
}
