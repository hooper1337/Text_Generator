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
    int opt;
    string output[10];
public:
    inputOutputText(string t="NULL", int o=0): text(t), opt(o){}
    void receiveInput();
    string ironicText();
};

void inputOutputText::receiveInput()
{
    cout << "\nWrite your initial sentence/text!\n";
    while(1)
    {
        getline(cin, text);

        if(text == "end")
            exit(EXIT_SUCCESS);
        
        cout << "\nWhat type of text do you want?\n";
        cin >> opt;

        if(opt == 1)
            output[0] = ironicText();

        cout << output[0];
    }
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
