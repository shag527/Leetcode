/*  Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.


Example:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).   */

class Solution {
public:
    int check(vector<int>v,int thresh,int num)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        sum+=ceil((float)v[i]/(float)num);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=0,res=INT_MAX;
        for(int i=0;i<nums.size();i++)
            high=max(nums[i],high);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums,threshold,mid)<=threshold)
            {
                res=min(res,mid);
                high=mid-1;
            }
            else if(check(nums,threshold,mid)>threshold)
            low=mid+1;
        }
        return res;
    }
};
