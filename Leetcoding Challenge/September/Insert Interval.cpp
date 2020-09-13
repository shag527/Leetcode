/* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]  */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        for(int i=0;i<intervals.size();i++)
        {
           if(intervals[i][1]<newInterval[0])
           res.push_back(intervals[i]);
           else if(intervals[i][0]>newInterval[1])
           {
                res.push_back(newInterval);
                newInterval=intervals[i];
           }
           else if(intervals[i][0]<=newInterval[1]&&newInterval[0]<=intervals[i][1])
           {
               //cout<<i<<endl;
               newInterval[0]=min(intervals[i][0],newInterval[0]);
               newInterval[1]=max(intervals[i][1],newInterval[1]);
           }
           
        }
        res.push_back(newInterval);
        return res;
    }
};
