#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Solution {

    // Space O(n), Time O(n)
    int trap(vector<int>& heights) {
        int accumulator = 0;
        stack<pair<int, int>> s;
        bool leftWall = false;
        for (int i = 0; i < heights.size(); ++i) {
            // On the start put an element
            int h = heights[i];
            if (s.empty()) s.push({h, i});
            else {
                if(h < s.top().first){  // Encounter a dip
                    if (!leftWall){
                        leftWall = true;
                    }
                    s.push({h, i}); // Store when dip lower
                }else if(h > s.top().first){ // Can fill with water
                    if (!leftWall){ // Edge case with no left wall to fill
                        s.pop();    // Replace the stack item with max one
                        s.push({h,i});
                    } else{
                        // Last stack element only counts as the max wall
                        int bottom = s.top().first;
                        while (s.size() > 1 && h > s.top().first){  // Count how much water we can fill
                            // Discard Duplicates
                            while (s.size() > 1 && s.top().first == bottom) s.pop();

                            // Add rectangle with width of i and height min of h or next elem
                            int top = min(h, s.top().first);    // Don't overfill
                            accumulator += (top - bottom) * (i - (s.top().second+1));
//                            printf("At %i added %i \n", i, (top - bottom) * (i - (s.top().second+1)));
                            bottom = top;
                        }
                        // Pop the old maximum
                        if(h > s.top().first || (h == s.top().first && s.size() == 1)) s.pop();
                        s.push({h,i}); // Store this
                    }
                } else{ // Replace duplicated maximums
                    if (s.size() == 1) s.pop();
                    s.push({h,i}); // Update with new wall
                }
            }
        }
        return accumulator;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> height1 = {5,5,1,7,1,1,5,2,7,6}; // Expected 23
    int result1 = solution.trap(height1);
    cout << "Test case 1: " << result1 << endl;

    // Test case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int result2 = solution.trap(height2);
    cout << "Test case 2: " << result2 << endl;

    // Test case 3
    vector<int> height3 = {4, 2, 0, 1, 0, 3};
    int result3 = solution.trap(height3);
    cout << "Test case 3: " << result3 << endl;

    // Test case 4
    vector<int> height4 = {0, 0, 0, 0, 0};
    int result4 = solution.trap(height4);
    cout << "Test case 4: " << result4 << endl;

    // Test case 5
    vector<int> height5 = {1, 1, 1, 1, 1};
    int result5 = solution.trap(height5);
    cout << "Test case 5: " << result5 << endl;

    return 0;
}