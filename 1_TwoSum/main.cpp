#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main() {
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++) {
        map[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++) {
        int n = target - nums[i];
        if(map.count(n) && map[n] != i) {
            return {i, map[n]};
        }
    }
    return {};
}
