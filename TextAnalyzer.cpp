#include <fstream>
#include <iostream>
#include <algorithm>
#include "TextAnalyzer.h"

void TextAnalyzer::setFilePath(string newFilePath) {
    filePath = newFilePath;
}

string TextAnalyzer::getFilePath() {
    return filePath;
}

vector<string> TextAnalyzer::getWords() {
    getWordsFromFile();
    return words;
}

void TextAnalyzer::getWordsFromFile() {
    ifstream readFile;
    string fileText;
    regex pattern("[^a-zA-Z\\d]");

    checkIsPathEmpty();
    readFile.open(filePath);
    while(readFile >> fileText) {
        fileText = replaceAll(pattern, fileText);
        if(find(words.begin(), words.end(), fileText) == words.end()) {
            words.push_back(fileText);
        }
    }
}

void TextAnalyzer::checkIsPathEmpty() {
    if(filePath.empty()) {
        cout << "\nfile path doesn't exist\n" << endl;
        throw exception();
        //return;
    }
}

string TextAnalyzer::replaceAll(regex pattern, string fileText) {
    stringstream result;
    regex_replace(ostream_iterator<char>(result), fileText.begin(), fileText.end(), pattern, "");
    return result.str();
}
