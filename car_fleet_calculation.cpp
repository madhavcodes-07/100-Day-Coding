//Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
//Sort cars by position in descending order and calculate time to reach target.


//solution:


#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort by position, descending
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int fleets = 0;
        double lastTime = 0;

        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }
        return fleets;
    }
};

int main() {
    Solution sol;

    vector<int> p1 = {10, 8, 0, 5, 3}, s1 = {2, 4, 1, 1, 3};
    cout << sol.carFleet(12, p1, s1) << "\n"; // 3

    vector<int> p2 = {3}, s2 = {3};
    cout << sol.carFleet(10, p2, s2) << "\n"; // 1

    vector<int> p3 = {0, 2, 4}, s3 = {4, 2, 1};
    cout << sol.carFleet(100, p3, s3) << "\n"; // 1

    return 0;
}