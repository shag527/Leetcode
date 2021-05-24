/*   Given a string s, return the string after replacing every uppercase letter with the same lowercase letter. */

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<=90&&s[i]>=65)
                s[i]+=32;
        }
        return s;
    }
};
