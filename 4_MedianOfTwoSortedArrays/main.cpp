#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2);
double medianSortedArray(vector<int>& arr);
int max(int n1, int n2);

int main() {
    std::vector<int> arr1; // Empty array
    std::vector<int> arr2 = {1}; // Array with one element

    double median = findMedianSortedArrays(arr1, arr2);

    std::cout << "Median: " << median << std::endl;
    return 0;
}

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2){
    int s1 = arr1.size();
    int s2 = arr2.size();
    int s = s1 + s2;
    if(s1 == 0) {
        return medianSortedArray(arr2);
    }
    if(s2 == 0) {
        return medianSortedArray(arr1);
    }

    if(s%2==1) {
        int target = ((s+1)/2)-1;
        int i = 0;
        int j = 0;
        while(true) {
            if(i == s1) {return arr2[target - i];}
            if(j == s2) {return arr1[target - j];}

            if(i+j == target) {
                return min(arr1[i], arr2[j]);
            }

            if(arr1[i] < arr2[j])
            {i++;}
            else
            {j++;}
        }
    } else {
        int target = s/2;
        int i = 0;
        int j = 0;
        double prev = 0;
        while(true) {
            if(i == s1) {
                target -= i;
                if(target == 0) {
                    return (prev + arr2[j]) / 2.0;
                } else {
                    return (max(arr2[target - 1], prev) + arr2[target]) / 2.0;
                }
            }
            if(j == s2) {
                target -= j;
                if(target == 0) {
                    return (prev + arr1[i]) / 2.0;
                } else {
                    return (max(arr1[target - 1], prev) + arr1[target]) / 2.0;
                }
            }

            if(i+j == target) {
                return (min(arr1[i], arr2[j]) + prev)/2.0;
            }

            if(arr1[i] < arr2[j]){
                prev = arr1[i];
                i++;
            }else{
                prev = arr2[j];
                j++;
            }
        }
    }
}

double medianSortedArray(vector<int>& arr) {
    if(arr.size()%2 == 1) {
        return arr[((arr.size() + 1)/2) - 1];
    } else {
        return (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0;
    }
}

int max(int n1, int n2){
    if(n1>n2){
        return n1;
    }
    return n2;
}
