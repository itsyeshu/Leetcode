#include<iostream>
#include<vector>

using std::vector;
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

    Solution(){
        vector<int> prices {7,1,5,3,6,4};
        std::cout << maxProfit(prices) << std::endl; // 5
    }
};

int main(){
    Solution sol;
    return 0;
}