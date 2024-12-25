#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

/*  C ADTs
    - std::vector sort() Hybrid(Insertion n<16, Quicksort,
        Heapsort(bad recursion case for Quicksort)), Cache optimized, with parallelism
    - std::set it's a red-black tree underneath
    - Avoid std::list frequent node memory allocations, good if its already built
 */

class Solution {
public:
    // This function checks for duplicate elements in a vector
    // O(n log n) Time and O(n) Space to not modify the original vector
    bool containsDuplicate(vector<int>& nums) {
//        list<int> sorted;
//        for (int num:nums) {    // O(n log n) To sort the list
//            auto pos = findInsertPos(sorted, num);
//            sorted.insert(pos, num);
//        }
        sort(nums.begin(), nums.end());

        bool isDuplicated = false;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] == nums[i]){
                return true;
            }
        }

//        // Test print
//        for (int num:sorted) {
//            cout << num << ", ";
//        }cout << endl;

        return isDuplicated;
    }
//private:
//    // This function finds in O(log n) the iterator position for insertion sorting
//    static list<int>::iterator findInsertPos(list<int>& sorted, int num){
//        auto start = sorted.begin();    // Get the beginning and ending iterators
//        auto end = sorted.end();
//
//        size_t delta = std::distance(start, end);   // Get the delta in between
//        while(delta > 0){
//            size_t half = delta / 2;
//            auto mid = start;
//
//            std::advance(mid, half);                // Look at the half-point
//            if (*mid < num) {                       // -> Discard the Left side
//                start = std::next(mid);
//                delta -= half + 1;
//            } else {                                // <- Discard the Right side
//                delta = half;
//            }
//        }
//        return start;
//    }
};

int main() {
    Solution solution;

    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 3, 4};
    vector<int> test3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << "Test 1: " << solution.containsDuplicate(test1) << endl;
    cout << "Test 2: " << solution.containsDuplicate(test2) << endl;
    cout << "Test 3: " << solution.containsDuplicate(test3) << endl;

    return 0;
}
