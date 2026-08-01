//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n (number of elements to enqueue)
//- Second line: n space-separated integers
//- Third line: integer m (number of dequeue operations)

//Output:
//- Print queue elements from front to rear after operations, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//30 40 50 10 20

//Explanation:
//Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.



//soultion:


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int m;
    cin >> m;

    int front = 0;
    // Each dequeue advances the front pointer by one, wrapping around
    for (int i = 0; i < m; i++) {
        front = (front + 1) % n;
    }

    // Print all n elements starting from the new front, wrapping around
    for (int i = 0; i < n; i++) {
        cout << arr[(front + i) % n];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}