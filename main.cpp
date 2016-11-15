#include <iostream>
#include <string>
#include <vector>
#include "TextAnalyzer.h"

using namespace std;

void printVector(vector<string> vec) {
    int i = 0;
    int size = vec.size();
    for(i=0; i < size; i++) {
        cout << vec.at(i) << " " << endl;
    }
}

void taskFirst() {
    TextAnalyzer textAnalyzer = TextAnalyzer();
    textAnalyzer.setFilePath("/home/evgeny/ClionProjects/Lab6/text.txt");
    printVector(textAnalyzer.getWords());
}

void taskSecond() {

}

bool selectTask(int taskIndex) {
    switch (taskIndex) {
        case 1: taskFirst();
            break;
        case 2: taskSecond();
            break;
        case 0: return false;
        default: cout << "Cant execute this task" << endl; break;
    }
    cout << "\nEXECUTED\n" << endl;
    return true;
}

int main() {
    bool enabled = true;
    int index = 0;
    while(enabled) {
        cout << "Enter task number: " << endl;
        cin >> index;
        enabled = selectTask(index);
    }
    return 0;
}