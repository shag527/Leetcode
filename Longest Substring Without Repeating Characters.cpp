// Longest Substring Without Repeating Characters

/* Given a string, find the length of the longest substring without repeating characters. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       int index=0,n=s.size(),count=0,res=0;
        unordered_set<char>m;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])==m.end())
            {
                count++;
                m.insert(s[i]);
            }
            else
            {
                res=max(res,count);
                while(index<i&&s[index]!=s[i])
                {
                    m.erase(s[index]);
                    count--;
                    index++;
                }
                m.erase(s[index]);
                index++;
                m.insert(s[i]);
            }
        }
        res=max(res,count);
        return res;
    }
};
