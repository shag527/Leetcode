/*  We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


Example:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].  */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ptr1=0,ptr2=1,min_=nums[0],max_=nums[0],len=0,flag=0,res=0;
        while(ptr2<nums.size()&&ptr1<nums.size())
        {
            max_=nums[ptr2];
            min_=nums[ptr1];
            if(ptr1==ptr2||nums[ptr1]==nums[ptr2])
            {
                ptr2++;
                continue;
            }
            if(max_-min_==1)
            {
                res=max(res,ptr2-ptr1+1);
                ptr2++;
            }
            else
            ptr1++;
            res=max(len,res);   
        }
        return res;
    }
};
