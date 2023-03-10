#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

void HandleInput(int argc, char *argv[]);
void PrintHelp();
void CalculateWordFrequency(char *argv[], vector<string> &words, map<string, int> &wordFreq);
void GetWords(string fileName, vector<string> &words);
void GetFileContent(string fileName, string &fileContent);
void PrintSortedMap(map<string, int> map);
bool compareByValue(const pair<string, int> &a, const pair<string, int> &b);

int main(int argc, char *argv[])
{
    HandleInput(argc, argv);
    return 0;
}

void HandleInput(int argc, char *argv[])
{
    string InputLowered(argv[1]);
    transform(InputLowered.begin(), InputLowered.end(), InputLowered.begin(), ::tolower);

    if (argc < 2)
    {
        PrintHelp();
        return;
    }

    // Check for Help Command
    if (InputLowered == "-h" || InputLowered == "--help")
    {
        PrintHelp();
        return;
    }
    else if (InputLowered == "-v" || InputLowered == "--version")
    {
        cout << "Version: 1.0.0" << endl;
        return;
    }
    else if (InputLowered == "-i" || InputLowered == "--input")
    {
        if (argv[2] == NULL)
        {
            PrintHelp();
            return;
        }

        vector<string> words;
        map<string, int> wordFreq;
        CalculateWordFrequency(argv, words, wordFreq);
        PrintSortedMap(wordFreq);
    }
    else
    {
        PrintHelp();
    }
}

void PrintHelp()
{
    cout << "-h, --help     | Displays a this Help Message" << endl;
    cout << endl;
    cout << "-v, --version  | Shows the current Version" << endl;
    cout << endl;
    cout << "-I             | Usage: main.exe -I [FileName] | Example: main.exe file.txt" << endl;
}

void CalculateWordFrequency(char *argv[], vector<string> &words, map<string, int> &wordFreq)
{
    GetWords(argv[2], words);
    for (const string word : words)
    {
        if (wordFreq.find(word) == wordFreq.end())
        {
            wordFreq[word] = 1;
        }
        else
        {
            wordFreq[word]++;
        }
    }
}

void GetWords(string fileName, vector<string> &words)
{
    string fileContent;
    GetFileContent(fileName, fileContent);
    stringstream stream(fileContent);
    string word;

    while (stream >> word)
    {
        words.push_back(word);
    }
}

void GetFileContent(string fileName, string &fileContent)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        throw runtime_error("File could not be opened.");
    }

    string line;
    while (getline(file, line))
    {
        fileContent.append(line + " ");
    }
    file.close();
}

void PrintSortedMap(map<string, int> map)
{
    vector<pair<string, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), compareByValue);

    for (const auto &kv : vec)
    {
        cout << kv.first << " - " << kv.second << endl;
    }
}

bool compareByValue(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second < b.second;
}
