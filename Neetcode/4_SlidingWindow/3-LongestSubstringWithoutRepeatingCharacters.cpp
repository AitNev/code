#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Space O(1), Time O(n)
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(255,-1); // Store 0 for every char
        int max = 0, b = 0, e = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (chars[c] >= b) { // Char has repeated
                if (max < (e-b)) max = e - b;   // Update max
                b = chars[c] + 1;               // Move the beginning
            }
            // Insert the char
            chars[c] = i;
            e++;
        }
        if (max < (e-b)) max = e - b;
        return max;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<string> testCases = {
            "abcabcbb", // Test Case 1
            "bbbbb",    // Test Case 2
            "aab",   // Test Case 3
            "dvdf"        // Test Case 4: Single space
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << (i + 1) << ": " << solution.lengthOfLongestSubstring(testCases[i]) << endl;
    }

    return 0;
}
