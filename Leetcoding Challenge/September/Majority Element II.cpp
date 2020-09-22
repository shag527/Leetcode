/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example:

Input: [3,2,3]
Output: [3]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,num1=0,count2=0,num2=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0&&nums[i]!=num2||nums[i]==num1)
            {
                count1++;
                num1=nums[i];
            }
            else if(count2==0&&nums[i]!=num1||nums[i]==num2)
            {
                count2++;
                num2=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
        }
        if(count1>nums.size()/3)
            res.push_back(num1);
        if(count2>nums.size()/3)
            res.push_back(num2);
        return res;
    }
};
