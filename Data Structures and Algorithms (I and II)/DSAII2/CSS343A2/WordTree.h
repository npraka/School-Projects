//File Name: WordTree.h
//Author Name: Nathaniel Prakasam
//Student Code:  1541260
//Date: 1/18/2017
//Description: Declaration for WordTree and WordNode functions/variables. 



#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class WordTree
{
    
public:
    
    //Constructor: Has no function other than to instantiate the WordTree
    WordTree();

    //Destructor: Checks if root is NULL and calls its private recursive function DestructorHelper() if not.
    // If so, it does nothing since there is nothing to deallocate. 
    ~WordTree();
    
    //Add: A method to access its private recursive function AddSeparate(string e, WordNode* current)
    // It takes a const string as a parameter which is confirmed to be a valid word. 
    void Add(const string newWord,  string first,  string numeral);


	void Add(const string actor, const string movie);

    //NumWords: returns an int which represents the number of wordNodes in the tree. 
    //If the root is null, we can assume the int is 0 so that is returned.
    //otherwise, it calls its private recursive function NumWordsRecurse
    int NumWords();
    
    //Initialize: initializes root node to receive a word, 
    //makes a node pointer for root
    void Initialize(); 

    // Output Stream Operator: Outputs the words of the nodes in tree
    // Checks if root is NULL and outputs a header message for the following words and numbers if not.
    //If so, it outputs that tree is empty
    friend ostream& operator<<(ostream& os, WordTree& dt);
    
    
private:
    
    struct WordNode{
        
        //the word string stored by the node
        string word="";
		string firstN = "";
		string numeral = "";
		string movies[100];
		int numMovies=0;
        //Number of times the word occurs 
        int baconNumber=0;
        
        //left and right nodes as subtrees
        WordNode* left=NULL;
        WordNode* right=NULL;

        //WordNode convenience constructor along with an initialization list
        WordNode() : word("") , baconNumber(0), left(NULL), right(NULL) {};
    };
    //root node: which is the only private data member of WordTree. 
    WordNode *root=NULL;

	void AddMovie(string movie, WordNode* cur);
    //AddSeparate: Private recursive function of add.
    //Takes in a string and finds the correct spot in the tree to add it. 
	void AddSeparate(string newWord,  string first,string numeral, WordNode* current);

	void AddSeparate(string e, string movie, WordNode* current);



    //Output helper: Takes in a const Wordnode and processes output in 
    //inorder traversal. Visits every node in the tree that is not null. Outputs to cout
    //private recursive function of outputstream
    void OutputHelper(const WordNode* current);

    //DestructorHelper: private recursive function that visits every node in the tree.
    //Goes in Post-order. WordNode is a parameter passed in. 
    //Root is initially passed in. If its left or right child exists, it recurses to that node
    void DestructorHelper(WordNode* current);
    
    //NumWordsRecurse: Takes in an int (count) and a wordnode. 
    //Pre-order traversal of every node in tree. 
    //Initially passes 0 and increments everytime a node is shown to not be null. 
    //Returns total count of words to NumWords
    int NumWordsRecurse(int count, const WordNode* current);
};


//TODO: remember to unbitify after all implementation