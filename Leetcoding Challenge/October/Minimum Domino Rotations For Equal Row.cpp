/*  In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half 
of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicate  */

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int>count_a(7),count_b(7);
        int max_a=0,max_b=0,idx_a=0,idx_b=0,res=0;;
        for(int i=0;i<A.size();i++)
        {
            count_a[A[i]]++;
            count_b[B[i]]++;
        }
        for(int i=1;i<=6;i++)
        {
            if(count_a[i]>max_a)
            {
                idx_a=i;
                max_a=count_a[i];
            }
            if(count_b[i]>max_b)
            {
                idx_b=i;
                max_b=count_b[i];
            }
        }
        if(max_a>max_b)
        {
            for(int i=0;i<A.size();i++)
            {
                if(A[i]!=idx_a)
                {
                    res++;
                    swap(A[i],B[i]);
                    if(A[i]!=idx_a)
                    return -1;
                }
            }
        }
        else
        {
            for(int i=0;i<B.size();i++)
            {
                if(B[i]!=idx_b)
                {
                    res++;
                    swap(A[i],B[i]);
                    if(B[i]!=idx_b)
                    return -1;
                }
            }
        }
        return res;
    }
};
