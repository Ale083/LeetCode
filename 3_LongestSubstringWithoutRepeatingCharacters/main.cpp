#include <iostream>
using namespace std;
#include <unordered_map>

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int maxLength = 0;
    int start = 0;
    for(int i=0; i<s.size();i++) {
        if(map.find(s[i]) != map.end() && map[s[i]] >= start) {
            start = map[s[i]] + 1;
        }
        map[s[i]] = i;
        if(i-start+1 > maxLength) {
            maxLength = i-start+1;
        }
    }
    return maxLength;
}

int main() {
    cout<< lengthOfLongestSubstring("abcabcbaed") << endl;

    return 0;
}