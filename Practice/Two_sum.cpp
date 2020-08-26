//Two Sum

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice. */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>v;
        unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(target-nums[i])!=s.end())
            {
                auto itr=s.find(target-nums[i]);
                v.push_back(i);
                v.push_back(itr->second);
                return v;
            }
            s[nums[i]]=i;
        }
        return v;
    }
};
