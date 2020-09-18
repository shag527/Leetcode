/* Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.   */
             
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int max_price=prices[0],min_price=prices[0],res=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>max_price)
                max_price=prices[i];
            else if(prices[i]<min_price)
            {
                min_price=prices[i];
                max_price=prices[i];
            }
            if(max_price-min_price>res)
                res=max_price-min_price;
        }
        return res;
    }
};
