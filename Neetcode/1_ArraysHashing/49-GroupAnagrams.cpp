#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
    // Custom hash function for array, not needed in C++ 20
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t hash = 0;
            for (int count : arr) {
                hash = hash * 31 + count; // Combine hash values
            }
            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> anagramMap;

        for (const string& str : strs) {
            array<int, 26> charCount = {0};
            for (char c : str) {    // Char counting
                charCount[c - 'a']++;
            }

            // Use the charCount array hash as the key
            anagramMap[charCount].push_back(str);
        }

        // Prepare the returning vector
        vector<vector<string>> result;
        for (auto& entry : anagramMap) {
            result.push_back(move(entry.second));
        }
        return result;
    }
};

void printResult(const vector<vector<string>>& result) {
    for (const auto& group : result) {
        cout << "[";
        for (const auto& str : group) {
            cout << str << ",";
        }
        cout << "], ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    cout << "Test case 1: \n";
    printResult(result1);

    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    cout << "Test case 2: \n";
    printResult(result2);

    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = solution.groupAnagrams(strs3);
    cout << "Test case 3: \n";
    printResult(result3);

    return 0;
}
