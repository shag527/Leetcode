/* Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6. */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),cur_max=nums[0],cur_min=nums[0],max_prod=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
                swap(cur_max,cur_min);
            cur_max=max(cur_max*nums[i],nums[i]);
            cur_min=min(cur_min*nums[i],nums[i]);
            max_prod=max(max_prod,cur_max);
        }
        return max_prod;
    }
};
