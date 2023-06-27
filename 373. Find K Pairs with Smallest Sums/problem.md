# 373. Find K Pairs with Smallest Sums

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/).
<!-- Badges -->
![Leetcode medium level problem](https://img.shields.io/badge/Medium-ffc01e)
![Queue Tag](https://img.shields.io/badge/Queue-cfcfcf) ![minHeap Tag](https://img.shields.io/badge/minHeap-cfcfcf) ![Arrays Tag](https://img.shields.io/badge/Arrays-cfcfcf)

## Question statement

You are given two integer arrays `nums1` and `nums2` sorted in **ascending order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return the `k` pairs `(u1, v1), (u2, v2), ..., (uk, vk)` with *the smallest sums*.

## Example:
**Input:**
    nums1 = [1,7,11], nums2 = [2,4,6], k = 3

**Output:**
    [ [1,2],[1,4],[1,6] ]

**Explanation:**
The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

**Constraints:**
* `1 <= nums1.length, nums2.length <= 10⁵`
* `-10⁹ <= nums1[i], nums2[i] <= 10⁹`
* `nums1` and `nums2` both are sorted in *ascending order*.
* `1 <= k <= 10⁴`
