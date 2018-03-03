//File Name: CountWords.cpp
//Author Name: Nathaniel Prakasam
//Student Code:  1541260
//Date: 1/18/2017
//Description/Documentation: 

//This program:
//creates a binary search tree, 
//takes text input through cin, 
//adds all valid words to the tree, using Add()
//outputs the number of words using NumWords() through cout
//and outputs the words in the tree and how many times they occur in the text, using the output stream operator. 
//Errors: Outputting an empty tree will yield "Tree is empty", Calling numwords on an empty tree will yield 0. 
//Valid Words: any consecutive string of letters with apostrophes inside. 

using namespace std;
#include "WordTree.h"

int main()
{	
     
    cout << "Hello, Please make your text entry: " << endl;//Welcome message :)
    

    int x = 5;//This is to create a scope within main to test the destructor before main returns. 
    if (x == 5)//
    {

        WordTree T;//Instantiates a tree. 
        
        //This is the section that processes input
        /////////////////////////////////////////////////////////////////////////////

        int asciiVal; //represents current ascii get value for assessment
        string curWord = ""; //Will be the word to get added by Add() and then reset to ""


        while (!cin.eof())//While still taking in input
        {
            asciiVal = cin.get();//After process for character is completed, go to next character


            if (!cin.good()) //Tests for end of input.
            {

                if (curWord != "")//if current word is not empty, and has reached the end of input.
                {
                    if (curWord.at(curWord.length() - 1) == 39)//if the word has an apostrophe at the back, remove it. 
                    {
                        curWord.erase(curWord.size()-1);
                    }
                    T.Add(curWord);//
                    curWord = "";
                }
                cout << "Done Adding" << endl;

                break;
            }

            if (asciiVal > 122 || asciiVal < 97)//If not a lowercase letter
            {

                if (asciiVal > 64 && asciiVal < 91) //If it's an uppercase letter, switch it to lowercase
                {
                    asciiVal = asciiVal + 32;
                    T.Initialize();//Since we have confirmed that there is at least one letter in the input 
                    

                    curWord += asciiVal; //append the value to the current word and loop to the beginning

                }
                else if (asciiVal == 39 && curWord != "")//if the character is an apostrophe
                {
                    if (curWord.at(curWord.length() - 1) == 39)//if the previous character was also an apostophe
                    {
                        curWord.erase(curWord.size() - 1);//Take out both apostrophes and add the word to tree
                        T.Add(curWord);

                        curWord = "";//reset the current wordd
                    }
                    else
                    {
                        curWord += asciiVal;

                    }
                }
                else if (curWord != "")//if current word exists, and non-lowercase character marks end of a word. 
                {
                    if (curWord.at(curWord.length() - 1) == 39)//if there's an apostrophe at the end of a word, take it out. 
                    {
                        curWord.erase(curWord.size() - 1);
                    }
                    T.Add(curWord);
                    curWord = "";//reset the current word
                }



            }
            else //It is confirmed to be a lowercase letter

            {
                T.Initialize();//Since we have confirmed that there is at least one letter in the input, 
                                //make sure there's an existing root since we know there's at least one word
                
                

                curWord += asciiVal;//add the value to the current string

                
            }
        }
        //////////////////////////////////////////////////////////////////////

        cout << "Number of words: " << T.NumWords() << endl;//Number message with numwords
        cout << T << endl;//stream output operator
        
        
    }
    //Destructor is invoked at this point because T has reached end of scope. 

    cout << "End of Program. Goodbye " << endl;
    return 0;
}