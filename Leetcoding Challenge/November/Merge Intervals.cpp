/*  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that 
cover all the intervals in the input.

 

Example:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].  */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        vector<int>temp;
        int left=intervals[0][0],right=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=right)
            right=max(intervals[i][1],right);
            else
            {
                temp.push_back(left);
                temp.push_back(right);
                res.push_back(temp);
                temp.clear();
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        temp.push_back(left);
        temp.push_back(right);
        res.push_back(temp);
        return res;
    }
};
