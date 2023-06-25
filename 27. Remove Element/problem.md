# 88. Merge Sorted Array 

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/remove-element/).

## Question statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

Consider the number of elements in `nums` which are not equal to `val` be k, to get accepted, you need to do the following things:

* Change the array `nums` such that the first k elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
* Return k.

## Example:
**Input:**
    nums = [3,2,2,3], val = 3

**Output:**
    2
>Updated `nums = [2, 2, _, _ ]`
It does not matter what you leave beyond the returned `k`,
hence they are underscores.

**Explanation:**
Your function should return `k = 2`, with the first two elements of nums being `2`.

**Constraints:**
* `0 <= nums.length <= 100`
* `0 <= nums[i] <= 50`
* `0 <= val <= 100`


**More to read :**
* [In-place algorithm | Wikipedia](https://en.wikipedia.org/wiki/In-place_algorithm)
