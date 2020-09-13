/* Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example:

Input: k = 3, n = 7
Output: [[1,2,4]] */

class Solution {
public:
    vector<vector<int>>res;
    void find_combo(vector<int>v,int n,int k, int start)
    {
        if(n==0&&k==0)
        {
            res.push_back(v);
            return;
        }
        if(k<0||n<0)
            return;
        for(int i=start;i<=9;i++)
        {
            v.push_back(i);
            find_combo(v,n-i,k-1,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        find_combo(v,n,k,1);
        return res;
    }
};
