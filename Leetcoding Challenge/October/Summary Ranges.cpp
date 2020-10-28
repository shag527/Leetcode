/*  You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"   */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int count=0,flag=0,start=0;
        if(nums.size()==0)
            return res;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1]-1)
            {
                if(count==0)
                    res.push_back(to_string(nums[i]));
                else
                    res.push_back(to_string(start)+"->"+to_string(nums[i]));
                flag=0;
                count=0;
            }
            else
            {
                if(flag==0)
                {
                    start=nums[i];
                    flag=1;
                }
                count++;
            }
        }
        if(count==0)
        res.push_back(to_string(nums[nums.size()-1]));
        else
        res.push_back(to_string(start)+"->"+to_string(nums[nums.size()-1]));
        return res;
    }
};
