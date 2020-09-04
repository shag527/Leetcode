/* A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part,
and return a list of integers representing the size of these parts. 

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts. */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>arr(26),res;
        if(s.size()==0)
            return res;
        for(int i=0;i<s.size();i++)
            arr[s[i]-'a']=i;
        int index=0,prev_index=-1;
        while(1)
        {
            for(int i=index;i<arr[s[index]-'a'];i++)
            {
                if(arr[s[i]-'a']>index)
                    index=arr[s[i]-'a'];
            } 
            index++;
            if(prev_index==-1)
            res.push_back(index);
            else
            res.push_back(index-prev_index);
            prev_index=index;
            if(index>=s.size())
                break;
        }
        return res;
    }
};


