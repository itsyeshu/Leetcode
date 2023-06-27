# 238. Product of Array Except Self

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/).
<!-- Badges -->
![Leetcode medium level problem](https://img.shields.io/badge/Medium-ffc01e)
^Tags:^
![Arrays Tag](https://img.shields.io/badge/Arrays-cfcfcf) ![Dynamic programming Tag](https://img.shields.io/badge/Dynamic_Programming-cfcfcf)

## Question statement

Given an integer array nums, return an array answer such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of nums is *guaranteed* to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## Example:
### Example 1:
**Input:**
    nums1 = [-1,1,0,-3,3]

**Output:**
    [0,0,9,0,0]

### Example 2:
**Input:**
    nums1 = [1,2,3,4]

**Output:**
    [24,12,8,6]


**Constraints:**
* `2 <= nums.length <= 10⁵`
* `-30 <= nums[i] <= 30`
* The product of any prefix or suffix of nums is **guaranteed** to fit in a **32-bit** integer.


## Follow up:
Can you solve the problem in `O(1)` space complexity? 
>**Hint:**
>The output array does not count as extra space for space complexity analysis.