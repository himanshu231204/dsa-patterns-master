/*
=========================================================
 HASHING PATTERN - LEETCODE STYLE TEMPLATE
 Author: Himanshu Kumar
 Repo: dsa-patterns-master
=========================================================

Use Cases:
1) Frequency count
2) Two Sum (unsorted)
3) Subarray sum = K
4) Longest subarray with sum K

Time Complexity: O(n)
Space Complexity: O(n)
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    ///////////////////////////////////////////////////////////
    // 1️⃣ Frequency Count
    ///////////////////////////////////////////////////////////

    unordered_map<int,int> frequencyCount(vector<int>& nums) {

        unordered_map<int,int> freq;

        for(int x : nums){
            freq[x]++;
        }

        return freq;
    }


    ///////////////////////////////////////////////////////////
    // 2️⃣ Two Sum (Unsorted Array)
    ///////////////////////////////////////////////////////////

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }


    ///////////////////////////////////////////////////////////
    // 3️⃣ Count Subarray Sum = K
    ///////////////////////////////////////////////////////////

    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefix = 0;
        int count = 0;

        for(int x : nums){

            prefix += x;

            if(mp.find(prefix - k) != mp.end()){
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }


    ///////////////////////////////////////////////////////////
    // 4️⃣ Longest Subarray with Sum K
    ///////////////////////////////////////////////////////////

    int longestSubarraySumK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int prefix = 0;
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++){

            prefix += nums[i];

            if(prefix == k){
                maxLength = i + 1;
            }

            if(mp.find(prefix - k) != mp.end()){
                maxLength = max(maxLength, i - mp[prefix - k]);
            }

            if(mp.find(prefix) == mp.end()){
                mp[prefix] = i;
            }
        }

        return maxLength;
    }

};