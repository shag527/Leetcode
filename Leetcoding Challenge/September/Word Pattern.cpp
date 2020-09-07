/* Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>v;
        int index=0;
        string s="";
        for(int i=0;i<str.size();)
        {
            s.clear();
            while(i<str.size()&&str[i]!=' ')
            {
                s.push_back(str[i]);
                i++;
            }
            i++;
            v.push_back(s);
        }
        if(pattern.size()!=v.size())
            return false;
        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp1.find(v[i])==mp1.end())
            mp1[v[i]]=pattern[i];
            else
            {
                auto itr=mp1.find(v[i]);
                if(pattern[i]!=(itr->second))
                return false;
            }
            if(mp2.find(pattern[i])==mp2.end())
            mp2[pattern[i]]=v[i];
            else
            {
                auto itr=mp2.find(pattern[i]);
                if(v[i].compare(itr->second)!=0)
                return false;
            }
        }
        return true;
    }
};
