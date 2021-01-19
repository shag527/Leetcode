/* Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.  */

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),dp[n][n];
        string ans="";
        ans+=s[0];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
         for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1||dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
