/* Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        int min_num=INT_MAX,max_num=INT_MIN,min_bucket[n-1],max_bucket[n-1];
        
        //Finding minimum and maximum element
        for(int i=0;i<n;i++)
        {
            if(nums[i]<min_num)
                min_num=nums[i];
            if(nums[i]>max_num)
                max_num=nums[i];
        }
        float f_min=min_num,f_max=max_num;        
        for(int i=0;i<n-1;i++)
        {
            min_bucket[i]=max_num+1;
            max_bucket[i]=-1;
        }
        float interval=ceil((f_max-f_min)/(n-1));
        
        // Finding and filling buckets
        for(int i=0;i<n;i++)
        {
            if(nums[i]==min_num||nums[i]==max_num)
                continue;
            int curr_bucket=floor((nums[i]-min_num)/interval);
            if(min_bucket[curr_bucket]>nums[i])
               min_bucket[curr_bucket]=nums[i];
            if(max_bucket[curr_bucket]<nums[i])
               max_bucket[curr_bucket]=nums[i];
        }
        
        //Finding Maximum Difference
        int res=0,prev=min_num;
        for(int i=0;i<n-1;i++)
        { 
            if(min_bucket[i]!=max_num+1)
            res=max(min_bucket[i]-prev,res);
            if(max_bucket[i]!=-1)
            prev=max_bucket[i];
        }
        res=max(max_num-prev,res);
        return res;
    }
};

