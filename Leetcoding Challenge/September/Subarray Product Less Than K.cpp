/* our are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.   */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),ptr=0,sum=1,res=0;
        vector<int>idx(n);
        for(int i=0;i<n;i++)
        {
            sum*=nums[i];
            if(nums[i]>=k)
            {
                idx[i]=-1;
                continue;
            }
            if(sum>=k)
            {
                while(ptr<i&&sum>=k)
                {
                    sum/=nums[ptr];
                    ptr++;
                }
            }
            idx[i]=ptr;
        } 
        for(int i=0;i<n;i++)
        {
            if(idx[i]!=-1)        
            res+=i-idx[i]+1;
        }
        return res;
    }
};
