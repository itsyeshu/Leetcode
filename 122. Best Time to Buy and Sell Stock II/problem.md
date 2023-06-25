# 122. Best Time to Buy and Sell Stock II

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/).

## Question statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i'th` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return the **maximum** profit you can achieve. If you cannot achieve any profit, return `0`.

## Example:
**Input:**
    prices = [7,1,5,3,6,4]

**Output:**
    7

**Explanation:**
Buy on *day 2* `price = 1` and sell on *day 3* `price = 5`, *profit = 6 - 1 = 4*.
Then buy on *day 4* `price = 3` and sell on *day 5* `price = 6`, *profit = 6 - 3 = 3*.
Total profit is *4 + 3 = 7*.

**Constraints:**
* `1 <= prices.length <= 3 * 10^4`
* `0 <= prices[i] <= 10^4`

**Similar problems:**
* [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)