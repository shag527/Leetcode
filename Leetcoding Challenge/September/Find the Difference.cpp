/* Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde" */

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v(26);
        for(int i=0;i<s.size();i++)
            v[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
        {
            if(v[t[i]-'a']==0)
                return t[i];
            else
                v[t[i]-'a']--;
        }
        return t[0];
    }
};