/*
=========================================================
 SLIDING WINDOW PATTERN - MASTER TEMPLATE
 Author: Himanshu Kumar
 Repo: dsa-patterns-master
=========================================================

Types:
1) Fixed Size Window
2) Variable Size Window

Time Complexity:
O(n)

Space Complexity:
O(1) or O(k) depending on problem
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////
// TEMPLATE 1: Fixed Size Sliding Window
///////////////////////////////////////////////////////////

/*
Use When:
- Window size (k) is given
- Maximum / minimum sum of size k
*/

int maxSumSubarrayOfSizeK(vector<int>& arr, int k) {

    int n = arr.size();
    if (n < k) return -1;

    int windowSum = 0;

    // Step 1: First window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: Slide window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];        // include new element
        windowSum -= arr[i - k];    // remove old element
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

///////////////////////////////////////////////////////////
// TEMPLATE 2: Variable Size Sliding Window
///////////////////////////////////////////////////////////

/*
Use When:
- Longest substring
- Smallest subarray
- At most K distinct elements
- Continuous subarray with condition
*/

int longestSubarrayWithSumAtMostTarget(vector<int>& arr, int target) {

    int left = 0;
    int windowSum = 0;
    int maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {

        // 1. Expand window
        windowSum += arr[right];

        // 2. Shrink window if invalid
        while (windowSum > target) {
            windowSum -= arr[left];
            left++;
        }

        // 3. Update result
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

///////////////////////////////////////////////////////////
// TEMPLATE 3: Variable Window with Frequency Map (String)
///////////////////////////////////////////////////////////

/*
Use When:
- Longest substring without repeating characters
- At most K distinct characters
*/

int lengthOfLongestSubstring(string s) {

    unordered_map<char, int> freq;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right]]++;

        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

