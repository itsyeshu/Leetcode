class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestStockPrice  = INT_MAX;
        int maxProfitValue = 0;

        for(int stockPrice : prices){
            lowestStockPrice = std::min(lowestStockPrice, stockPrice);
            maxProfitValue = std::max(stockPrice - lowestStockPrice, maxProfitValue);
        }
        return maxProfitValue;
    }
};