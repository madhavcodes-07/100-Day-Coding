//Problem: Deque (Double-Ended Queue)

//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

//Common Operations:
//1. push_front(value): Insert an element at the front of the deque.
//2. push_back(value): Insert an element at the rear of the deque.
//3. pop_front(): Remove an element from the front of the deque.
//4. pop_back(): Remove an element from the rear of the deque.
//5. front(): Return the front element of the deque.
//6. back(): Return the rear element of the deque.
//7. empty(): Check whether the deque is empty.
//8. size(): Return the number of elements in the deque.

//Additional Operations:
//- clear(): Remove all elements from the deque.
//- erase(): Remove one or more elements from the deque.
//- swap(): Swap contents of two deques.
//- emplace_front(): Insert an element at the front without copying.
//- emplace_back(): Insert an element at the rear without copying.
//- resize(): Change the size of the deque.
//- assign(): Replace elements with new values.
//- reverse(): Reverse the order of elements.
//- sort(): Sort the elements in ascending order.

//Time Complexity:
//- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
//- clear, erase, resize, assign, reverse: O(n)
//- sort: O(n log n)

//Input:
//- Sequence of deque operations with values (if applicable)

//Output:
//- Results of operations such as front, back, size, or the final state of the deque after all operations





//solution:




#include <bits/stdc++.h>
using namespace std;

void printDeque(const deque<int>& dq) {
    for (int x : dq) cout << x << " ";
    cout << "\n";
}

int main() {
    deque<int> dq;

    // Insertion at both ends
    dq.push_back(10);        // [10]
    dq.push_back(20);        // [10 20]
    dq.push_front(5);        // [5 10 20]
    dq.emplace_front(1);     // [1 5 10 20]
    dq.emplace_back(30);     // [1 5 10 20 30]

    // Access
    cout << "front: " << dq.front() << "\n";   // 1
    cout << "back: "  << dq.back()  << "\n";   // 30
    cout << "size: "  << dq.size()  << "\n";   // 5
    cout << "empty: " << dq.empty() << "\n";   // 0

    // Removal at both ends
    dq.pop_front();          // [5 10 20 30]
    dq.pop_back();           // [5 10 20]

    // Erase a single element / a range
    dq.erase(dq.begin() + 1);                  // [5 20]
    dq.assign({4, 2, 9, 7, 1});                // [4 2 9 7 1]
    dq.erase(dq.begin(), dq.begin() + 2);      // [9 7 1]

    // Algorithms (not member functions)
    reverse(dq.begin(), dq.end());             // [1 7 9]
    dq.push_back(3);                           // [1 7 9 3]
    sort(dq.begin(), dq.end());                // [1 3 7 9]

    // Resize and swap
    dq.resize(6);                              // [1 3 7 9 0 0]
    deque<int> other = {100, 200};
    dq.swap(other);                            // dq = [100 200], other = [1 3 7 9 0 0]

    printDeque(dq);
    printDeque(other);

    dq.clear();
    cout << "size after clear: " << dq.size() << "\n";   // 0
    return 0;
}