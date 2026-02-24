/*
=========================================================
 TWO POINTER PATTERN - ARRAY
 Author: Himanshu Kumar
 Repo: dsa-patterns-master
=========================================================

Pattern Types:
1) Opposite Direction (left--right)
2) Same Direction (slow-fast)
3) Fixed + Two Pointer (3Sum type)
===============================================================
1) Opposite:
   left = 0, right = n-1
   left++ / right--

2) Slow-Fast:
   slow = 0
   for fast:
       if condition:
           slow++

3) Fixed + 2P:
   for i:
       left = i+1
       right = n-1
 ==============================================================================      
Identification Clues:
- Sorted array? → Opposite
- Pair sum? → Opposite
- Remove duplicates / shift? → Slow-Fast
- Triplet problem? → Fixed + Two Pointer
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////
// TEMPLATE 1: Opposite Direction (Pair / Sorted Array)
///////////////////////////////////////////////////////////

bool twoSumSorted(vector<int>& arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        }
        else if (sum < target) {
            left++;        // need bigger sum
        }
        else {
            right--;       // need smaller sum
        }
    }

    return false;
}

///////////////////////////////////////////////////////////
// TEMPLATE 2: Same Direction (Slow-Fast Pointer)
///////////////////////////////////////////////////////////

int removeDuplicates(vector<int>& arr) {

    int slow = 0;

    for (int fast = 1; fast < arr.size(); fast++) {

        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    return slow + 1;   // new length
}

///////////////////////////////////////////////////////////
// TEMPLATE 3: Fixed + Two Pointer (3Sum Type)
///////////////////////////////////////////////////////////

vector<vector<int>> threeSum(vector<int>& arr, int target) {

    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {

        int left = i + 1;
        int right = arr.size() - 1;

        while (left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}



