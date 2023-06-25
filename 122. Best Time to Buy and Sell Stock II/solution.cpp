/*
// Using Recursion, without memoisation
// Gives Time Limit Exceeded error, so need to use Memoisation to optimise the code

class Solution {
public:

    int calcProfit(vector<int>& prices, int currIndex, bool hasStock){
        if(currIndex == prices.size()) return 0;

        int profit{};
        // On each trading day, I've 3 choices
        // 1. buy the stock or won't buy the Stock
        // 2. sell the stock
        // 3. Do nothing / Hold on the Stock

        if(hasStock){
            // Sell the Stock or hold the stock
        profit = max(prices[currIndex] + calcProfit(prices, currIndex + 1, !hasStock), calcProfit(prices, currIndex + 1, hasStock));
        }else{
            // Buy the Stock or hold the Stock
            profit = max(calcProfit(prices, currIndex + 1, !hasStock) - prices[currIndex], calcProfit(prices, currIndex + 1, hasStock));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return calcProfit(prices, 0, false);
    }
};
*/

/*
// Using Recursion, with memoisation

class Solution {
public:

    int calcProfit(vector<int>& prices, int currIndex, int hasStock, vector<vector<int>>& dp){
        if(currIndex == prices.size()) return 0;
        if(dp[currIndex][hasStock] != -1) return dp[currIndex][hasStock];
        int profit{};

        // On each trading day, I've 3 choices
        // 1. buy the stock or won't buy the Stock
        // 2. sell the stock
        // 3. Do nothing / Hold on the Stock

        if(hasStock){
            // Sell the Stock or hold the stock
        profit = std::max(prices[currIndex] + calcProfit(prices, currIndex + 1, 0, dp), calcProfit(prices, currIndex + 1, 1, dp));
        }else{
            // Buy the Stock or hold the Stock
            profit = std::max(calcProfit(prices, currIndex + 1, 1, dp) - prices[currIndex], calcProfit(prices, currIndex + 1, 0, dp));
        }

        return dp[currIndex][hasStock] = profit;
    }

    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return calcProfit(prices, 0, 0, dp);
    }
};
*/


/*
// This solution finds Minima and Maxima but not explicitly

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, len=prices.size();
        for(int i=1; i<len; i++)
        {
            profit+=max(prices[i]-prices[i-1],0);
        }
        return profit;
    }
};
*/

/*
// This solution explicitly calculates local Minima and Maxima
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, buy, sell, profit = 0, N = prices.size() - 1;
        while(i < N) {
            //Local Minima
            while(i<N && prices[i+1] <= prices[i]) i++;
            buy = prices[i];
            //Local Maxima
            while(i<N && prices[i+1] > prices[i]) i++;
            sell = prices[i];

            profit+= sell-buy;
        }
        return profit;
    }
};
