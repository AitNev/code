#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Space O(1), Time O(n) Simple DP problem
    int maxProfit(vector<int>& prices) {
        int best = 0, curr, last=0;
        for (int i = prices.size()-2; i >= 0; i--) {
            curr = max(prices[i+1], last + prices[i+1]) - prices[i];
            last = curr;
            if (curr > best) best = curr;
        }
        return best;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test Case 1: " << solution.maxProfit(prices1) << endl;

    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test Case 2: " << solution.maxProfit(prices2) << endl;

    return 0;
}