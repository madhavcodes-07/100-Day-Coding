//Problem: Given intervals, merge all overlapping ones.
//Sort first, then compare with previous.


//solution:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (auto& cur : intervals) {
            if (result.empty() || result.back()[1] < cur[0]) {
                result.push_back(cur);
            } else {
                result.back()[1] = max(result.back()[1], cur[1]);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<vector<int>>> tests = {
        {{1,3},{2,6},{8,10},{15,18}},   // expect [[1,6],[8,10],[15,18]]
        {{1,4},{4,5}},                  // expect [[1,5]]
        {{4,7},{1,4}},                  // expect [[1,7]]
        {{1,10},{2,3}}                  // expect [[1,10]]
    };

    for (auto& t : tests) {
        auto res = sol.merge(t);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            cout << "[" << res[i][0] << "," << res[i][1] << "]";
            if (i + 1 < res.size()) cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}