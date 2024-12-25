#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Space O(n), Time Worst O(n^2), Time Average O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        // Use an unordered map to efficiently find the complement
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }

        return {};
    }
};

// Sake of debugging
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    Solution solution;

    vector<int> test1 = {2,7,11,15};
    vector<int> test2 = {3,2,4};
    vector<int> test3 = {3,3};

    int t1 = 9, t2 = 6, t3 = 6;

    printVector(solution.twoSum(test1, t1));
    printVector(solution.twoSum(test2, t2));
    printVector(solution.twoSum(test3, t3));

    return 0;
}