/*  Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True   */

class Solution {
public:
    int find_dist(vector<int>a,vector<int>b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dist1=find_dist(p1,p2),flag=0;
        int dist2=find_dist(p1,p3);
        int dist3=find_dist(p1,p4);
        if(dist1==dist2&&dist2==dist3)
            return false;
        if(dist1==dist2&&2*dist1==dist3||dist1==dist3&&2*dist1==dist2||dist3==dist2&&2*dist2==dist1)
            flag=1;
        else return 0;
        dist1=find_dist(p3,p1);
        dist2=find_dist(p3,p2);
        dist3=find_dist(p3,p4);
        if(dist1==dist2&&dist2==dist3)
            return false;
        if(flag==1&&dist1==dist2&&2*dist1==dist3||dist1==dist3&&2*dist1==dist2||dist3==dist2&&2*dist2==dist1)
            return true;
        else return false;
    }
};
