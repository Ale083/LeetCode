#include <iostream>
using namespace std;

int main() {
    return 0;
}

int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        char currentChar = s[i];
        if(currentChar == 'M') {
            result += 1000;
        }
        else if(currentChar == 'C') {
            if(i+1 < s.size()) {
                if(s[i+1] == 'D') {
                    result += 400;
                    i++;
                } else if(s[i+1] == 'M') {
                    result += 900;
                    i++;
                } else {
                    result += 100;
                }
            } else {
                result += 100;
            }
        } else if(currentChar == 'D') {
            result += 500;
        } else if(currentChar == 'X') {
            if(i+1 < s.size()) {
                if(s[i+1] == 'L') {
                    result += 40;
                    i++;
                } else if(s[i+1] == 'C') {
                    result += 90;
                    i++;
                } else {
                    result += 10;
                }
            } else {
                result += 10;
            }
        } else if(currentChar == 'L') {
            result += 50;
        } else if(currentChar == 'I') {
            if(i+1 < s.size()) {
                if(s[i+1] == 'V') {
                    result += 4;
                    i++;
                } else if(s[i+1] == 'X') {
                    result += 9;
                    i++;
                } else {
                    result += 1;
                }
            } else {
                result += 1;
            }
        } else if(currentChar == 'V') {
            result += 5;
        }
    }
    return result;
}
