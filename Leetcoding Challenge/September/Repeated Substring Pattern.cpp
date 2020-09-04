/* Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the
given string consists of lowercase English letters only and its length will not exceed 10000.

Example:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice. */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int curr=0,count=0,flag=0,start=-1;
        if(s.size()<=1)
            return false;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[curr])
            {
                curr=0;
                count=0;
                if(start>=1&&flag==1)
                i=start;
                flag=0;
            }
            else
            {
                if(flag==0)
                {
                    start=i;
                    flag=1;
                }
                curr++;
                count++;
            }
        }
        int length=s.size()-count;
        if(count==1)
        {
            for(int i=1;i<s.size();i++)
                if(s[i]!=s[i-1])
                    return false;
        }
        if(count!=0&&s.size()%length==0&&count%length==0)
            return true;
        else
            return false;
    }
};
