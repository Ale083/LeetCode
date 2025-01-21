#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height);

int main() {

    return 0;
}

int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int max_area = 0;

    while(i<j) {
        int h = height[i] > height[j] ? height[j] * (j-i) : height[i] * (j-i);
        if(max_area < h) {
            max_area = h;
        }
        if(height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max_area;
}