# 189. Rotate Array

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/rotate-array/).

## Question statement

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

## Example:
**Input:**
    nums = [1,2,3,4,5,6,7], k = 3

**Output:**
    [5,6,7,1,2,3,4]

**Explaination:**
1. Rotate `1` steps to the right: `nums = [7,1,2,3,4,5,6]`
2. Rotate `2` steps to the right: `nums = [6,7,1,2,3,4,5]`
3. Rotate `3` steps to the right: `nums = [5,6,7,1,2,3,4]`

**Constraints:**
* `1 <= nums.length <= 105`
* `-231 <= nums[i] <= 231 - 1`
* `0 <= k <= 105`

**Follow up :**
* Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
* Could you do it in-place with O(1) extra space?
