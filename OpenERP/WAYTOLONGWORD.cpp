#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> change_to_long_word(vector<string> words, int n)
{
    string word;
    int len;
    for(int i = 0; i < n; i++)
    {
        word = words[i];
        len = word.length();
        if(len > 10)
        {
            word = word[0] + to_string(len - 2) + word[len-1];
            words[i] = word;
        }
    }

    return words;
}

void print_words(vector<string> words, int n)
{
    for(int i = 0; i < n; i++)
        cout << words[i] << endl;
}

int main() {
    int n;
    vector<string> words;
    string word;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        words.push_back(word);
    }
    words = change_to_long_word(words, n);
    print_words(words, n);
    return 0;
}