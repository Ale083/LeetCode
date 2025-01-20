#include <iostream>
#include <cmath>
using namespace std;

int myAtoi(string s);
int stoi(string s, bool neg);

int main() {
    cout << myAtoi("-2147483647") << endl;
    cout << "----------------" << endl;
    // cout << myAtoi("42") << endl;
    // cout << "----------------" << endl;
    // cout << myAtoi("1337c0d3") << endl;
    return 0;
}

int myAtoi(string s) {
    int step = 1;
    bool negative = false;
    string strRes = "";
    for(char c : s) {
        switch(step) {
            case 1:
                if(c == ' ') {
                    continue;
                }
                if(c == '+') {
                    step = 2;
                    continue;
                }
                if (c == '-') {
                    negative = true;
                    step = 2;
                    continue;
                }
                if(isdigit(c)){
                    step = 2;
                }else{
                    return 0;
                }
            case 2:
                if(isdigit(c)) {
                    strRes += c;
                } else {
                    step = 3;
                }
        }
        if(step == 3) {
            break;
        }
    }
    cout << strRes << endl;
    return stoi(strRes, negative);
}

int stoi(string s, bool neg) {
    int result = 0;
    int exponente = 0;
    for(int i = s.size()-1;i>=0;i--) {
        int num = s[i] - '0';
        int suma =  num * pow(10, exponente);
        if(result > INT_MAX - suma) {
            if(neg){
                return INT_MIN;
            }
            return INT_MAX;
        }
        if(result == INT_MAX - suma && neg) {
            return INT_MIN +1;
        }
        result += suma;
        exponente++;
    }
    if(neg) {
        return result * -1;
    }
    return result;
}