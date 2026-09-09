//Problem Statement
//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

//Input Format
//An integer array arr[].

//Output Format
//Print the length of the longest subarray with sum equal to zero.

//Sample Input
//15 -2 2 -8 1 7 10 23

//Sample Output
//5

//Explanation
//The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.



//solution:




class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lo = 1;

        for (int d = 1; lo <= n; d++) {
            long long hi = lo * 10 - 1;           // largest d-digit number
            long long hiCapped = min(hi, n);       // cap at n
            long long cnt = hiCapped - lo + 1;     // how many d-digit numbers <= n
            long long commasPerNum = (d - 1) / 3;  // commas in a d-digit number

            total += cnt * commasPerNum;

            lo = hi + 1; // move to first (d+1)-digit number
        }

        return total;
    }
};