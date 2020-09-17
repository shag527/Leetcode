/* On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.    */

class Solution {
public:
    bool isRobotBounded(string ins) {
        vector<pair<int,int>>quad;
        quad.push_back(make_pair(1,1));
        quad.push_back(make_pair(-1,1));
        quad.push_back(make_pair(-1,-1));
        quad.push_back(make_pair(1,-1));
        int x=0,y=0,curr=0;
        pair<int,int>p;
        p=quad[0];
        for(int i=0;i<ins.size();i++)
        {
            if(ins[i]=='G')
            {
                if(p.first==p.second)
                y+=1*p.first;
                else
                x+=1*p.first;
            }
            else if(ins[i]=='L')
            {
                curr=(curr+1)%4;
                p=quad[curr];
            }
            else if(ins[i]=='R')
            {
                curr=(curr+4-1)%4;
                p=quad[curr];
            }
        }
        if(x==0&&y==0||curr!=0)
            return true;
        else 
            return false;
    }
};
