//Problem Statement
//Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

//This is an optimization problem where binary search on the answer is required.

//Input Format
//n k
//n space-separated integers representing stall positions

//Output Format
//Print the maximum possible minimum distance between any two cows.

//Sample Input
//5 3
//1 2 8 4 9

//Sample Output
//3

//Explanation
//Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.




//solution:






#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls, int k, int d) {
    int count = 1;
    int last = stalls[0];
    for (int i = 1; i < (int)stalls.size(); i++) {
        if (stalls[i] - last >= d) {
            count++;
            last = stalls[i];
            if (count >= k) return true;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];
    
    sort(stalls.begin(), stalls.end());
    
    int lo = 1, hi = stalls[n - 1] - stalls[0];
    
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;  // bias upward since we want max feasible d
        if (canPlace(stalls, k, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << lo << endl;
    return 0;
}