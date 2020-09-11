/* You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7. */

class Solution {
public:
    string getHint(string s, string g) {
        vector<int>v1(10),v2(10);
        int bull=0,cow=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==g[i])
            {
                bull++;
                v1[s[i]-'0']--;
                v2[g[i]-'0']--;
            }
            v1[s[i]-'0']++;
            v2[g[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        cow+=min(v1[i],v2[i]);
        string res="";
        res+=std::to_string(bull);
        res+='A';
        res+=std::to_string(cow);
        res+='B';
        return res;
    }
};
