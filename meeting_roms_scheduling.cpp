//Problem: Given meeting intervals, find minimum number of rooms required.
//Sort by start time and use min-heap on end times.



//solution:


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Approach 1: two pointers on sorted start/end arrays, O(1) extra space
    int minMeetingRoomsTwoPointer(vector<int> start, vector<int> end) {
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] >= end[j]) j++;  // a room freed up, reuse it
            else rooms++;                 // need a new room
        }
        return rooms;
    }

    // Approach 2: sort by start time + min-heap of end times, O(n) extra space
    int minMeetingRoomsHeap(vector<int> start, vector<int> end) {
        int n = start.size();
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; i++) meetings[i] = {start[i], end[i]};
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &m : meetings) {
            if (!minHeap.empty() && minHeap.top() <= m.first) minHeap.pop();
            minHeap.push(m.second);
        }
        return minHeap.size();
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, vector<int>>> tests = {
        {{1, 10, 7}, {4, 15, 10}},  // expected 1
        {{2, 9, 6}, {4, 12, 10}},   // expected 2
    };

    for (auto &t : tests) {
        cout << "Two pointer: " << sol.minMeetingRoomsTwoPointer(t.first, t.second)
             << " | Heap: " << sol.minMeetingRoomsHeap(t.first, t.second) << "\n";
    }
    return 0;
}