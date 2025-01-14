#include <iostream>
using namespace std;
#include <unordered_map>

//can be more efficient by using a sliding window approach, this is by
//having the hashmap be of char, last index. and saving a start and end of longest substring (window).

int lengthOfLongestSubstring(string s) {
    unordered_map<char, bool> map;
    int maxLength = 0;
    int currentLength = 0;
    for(int i=0; i<s.size();i++) {
        if(map[s[i]]) {
            if(currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0;
            map.clear();
            char dup = s[i--];
            while(s[i] != dup) {
                i--; //go back to the last character until it finds the index of the one duplicated.
            }
        } else {
            currentLength++;
            map[s[i]] = true;
        }
    }

    if(currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}
int main() {
    cout<< lengthOfLongestSubstring("abcabcbaed") << endl;

    return 0;
}


/*
*for(char c : s) {
        if(map[c]) {
            cout << "maxLength: " << maxLength << " currentLength: " << currentLength << endl;
            if(currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
            map.clear();
            map[c] = true;
        } else {
            currentLength++;
            cout << "currentLength: " << currentLength << endl;
            map[c] = true;
        }
    }
 *
 */