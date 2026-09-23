//Problem Statement
//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

//Books must be allocated in contiguous order.

//Input Format
//n m
//n space-separated integers representing pages in books

//Output Format
//Print the minimum possible value of the maximum pages assigned to any student.

//Sample Input
//4 2
//12 34 67 90

//Sample Output
//113

//Explanation
//One optimal allocation is:
//Student 1: 12 + 34 + 67 = 113
//Student 2: 90
//Maximum pages = 113 (minimum possible).




//solution:





#include <bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int>& pages, int n, int m, int maxPages) {
    int studentsNeeded = 1;
    int currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) return false; // single book exceeds capacity
        if (currentSum + pages[i] > maxPages) {
            studentsNeeded++;
            currentSum = pages[i];
        } else {
            currentSum += pages[i];
        }
    }
    
    return studentsNeeded <= m;
}

int findPages(vector<int>& pages, int n, int m) {
    if (m > n) return -1; // more students than books
    
    int lo = *max_element(pages.begin(), pages.end());
    int hi = accumulate(pages.begin(), pages.end(), 0);
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isFeasible(pages, n, m, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> pages(n);
    for (int i = 0; i < n; i++) cin >> pages[i];
    
    cout << findPages(pages, n, m) << endl;
    
    return 0;
}