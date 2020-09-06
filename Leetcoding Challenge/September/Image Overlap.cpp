/* Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap 
of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit. */

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int>index_a,index_b;
        unordered_map<int,int>count;
        int n=A.size(),res=0;
        for(int i=0;i<n*n;i++)
        {
            if(A[i/n][i%n]==1)
                index_a.push_back(i/n*100+i%n);
            if(B[i/n][i%n]==1)
                index_b.push_back(i/n*100+i%n);
        }
        for(auto i:index_a)
        {
            for(auto j:index_b)
            {
                count[i-j]++;  
            }
        }
        for(auto it:count)
            res=max(res,it.second);
        return res;
    }
};
