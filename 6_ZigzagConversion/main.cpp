#include <iostream>
using namespace std;


int main() {
    return 0;
}

string convert(string s, int numRows) {
    if(numRows == 1) {
        return s;
    }
    string rows[numRows];
    int i = 0;
    int n = 1;
    for(char c : s) {
        if(i == numRows-1) {
            n=-1;;
        } else if (i == 0) {
            n = 1;
        }
        rows[i] += c;
        i += n;
    }
    string result = "";
    for(string row : rows) {
        result += row;
    }
    return result;
}