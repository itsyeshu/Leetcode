# 1514. Path with Maximum Probability

>**Note :**
>1. This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/path-with-maximum-probability/description/).
>2. This problem is the Daily LeetCoding Challenge for June, Day 29.
<!-- Badges -->
![Leetcode hard level problem](https://img.shields.io/badge/Hard-ff375f?logo=leetcode&labelColor=fff)
^Tags:^
![Array Tag](https://img.shields.io/badge/Array-cfcfcf) ![Bit manipulation Tag](https://img.shields.io/badge/Bit_manipulation-cfcfcf) ![Graph Tag](https://img.shields.io/badge/Graphs-cfcfcf) ![Breadth-First Search Tag](https://img.shields.io/badge/Breadth_%2D%2D_First_Search-cfcfcf) ![Matrix Tag](https://img.shields.io/badge/Matrix-cfcfcf)

## Question statement

You are given an m x n grid grid where:
- '.' is an empty cell.
- '#' is a wall.
- '@' is the starting point.
- Lowercase letters represent keys.
- Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions(Up, down, Right, Left). You ***cannot*** *walk outside the grid*, or *walk into a wall*.

If you walk over a `key`, you can pick it up and you cannot walk over a `lock` unless you have its corresponding `key`.

For some `1 <= k <= 6`, there is **exactly one** lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is **exactly one** `key` for each `lock`, and one `lock` for each `key`; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the *lowest* number of moves to acquire all keys. If it is impossible, return `-1`.

## Example:
![Example Grid image](https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg)
**Input:**
    grid = ["@.a..","###.#","b.A.B"]

**Output:**
    8

**Explaination:**
    Note that the goal is to obtain all the keys not to open all the locks.

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 30`
* `grid[i][j]` is either an English letter, `.`, `#`, or `@`.
* The number of keys in the grid is in the range `[1, 6]`.
* Each key in the grid is **unique**.
* Each key in the grid has a matching lock.