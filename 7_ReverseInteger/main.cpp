#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x);

int main() {
    // cout << reverse(219) << endl;
    cout << reverse(0) << endl;
    // cout << reverse( 190042) << endl;
    return 0;
}

int reverse(int x) {
    if (x == 0 || x == INT_MIN) { return 0; }

    bool negative = false;
    if (x < 0) {
        negative = true;
        x = abs(x);
    }
    int digits = floor(log10(x)) + 1;
    if (x % 10 > 2 && digits == 10) {
        return 0;
    }
    int result = 0;
    int multiplier = 0;

    for (int i = digits - 1; i >= 0; i--) {
        int suma = (x / (int) pow(10, i)) * (int) pow(10, multiplier);
        if (result > INT_MAX - suma) {
            return 0;
        }
        result += suma;
        x = x % (int) pow(10, i);
        multiplier++;
    }
    if (negative) {
        result = -result;
    }
    return result;
}
