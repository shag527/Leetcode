/*  Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.  */

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int count=0,res=0,flag1=0,flag2=0;
            if(A.size()==0||A.size()==1)
                return 0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i]>A[i-1])
            {
                if(flag2==1)
                {
                    count=0;
                    flag2=0;
                }
                flag1=1;
                count++;
            }
            else if(A[i]<A[i-1])
            {
                count++;
                flag2=1;
            }
            else
            {
                count=0;
                flag1=0;
                flag2=0;
            }
            if(flag1==1&&flag2==1)
            res=max(res,count);
        }
        if(res+1>=3)
        return res+1;
        else return 0;
    }
};
