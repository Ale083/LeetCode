#include <iostream>
using namespace std;

string intToRoman(int num);

int main() {

    return 0;
}

/*
Para tener a mano
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
1>=num<=3999
*/

string intToRoman(int num) {
    int i = 3;
    string roman = "";
    for(int j=0; j<num/1000; j++) {
        roman += "M";
    }

    int n = (num / 100) % 10;
    if(n==4) {
        roman += "CD";
    } else if(n==9) {
        roman += "CM";
    } else {
        if(n>=5) {
            roman += "D";
            n -= 5;
        }
        roman += string(n, 'C');
    }

    n = (num / 10) % 10;
    if(n==4) {
        roman += "XL";
    } else if(n==9) {
        roman += "XC";
    } else {
        if(n>=5) {
            roman += "L";
            n -= 5;
        }
        roman += string(n, 'X');
    }

    n = num % 10;
    if(n==4) {
        roman += "IV";
    } else if(n==9) {
        roman += "IX";
    } else {
        if(n>=5) {
            roman += "V";
            n -= 5;
        }
        roman += string(n, 'I');
    }
    return roman;
}