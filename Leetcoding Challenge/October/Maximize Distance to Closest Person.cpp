/*  You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example:

Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.   */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ptr1=0,ptr2=0,res=0;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)
            {
                if(ptr1==0||ptr2==seats.size())
                res=max(res,ptr2-ptr1);
                else if((ptr2-ptr1)%2==0)
                res=max(res,(ptr2-ptr1)/2);
                else
                res=max(res,(ptr2-ptr1+1)/2);
                ptr2++;
                ptr1=ptr2;
            }
            else
            ptr2++;
        }
        if(ptr2==seats.size()&&seats[seats.size()-1]==0)
        res=max(res,ptr2-ptr1);
        return res;
    }
};
