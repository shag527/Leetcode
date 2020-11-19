/*  Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a 
positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be 
input like 3a or 2[4].

Example:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"    */

class Solution {
public:
    string repeat(string temp,int times)
    {
        string res="";
        for(int i=0;i<times;i++)
            res+=temp;
        return res;
    }
    string decodeString(string s) {
        stack<string>s1;
        stack<int>s2;
        string num="",temp="",res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                num+=s[i];
            else if(s[i]=='[')
            {
                s1.push(string(1,s[i]));
                s2.push(stoi(num));
                num="";
            }
            else if(s[i]==']')
            {
                while(s1.top()!=string(1,'['))
                {
                    temp+=s1.top();
                    s1.pop();
                }
                s1.pop();
                s1.push(repeat(temp,s2.top()));
                s2.pop();
                temp="";
            }
            else
                s1.push(string(1,s[i]));
        }
        while(!s1.empty())
        {
            res+=s1.top();
            s1.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
