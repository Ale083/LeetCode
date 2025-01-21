#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x);

//Optimal-ish, best solution is to reverse the number and compare it to the original

int main() {
    cout << isPalindrome(321) << endl;
    cout << "----------------" << endl;
    cout << isPalindrome(32123) << endl;
    return 0;
}

bool isPalindrome(int x) {
    if(x<0) {
        return false;
    }
    if(x==0) {
        return true;
    }
    int digits = floor(log10(x)) + 1;
    int end = 1;
    int start = digits - 1;
    while(start>=end) {
        int startDig = (x / (int)pow(10, start));
        int endDig = (x % (int)pow(10,end))/ (int)pow(10, end-1);
        if(startDig != endDig) {
            cout << startDig << " " << endDig << endl;
            return false;
        }
        x -= startDig * (int)pow(10, start);
        x -= endDig * (int)pow(10, end-1);
        start--;
        end++;
        cout << x << endl;
    }
    return true;
}