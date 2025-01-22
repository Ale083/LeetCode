#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main()
{
    return 0;
}

string longestCommonPrefix(vector<string>& strs) {
    int size = strs.size();
    if (size == 1) return strs[0];
    string firstWord = strs[0];
    string prefix = "";
    for(int i = 0; i < firstWord.size();i++) {
        char c = firstWord[i];
        for(int j = 1; j < size; j++) {
            try {
                if (strs[j][i] != c) {
                    return prefix;
                }
            } catch (...) {
                return prefix;
            }
        }
        prefix += c;
    }
    return prefix;
}
