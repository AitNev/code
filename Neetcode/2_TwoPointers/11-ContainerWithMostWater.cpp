#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Space O(1), Time O(n)
    int maxArea(vector<int>& height) {
        if (height.size() == 1) return height[0];

        int maxArea = 0, f = 1;
        int b = 0, e = height.size()-1;
        while(b < e) { // O(n)
            // Advance the barriers if we cant hold the flood
            while (b < e && height[b] < f) b++;
            while (b < e && height[e] < f) e--;
            // Check if it can handle the flood and update maxArea
            if (b >= e || height[b] < f || height[e] < f) return maxArea;
            else if (maxArea < (e - b) * f) maxArea = (e - b) * f;
            f++;
        }
        // Shouldn't ever exit here
        return 0;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = solution.maxArea(height1);
    cout << "Test case 1: " << result1 << endl;

    // Test case 2
    vector<int> height2 = {1, 1};
    int result2 = solution.maxArea(height2);
    cout << "Test case 2: " << result2 << endl;

    // Test case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    int result3 = solution.maxArea(height3);
    cout << "Test case 3: " << result3 << endl;

    // Test case 4
    vector<int> height4 = {1, 2, 1};
    int result4 = solution.maxArea(height4);
    cout << "Test case 4: " << result4 << endl;

    return 0;
}