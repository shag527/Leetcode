/* Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]  */

class Solution {
    void reverse(vector<int>& nums,int start,int end)
    {
        for(int i=start;i<start+((end-start)/2);i++)
        { 
            int temp=nums[i];
            nums[i]=nums[start+end-i-1];
            nums[start+end-i-1]=temp;
        }
    }
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        reverse(nums,0,nums.size());
        reverse(nums,k,nums.size());
        reverse(nums,0,k);
    }
};
