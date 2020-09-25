/* Given a list of non negative integers, arrange them such that they form the largest number.

Example:

Input: [10,2]
Output: "210"  */

class Solution {
public:
    static bool sort_func(string &a, string &b)
    return (a+b)>=(b+a);
    string largestNumber(vector<int>& nums) {
        vector<string>s(nums.size(),"");
        int cnt_zero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                cnt_zero++;
            s[i]=to_string(nums[i]);
        }
        if(cnt_zero==nums.size())
            return "0";
        sort(s.begin(),s.end(),sort_func);
        string res="";
        for(int i=0;i<s.size();i++)
        res+=s[i];
        return res;
    }
};
