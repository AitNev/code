#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    // Space O(n), Time O(nlogn + nc) c: Simulation cycles
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Sort the input O(nlogn)
        vector<pair<int,int>> vehicles;
        for(int i=0; i<position.size();i++){
            vehicles.push_back({position[i], speed[i]});
        }
        sort(vehicles.begin(), vehicles.end());

        // Place the sorted vector into a stack O(n)
        stack<pair<int, int>> myStack, aux;
        for (auto v:vehicles) {
            if (myStack.empty()) myStack.push(v);
            else{
                if (myStack.top().first == v.first){
                    int val = myStack.top().second; // Update for slower speed
                    myStack.top().second = (val > v.second)? v.second:val;
                }else myStack.push(v);
            }
//            printf("V: %i S %i \n",v.first, v.second);
        }

        // Simulate the cars running O(nc) c:simulation cycles
        int fleets = 0;
        while(!myStack.empty()){        // Iterate until all stacks are empty
            bool hasArrived = false;
            long long maxTime = 0;
            while(!myStack.empty()){    // Full iteration of myStack
                auto v = myStack.top();
                myStack.pop();          // Get the vehicle
                int old = v.first;
                v.first += v.second;    // Advance the vehicle
                // Do nothing, effectively removing the v into a fleet
                if (!aux.empty() && aux.top().first <= v.first);
                // A vehicle or fleet has arrived to the target
                else if (v.first >= target) { // 2x3x3x5x7x11x13 Removes float unittests randomness, Did solve the problem :D
                    long long time = (long long)(target - (v.first - v.second))*900090 / v.second;
                    if (time > maxTime || maxTime == 0) {
                        maxTime = time;
                        fleets++;
                    }
                // Store the vehicle for the next loop
                }else aux.push(v);
            }

            // Ideally, use a queue to fix this dumb iterations
            while (!aux.empty()){
                myStack.push(aux.top());
                aux.pop();
            }
        }
        printf("Result %i", fleets);
        return fleets;
    }
};

int main() {
    Solution solution;

    // Example 1
    int target1 = 12;
    vector<int> position1 = {10, 8, 0, 5, 3};
    vector<int> speed1 = {2, 4, 1, 1, 3};
    int expected1 = 3;
    assert(solution.carFleet(target1, position1, speed1) == expected1);
    cout << "Example 1 passed!" << endl;

    // Example 2
    int target2 = 16;
    vector<int> position2 = {11,14,13,6};
    vector<int> speed2 = {2,2,6,7};
    int expected2 = 2;
    assert(solution.carFleet(target2, position2, speed2) == expected2);
    cout << "Example 2 passed!" << endl;

    // Example 3
    int target3 = 10;
    vector<int> position3 = {8,3,7,4,6,5};
    vector<int> speed3 = {4,4,4,4,4,4};
    int expected3 = 6;
    assert(solution.carFleet(target3, position3, speed3) == expected3);
    cout << "Example 3 passed!" << endl;

    cout << "All examples passed!" << endl;
    return 0;
}
