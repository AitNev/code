#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution {
    // Space O(n), Time O(n^2), Time Worst O(n^3)
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Use Hash map to find in O(1) the complement
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        // Brute our way into all the possible triplets
        vector<vector<int>> answer;
        bool first = true;
        int prev;
        for (int i = 0; i < nums.size(); ++i) { // Iterate for i
            if (!first && nums[i] == prev) continue;
            if (first){
                first = false;
                prev = nums[i];
            }
            for (int j = i+1; j < nums.size(); ++j) {
                int ni = nums[i], nj = nums[j];

                // Use the hashmap to find a possible complement
                auto complement = map.find(-(ni + nj));
                if (complement == map.end() || complement->second <= i ||
                    complement->second <= j) continue;  // No valid options
                else {  // Found a valid combination
                    if(ni > nj){ // Insert the combination already sorted
                        if(complement->first > ni)
                            answer.push_back({complement->first, ni, nj});
                        else if(complement->first > nj){
                            answer.push_back({ni, complement->first, nj});
                        } else{
                            answer.push_back({ni, nj, complement->first});
                        }
                    }else{
                        if(complement->first > nj)
                            answer.push_back({complement->first, nj, ni});
                        else if(complement->first > ni){
                            answer.push_back({nj, complement->first, ni});
                        } else{
                            answer.push_back({nj, ni, complement->first});
                        }
                    }
                }
            }
        }

        // Remove the duplicated triplets
        sort(answer.begin(), answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        return answer;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Test case 1:" << endl;
    for (const auto& triplet : result1) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "Test case 2:" << endl;
    for (const auto& triplet : result2) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "Test case 3:" << endl;
    for (const auto& triplet : result3) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    return 0;
}