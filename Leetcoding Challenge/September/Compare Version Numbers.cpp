/* Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 
for its first and second level revision number. Its third and fourth level revision number are both 0.

 Example:

Input: version1 = "0.1", version2 = "1.1"
Output: -1 */

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int p1=0,p2=0,val1=0,val2=0;
        string s1="",s2="";
        while(1)
        {
            s1.clear();
            s2.clear();
            val1=0;
            val2=0;
            while(p1<v1.size()&&v1[p1]!='.')
            {
                s1+=v1[p1];
                p1++;
            }
            if(!s1.empty())
            val1=std::stoi(s1);
            while(p2<v2.size()&&v2[p2]!='.')
            {
                s2+=v2[p2];
                p2++;
            }
            if(!s2.empty())
            val2=std::stoi(s2);
            if(val1>val2)
                return 1;
            else if(val1<val2)
                return -1;
            if(p1>v1.size()&&p2>v2.size())
                break;
            p1++;
            p2++;
        }
        return 0;
    }
};
