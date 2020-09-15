/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing
word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5   */

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0)
            return 0;
        int res=0,curr=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            { 
                if(curr!=0)
                res=curr;
                curr=0;
            }
            else
            curr++;
        }
        if(curr==0)
        return res;
        else
        return curr;
    }
};
