//File Name: WordTree.cpp
//Author Name: Nathaniel Prakasam
//Student Code:  1541260
//Date: 1/18/2017
//Description: implementation for WordTree and WordNode functions. 



#include "WordTree.h"


//Constructor: Has no function other than to instantiate the WordTree
WordTree::WordTree()
{
	cout << "THIS IS WORKING OK" << endl;
}

//Destructor: Checks if root is NULL and calls its private recursive function DestructorHelper() if not.
// If so, it does nothing since there is nothing to deallocate. 
WordTree::~WordTree()
{
    if (root != NULL)//if there is at least one node in the tree
    {
        DestructorHelper(root);
    }
}

//DestructorHelper: private recursive function that visits every node in the tree.
//Goes in Post-order traversal. WordNode is a parameter passed in. 
//Root is initially passed in. If its left or right child exists, it recurses to that node
void WordTree::DestructorHelper(WordNode * current)
{
    
    if (current->left != NULL)
    {
        DestructorHelper(current->left);
    }
    if (current->right != NULL)
    {
        DestructorHelper(current->right);
    }
    
    delete current;
    current = NULL;

}

//Add: A method to access its private recursive function AddSeparate(string e, WordNode* current)
// It takes a const string as a parameter which is confirmed to be a valid word. 
void WordTree::Add(const string newWord,  string first, string numeral)
{
    AddSeparate(newWord,first, numeral, root);
}

void WordTree::Add(const string actor, const string movie)
{
	AddSeparate(actor, movie, root);
}

void WordTree::AddSeparate(string newWord, string movie, WordNode* current)
{
	if (current->word == "")//if current has no word
	{
		current->word = newWord;
		
	}
	else
	{

		if (newWord.compare(current->word) == 0)//If the actoralready exist
		{
			if (movie != "NoMovie")
			{
				AddMovie(movie, current);
			}
		}
		else if (newWord.compare(current->word) < 0)//if word is higher up alphabetically
		{
			if (current->left == NULL)//if there is no existing left node, make one
			{
				current->left = new WordNode;

			}
			AddSeparate(newWord, movie, current->left); //go to left node and repeat process
		}
		else if (newWord.compare(current->word) > 0)//if word is lower alphabetically
		{
			if (current->right == NULL)//if there is no existing left node, make one
			{
				current->right = new WordNode;

			}
			AddSeparate(newWord, movie, current->right); //go to left node and repeat process
		}

	}

}


void WordTree::AddMovie(string movie, WordNode* cur)
{

	cur->movies[cur->numMovies] = movie;
	cur->numMovies++;

}
//AddSeparate: Private recursive function of add.
//Takes in a string and finds the correct spot in the tree to add it. 
void WordTree::AddSeparate(string newWord, string first,string numeralI, WordNode* current)
{
    if (current->word == "")//if current has no lastname
    {
        current->word = newWord;
		current->firstN = first;
		current->numeral = numeralI;
    }
    else
    {
        
        if (newWord.compare(current->word) == 0)//If the last names are equal
        {
			if (current->firstN == "")//if current has no FirstName
			{
				current->firstN = first;
				current->numeral = numeralI;
			}
			else
			{
				if (first.compare(current->firstN) == 0)//same first name, then compare numberals 
				{
					if (current->numeral == "")//if current has no numeral
					{
						current->numeral = numeralI;
					}
					else
					{
						 if (numeralI.compare(current->numeral) < 0)//if word is higher up alphabetically
						{
							if (current->left == NULL)//if there is no existing left node, make one
							{
								current->left = new WordNode;

							}
							AddSeparate(newWord, first, numeralI, current->left); //go to left node and repeat process
						}
						else if (numeralI.compare(current->numeral) > 0)//if word is lower alphabetically
						{
							if (current->right == NULL)//if there is no existing left node, make one
							{
								current->right = new WordNode;

							}
							AddSeparate(newWord, first, numeralI, current->right); //go to left node and repeat process
						}

					}
				}
				else if (first.compare(current->firstN) < 0)//if first is higher up
				{
					if (current->left == NULL)//if there is no existing left node, make one
					{
						current->left = new WordNode;

					}
					AddSeparate(newWord, first, numeralI, current->left); //go to left node and repeat process
				}
				else if (first.compare(current->firstN) > 0)//if word is lower alphabetically
				{
					if (current->right == NULL)//if there is no existing left node, make one
					{
						current->right = new WordNode;
					}
					AddSeparate(newWord, first, numeralI, current->right); //go to left node and repeat process
				}

			}
        }
        else if (newWord.compare(current->word) < 0)//if word is higher up alphabetically
        {
            if (current->left == NULL)//if there is no existing left node, make one
            {
                current->left = new WordNode;

            }
            AddSeparate(newWord, first, numeralI, current->left); //go to left node and repeat process
        }
        else if (newWord.compare(current->word) > 0)//if word is lower alphabetically
        {
            if (current->right == NULL)//if there is no existing left node, make one
            {
                current->right = new WordNode;

            }
            AddSeparate(newWord, first, numeralI, current->right); //go to left node and repeat process
        }

    }


}


//Initialize: initializes root node to receive a word, 
//makes a node pointer for root
void WordTree::Initialize()
{
    if (root == NULL)//Since we have confirmed that there is at least one letter in the input 
    {
        root = new WordNode;//If root doesn't exist, make it
    }
}

//NumWords: returns an int which represents the number of wordNodes in the tree. 
//If the root is null, we can assume the int is 0 so that is returned.
//otherwise, it calls its private recursive function NumWordsRecurse
int WordTree::NumWords()
{
    if (root == NULL)
    {
        return 0;//No words in the tree
        }
    
    return NumWordsRecurse(0, root);
}

//NumWordsRecurse: Takes in an int (count) and a wordnode. 
//Pre-order traversal of every node in tree. 
//Initially passes 0 and increments everytime a node is shown to not be null. 
//Returns total count of words to NumWords
int WordTree::NumWordsRecurse(int count, const WordNode * current) 
{
    count++;
    if (current->left != NULL)
    {
        count = NumWordsRecurse(count, current->left); //passes incremented count
    }
    if (current->right != NULL)
    {
        count = NumWordsRecurse(count, current->right);//passes incremented count
    }
    return count;
}


//Output helper: Takes in a const Wordnode and processes output in 
//inorder traversal. Visits every node in the tree that is not null. Outputs to cout
//private recursive function of outputstream
void WordTree::OutputHelper( const WordNode * current)
{
    if (current->left != NULL)
    {
        OutputHelper(current->left);
    }

    cout << current->word << " " <<  current->baconNumber<< endl;//Puts a space in between word and number
    if (current->right != NULL)
    {
        OutputHelper(current->right);
    }
}



// Output Stream Operator: Outputs the words of the nodes in tree. takes in an ostream and WordTree 
// Checks if root is NULL and outputs a header message for the following words and numbers if not.
//If so, it outputs that tree is empty
ostream & operator<<( ostream & os,  WordTree & dt)
{
    if (dt.root != NULL)
    {
        cout << "Word/Bacon Number" << endl;
        dt.OutputHelper(dt.root);
    }
    else
    {
        cout << "Tree is empty" << endl;

    }
    return os;
}

