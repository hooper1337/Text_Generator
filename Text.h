#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

class inputOutputText
{
private:
    string text;
    string output[10];
public:
    inputOutputText(string t="NULL", int o=0): text(t){}
    void receiveInput();
    string ironicText();
    string capitalLetter();
    string lowerLetter();
    void showResults();
};

void inputOutputText::receiveInput()
{
    cout << "\nWrite your initial sentence/text!\n" << endl << ">";
    getline(cin, text);
    
    if(text == "end")
        exit(EXIT_SUCCESS);
        
    output[0] = ironicText();
    output[1] = capitalLetter();
    output[2] = lowerLetter();
    return;
}

string inputOutputText::ironicText()
{
    text[0] = tolower(text[0]);
    for(int i=1; i<text.length(); i++)
    {
        if(islower(text[i-1]))
            text[i] = toupper(text[i]);
        else
            text[i] = tolower(text[i]);    
    }
    return text;
}

string inputOutputText::capitalLetter()
{
    for(int i=0; i<text.length(); i++)
        text[i] = toupper(text[i]);
    return text;
}

string inputOutputText::lowerLetter()
{
    for(int i=0; i<text.length(); i++)
        text[i] = tolower(text[i]);
    return text;
}

void inputOutputText::showResults()
{
    cout << "\n\nRESULTS!\n";
    cout << "\nIronic text\n\n" << output[0] << endl << endl;
    cout << "--------------";
    cout << "\n\nFull capital letter\n\n" << output[1] << endl << endl;
    cout << "--------------";
    cout << "\n\nFull lower letter\n\n" << output[2] << endl;
}
