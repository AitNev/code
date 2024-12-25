#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    // O(n) Complexity, we iterate once per string and then
    // check constant time the results and O(1)

    bool isAnagram(string s, string t) {
        int sl = s.length(), tl = t.length();
        int sChars[26], tChars[26];

        // If string sized don't match or are empty
        if(sl != tl || sl < 1)
            return false;

        // Initialize the arrays to 0
        memset(sChars, 0, sizeof(sChars));
        memset(tChars, 0, sizeof(tChars));

        // Start counting the character occurrences
        bool result = addStr(s, sChars);
        if (!result) return false;
        result = addStr(t, tChars);
        if (!result) return false;

        // Compare for the same number of occurrences
        int i = 0;
        while(result && i < 26){
            if (sChars[i] != tChars[i])
                result = false;
            i++;
        }
        return result;
    }


private:
    // Counts the char occurrences of a given string and storing array
    bool addStr(string s, int* chars){
        for(char c:s){
            if(c < 'a' || c > 'z')      // The character is
                return false;           // non-English or uppercase
            chars[c - 'a']++;           // Add new character
        }
        return true;                    // Went well
    }

    // Test cases
    int main() {
        Solution solution;

        // Test Case 1: Different lengths, can't be anagrams
        string s1 = "listen";
        string t1 = "silently";
        cout << "Test Case 1: ";
        cout << (solution.isAnagram(s1, t1) ? "Failed" : "Passed") << endl;

        // Test Case 2: Different characters, can't be anagrams
        string s2 = "hello";
        string t2 = "world";
        cout << "Test Case 2: ";
        cout << (solution.isAnagram(s2, t2) ? "Failed" : "Passed") << endl;

        // Test Case 3: Empty strings, can't be anagrams
        string s3 = "";
        string t3 = "";
        cout << "Test Case 3: ";
        cout << (solution.isAnagram(s3, t3) ? "Failed" : "Passed") << endl;

        // Test Case 4: Different characters and lengths, can't be anagrams
        string s4 = "abcd";
        string t4 = "xyz";
        cout << "Test Case 4: ";
        cout << (solution.isAnagram(s4, t4) ? "Failed" : "Passed") << endl;

        // Test Case 5: Repeated characters but different occurrences, can't be anagrams
        string s5 = "banana";
        string t5 = "orange";
        cout << "Test Case 5: ";
        cout << (solution.isAnagram(s5, t5) ? "Failed" : "Passed") << endl;

        // Anagram Test Case 1: Anagrams - "listen" and "silent"
        string s6 = "listen";
        string t6 = "silent";
        cout << "Anagram Test Case 1: ";
        cout << (solution.isAnagram(s6, t6) ? "Passed" : "Failed") << endl;

        // Anagram Test Case 2: Anagrams - "debit" and "debit"
        string s7 = "debit";
        string t7 = "debit";
        cout << "Anagram Test Case 2: ";
        cout << (solution.isAnagram(s7, t7) ? "Passed" : "Failed") << endl;

        // Anagram Test Case 3: Anagrams - "elbow" and "below"
        string s8 = "elbow";
        string t8 = "below";
        cout << "Anagram Test Case 3: ";
        cout << (solution.isAnagram(s8, t8) ? "Passed" : "Failed") << endl;

        return 0;
    }
};