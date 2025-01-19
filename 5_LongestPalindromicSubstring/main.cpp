#include <iostream>
#include <unordered_map>
using namespace std;

string longestPalindrome(string s);
bool isPalindrome(string s);

int main() {
    cout << longestPalindrome("a") << endl;
    cout << longestPalindrome("aba") << endl;
    cout << longestPalindrome("abaa") << endl;
    cout << longestPalindrome("cbbc") << endl;
    return 0;
}


string longestpalindrome(string s) {
    unordered_map<char, int> map;
    int indexStartPalindrome = 0;
    int lengthPalindrome = 0;
    int start = 0;
    for(int i=0; i<s.size();i++) {
        if(map.find(s[i]) != map.end() && map[s[i]] >= start && isPalindrome(s.substr(map[s[i]],i-map[s[i]]+1))) {
            start = map[s[i]] + 1;
            string ss = s.substr(map[s[i]],i-map[s[i]]+1);
            indexStartPalindrome = map[s[i]];
            lengthPalindrome = i-map[s[i]]+1;
        }
        map[s[i]] = i;
    }
    if(lengthPalindrome == 0){return s.substr(0,1);}
    return s.substr(indexStartPalindrome,lengthPalindrome);
}

string longestPalindrome(string s) {
    if(s.size() == 1) {
        return s;
    }
    int maxLength = 0;

    string longestPalindrome = "";
    for(int i=1; i<s.size();i++) {
        int previous = i-1;
        int next = i+1;
        int currentSize = 1;
        while(previous >= 0 && next < s.size()) {
            if(s[previous] != s[next]) {

                break;
            }
            currentSize += 2;
            if(currentSize > maxLength) {
                maxLength = currentSize;

                longestPalindrome = s.substr(previous,maxLength);
            }
            previous--;
            next++;
        }


        previous = i-1;
        next = i;
        currentSize = 0;
        while(previous >= 0 && next < s.size()) {
            if(s[previous] != s[next]) {

                break;
            }
            currentSize += 2;
            if(currentSize > maxLength) {
                maxLength = currentSize;

                longestPalindrome = s.substr(previous,maxLength);
            }
            previous--;
            next++;
        }
    }
    if(maxLength == 0) {
        return s.substr(0,1);
    }
    return longestPalindrome;
}


bool isPalindrome(string s) {
    int start = 0;
    int end = s.size()-1;
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

