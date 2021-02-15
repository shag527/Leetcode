/*  Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to
the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j.
Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.


Example:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]  */

bool sort_(const pair<int,int>&a, const pair<int,int>&b)
{
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}
class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>count;
        for(int i=0;i<mat.size();i++)
        {
            int soldiers=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    soldiers++;
                else
                    break;
            }
            count.push_back(make_pair(i,soldiers));
        }
        sort(count.begin(),count.end(),sort_);
        vector<int>res;
        for(int i=0;i<k;i++)
        res.push_back(count[i].first);
        return res;
    }
};
