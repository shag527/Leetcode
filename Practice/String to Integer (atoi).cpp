/* Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

1 Only the space character ' ' is considered as whitespace character.
2 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned. */

class Solution {
public:
    int myAtoi(string str) {
        int i=0,res=0,sign=1;
        char ch;
        while(i<str.size()&&str[i]==' ')
            i++;
        if(i<str.size()&&str[i]=='+'||str[i]=='-')
        {
            sign=(str[i]=='+')?1:-1; 
            i++;
        }
        while(i<str.size()&&str[i]!=' ')
        {
            if((str[i]-'0')>=0&&(str[i]-'0')<=9)
            {
                if(res>INT_MAX/10||res==INT_MAX/10&&str[i]-'0'>INT_MAX%10)
                return (sign==1)?INT_MAX:INT_MIN;
                res=res*10+int(str[i]-'0');
            }
            else 
                return res*sign;
            i++;
        }
        return res*sign;
    }
};
