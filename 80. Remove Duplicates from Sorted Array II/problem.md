# 80. Remove Duplicates from Sorted Array II

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/).

## Question statement

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place  such that each unique element appears **at most twice**. The relative order of the elements should be kept the same. Then return *the number of unique elements in* `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:
* Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
* Return `k`.

## Example:
**Input:**
    nums = [1,1,1,2,2,3]

**Output:**
    5
>Updated `nums = [1, 1, 2, 2, 3, _]`
It does not matter what you leave beyond the returned `k`,
hence they are underscores.

**Explanation:**
Your function should return `k = 5`, with the first five elements of `nums` being 1, 1, 2, 2 and 3 respectively.

**Constraints:**
* `1 <= nums.length <= 3 * 10^4`
* `-10^-4 <= nums[i] <= 10^4`
* `nums` is sorted in **non-decreasing** order.

**Similar questions :**
* [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

**More to read :**
* [In-place algorithm | Wikipedia](https://en.wikipedia.org/wiki/In-place_algorithm)
