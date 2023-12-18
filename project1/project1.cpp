#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

int countPunctuation(const string& text) {
    int count = 0;
    for (char c : text) {
        if (ispunct(c)) {
            ++count;
        }
    }
    return count;
}

void printEvenWords(const string& text) {
    stringstream ss(text); // дозволяє робити операції введення та виведення 
    string word;
    while (ss >> word) {
        if (word.length() % 2 == 0) {
            cout << word << endl;
        }
    }
}

string swapFirstAndLast(const string& word) {
    if (word.length() < 2) {
        return word;
    }
    return word.substr(1) + word.front();
}

void processFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in.is_open()) {
        cout << "Error: Unable to open the file" << endl;
        return;
    }
    if (!out.is_open()) {
        cout << "Error: Unable to create the file" << endl;
        return;
    }

    string text;
    while (getline(in, text)) { // getline для зчитування
        int punctuationCount = countPunctuation(text);
        cout << "Punctuation count: " << punctuationCount << endl;
        printEvenWords(text);
        cout << endl;
        stringstream wordStream(text); // для подальшої обробки
        string word;
        while (wordStream >> word) {
            cout << swapFirstAndLast(word) << " ";
        }

        cout << endl << endl;
    }
    in.close();
    out.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    processFile(inputFile, outputFile);
    return 0;
}

