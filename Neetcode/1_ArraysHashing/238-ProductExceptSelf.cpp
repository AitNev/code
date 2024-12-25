#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    // Space O(1), Time O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        array<int, 61> multiples = {0}; // Takes O(1) space

        // Build the multiples array O(n * 61) is still O(n)
        for (int i=0; i<61; i++){
            int multiple = i - 30, acc = 1;
            bool found = false;

            // Find value skipping this number
            for (int num:nums) {
                if(!found && num == multiple){
                    found = true;
                }else{
                    acc = acc * num;
                }
            }
            multiples[i] = acc;
        }

        // Use the multiples array to build the response O(n)
        vector<int> response;
        for (int num:nums) {
            response.push_back(multiples[num+30]);
        }
        return response;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    for (int num: result1) {
        cout << num << " ";
    }
    cout << endl; // Expected output: 24 12 8 6

    // Test Case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    for (int num: result2) {
        cout << num << " ";
    }
    cout << endl; // Expected output: 0 0 9 0 0
}
