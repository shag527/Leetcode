/*  Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]   */
 
 class Solution {
public:
    vector<vector<int>>res;
    void find_perm(vector<int>& n,int idx)
    {
        if(idx==n.size()-1)
            res.push_back(n);
        unordered_set<int>s;
        for(int i=idx;i<n.size();i++)
        {
            if(s.find(n[i])==s.end())
            {
                swap(n[i],n[idx]);
                find_perm(n,idx+1);
                swap(n[i],n[idx]);
                s.insert(n[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        find_perm(nums,0);
        return res;
    }
};
