/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets. */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            int p1=i+1,p2=nums.size()-1;
            while(p1<p2)
            {
                if(nums[i]+nums[p1]+nums[p2]==0)
                {
                    vector<int>temp;
                    temp={nums[i],nums[p1],nums[p2]};
                    v.push_back(temp);
                    p1++;
                    while(p1<p2&&nums[p1]==nums[p1-1])
                        p1++;
                }
                else if(nums[i]+nums[p1]+nums[p2]>0)
                    p2--;
                else
                    p1++;
            }
        }
        return v;
    }
};
