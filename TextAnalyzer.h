#include <string>
#include <vector>
#include <regex>

using namespace std;

class TextAnalyzer {
private:
    string filePath;
    vector<string> words;

    void checkIsPathEmpty();
    void getWordsFromFile();
    string replaceAll(regex pattern, string fileText);

public:
    string getFilePath();
    void setFilePath(string newFilePath);
    vector<string> getWords();
};