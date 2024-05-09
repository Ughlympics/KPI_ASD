#include <iostream>
#include <string>

using namespace std;

void capitalizeWordsStartingWith(char letter, string& text) {
    bool capitalizeNext = true;

    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == ' ') {
            capitalizeNext = true;
        }
        else if (capitalizeNext && tolower(text[i]) == tolower(letter)) {
            text[i] = toupper(text[i]);
        }

        capitalizeNext = true;
    }
}

void addExclamationToWordsWithOddLength(string& text) {
    bool inWord = false;

    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            if (!inWord) {
                inWord = true;
                if (text.substr(i, 2) != " ") {
                    int wordLength = 0;
                    int j = i;
                    while (j < text.length() && isalpha(text[j])) {
                        ++wordLength;
                        ++j;
                    }
                    if (wordLength % 2 != 0) {
                        text.insert(j, "!");
                    }
                }
            }
        }
        else {
            inWord = false;
        }
    }
}

int main() {
    char startingLetter;
    string text;

    cout << "Enter a letter: ";
    cin >> startingLetter;
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, text);

    capitalizeWordsStartingWith(startingLetter, text);
    addExclamationToWordsWithOddLength(text);
    


    cout << "Modified text: " << text << endl;

    return 0;
}