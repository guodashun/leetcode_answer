#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map <int, int> hashMap;
        for (int i = 0; i < size; i++) {
            int diff = target - nums[i];
            if (hashMap.find(diff) != hashMap.end()) {
                vector <int> result;
                result.push_back(hashMap[diff]);
                result.push_back(i);
                return result;
            }
            hashMap[nums[i]] = i;
        }
    }
    // 如果数组有序，则可以用二分查找的方式解决
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) return vector<int>{left, right};
            else if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }
        }
    }
};


// test
int main() {
    Solution sol;
    int test_array[] = {1,2,3,4,5};
    int target = 9;
    vector<int> test;
    for (int i = 0; i < 5; i++) {
        test.push_back(test_array[i]);
    }
    vector<int> result = sol.twoSum(test, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}