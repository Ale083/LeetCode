#include <iostream>
using namespace std;

//Too unoptimal, there are certain cases it will just give time limit exceeded.

bool isMatch(string s, string p);
int ast(string s, char c);

int main() {
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aa", "a*") << endl;

    return 0;
}

bool isMatch(string s, string p){
    // int i = 0;
    // int j = 0;
    while(0 < s.size() && 0 < p.size()) {
        if(s[0] == p[0] || p[0] == '.') {
            if(p.size() >= 2 && p[1] == '*') {
                if (isMatch(s, p.substr(2))) return true;
                s = s.substr(1);
            } else {
                s = s.substr(1);
                p = p.substr(1);
            }
            continue;
        }
        else if(p.size() >= 2 && p[1] == '*') {
            p = p.substr(2);
            continue;
        } else {
            cout << s << " " << p << endl;
            return false;
        }
    }
    while (p.size() >= 2 && p[1] == '*') {
        p = p.substr(2);
    }
    return s.empty() && p.empty();;
}

