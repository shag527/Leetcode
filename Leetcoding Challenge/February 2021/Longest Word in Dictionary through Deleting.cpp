/*  Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there
are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"  */


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res="";
        int ptr1=0,ptr2=0;
        for(int i=0;i<d.size();i++)
        {
            int flag=0;
            ptr1=0;
            ptr2=0;
            while(ptr1<s.size()&&ptr2<d[i].size())
            {
                if(s[ptr1]==d[i][ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                    ptr1++;
            }
            if(ptr2==d[i].size()&&d[i].size()>res.size())
            {
                res="";
                res.append(d[i]);
            }
            else if(ptr2==d[i].size()&&d[i].size()==res.size())
            {
                if(res.compare(d[i])>0)
                {
                    res="";
                    res.append(d[i]);
                }       
            }
        }
        return res;
    }
};
