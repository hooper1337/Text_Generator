#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <bits/stdc++.h>
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
    string stringToBinary();
    void showResults();
};

void inputOutputText::receiveInput()
{
    cout << "\nTEXT GENERATOR\n\n";
    cout << "\nWrite end to close the program!\n";
    while(text != "end")
    {
    cout << "\nWrite your initial sentence/text!\n" << endl << ">";
    getline(cin, text);
    
    if(text == "end")
        exit(EXIT_SUCCESS);
        
    output[0] = ironicText();
    output[1] = capitalLetter();
    output[2] = lowerLetter();
    output[3] = stringToBinary();
    showResults();
    }
    exit(EXIT_SUCCESS);
}

string inputOutputText::ironicText()
{
    int n = text.length();
    text[0] = tolower(text[0]);

    for(int i=1; i<n; i++)
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
    int n = text.length();

    for(int i=0; i<n; i++)
        text[i] = toupper(text[i]);
    return text;
}

string inputOutputText::lowerLetter()
{
    int n = text.length();

    for(int i=0; i<n; i++)
        text[i] = tolower(text[i]);
    return text;
}

string inputOutputText::stringToBinary()
{
    int n = text.length();
    string bin = "";

    for(int i=0; i<=n; i++)
    {
        int val = int(text[i]);
        while(val > 0)
        {
            (val % 2) ? bin.push_back('1'):
                        bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
    }
    return bin;
}

void inputOutputText::showResults()
{
    cout << "\n\nRESULTS!\n";
    cout << "\nIronic text\n\n" << output[0] << endl << endl;
    cout << "--------------";
    cout << "\n\nFull capital letter\n\n" << output[1] << endl << endl;
    cout << "--------------";
    cout << "\n\nFull lower letter\n\n" << output[2] << endl << endl;
    cout << "--------------";
    cout << "\n\nBinary\n\n" << output[3] << endl << endl;
}
