/*  There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter.
Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.


Example:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6])   */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        sort(points.begin(),points.end());
        int right=points[0][1],count=1;
        for(int i=1;i<points.size();i++)
        {
            if(right>=points[i][0])
            right=min(points[i][1],right);
            else
            {
                count++;
                right=points[i][1];
            }
        }
        return count;
    }
};
