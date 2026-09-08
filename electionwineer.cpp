//Problem Statement
//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

//Input Format
//First line contains an integer n representing number of votes.
//Second line contains n space-separated strings representing candidate names.

//Output Format
//Print the name of the winning candidate followed by the number of votes received.

//Sample Input
//13
//john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

//Sample Output
//john 4

//Explanation
//Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.



//solution:



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> votes(n);
    for (int i = 0; i < n; i++) {
        cin >> votes[i];
    }
    
    map<string, int> count; // map keeps keys sorted lexicographically
    for (const string& name : votes) {
        count[name]++;
    }
    
    string winner;
    int maxVotes = 0;
    
    for (const auto& [name, votes] : count) {
        if (votes > maxVotes) {
            maxVotes = votes;
            winner = name;
        }
        // if votes == maxVotes, we skip — since map iterates in
        // lexicographical order, the first name we saw with this
        // count is already the smallest
    }
    
    cout << winner << " " << maxVotes << endl;
    
    return 0;
}