/* Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2. */

class Solution {
public:
int divide(int dividend, int divisor) {
        int sign= (dividend<0 ^ divisor<0) ? -1 : 1; 
        
        long ldividend=labs(dividend);
        long ldivisor=labs(divisor);
     
        long res = exp(log(ldividend)-log(ldivisor));
        if(res>INT_MAX)
            return sign==1 ? INT_MAX:INT_MIN;
        return sign*(int)res;
        }
};
