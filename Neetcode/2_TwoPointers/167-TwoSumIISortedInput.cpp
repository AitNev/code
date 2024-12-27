#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Space O(1), Time O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int b = 0, e = numbers.size()-1;

        while (b < e){
            int n = numbers[b];
            // Move the end pointer, making the sum smaller
            while(b < e && (n + numbers[e]) > target) e--;
            // Move the start pointer, making the sum larger
            n = numbers[e];
            while(b < e && (n + numbers[b]) < target) b++;

            if (n + numbers[b] == target) return {b+1, e+1};
        }

        return {0, 0};  // Return whatever if it didn't solve it
    }
};

int main() {
    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution solution;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << "Test case 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << "Test case 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test case 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << "Test case 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
