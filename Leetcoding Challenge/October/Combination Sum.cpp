/*  Combination Sum

Solution
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to
target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is
different.

Example:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.    */

class Solution {
public:
    void find_combinations(vector<int>&n,int target,int l,vector<vector<int>>&res,vector<int>&v)
    {
        if(target==0)
        {
            res.push_back(v);
            return;
        }
        else if(target<0)
        return;
        for(int i=l;i<n.size();i++)
        {
            v.push_back(n[i]);
            find_combinations(n,target-n[i],i,res,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        find_combinations(candidates,target,0,res,v);
        return res;
    }
};
