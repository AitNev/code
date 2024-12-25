#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // Space O(k + u), Time Worst O(n^2 + u log u), Time Average O(n + u log u); where n >= u >= k
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elementMap;

        // Count the elements
        for (int i = 0; i < nums.size(); ++i) {
            elementMap[nums[i]] += 1;
        }

        // Push the elements into max heap
        priority_queue<pair<int, int>> maxHeap;
        for (auto pair:elementMap){
            maxHeap.push({pair.second, pair.first});
//            printf("Element %i, is repeated %i times \n", pair.first, pair.second);
        }

        // Retrieve the k max elements
        vector<int> answer;
        for (int i = 0; i < k; ++i) {
            answer.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return  answer;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);

    cout << "Example 1 Output: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {-1, -1};
    int k2 = 1;
    vector<int> result2 = solution.topKFrequent(nums2, k2);

    cout << "Example 2 Output: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
