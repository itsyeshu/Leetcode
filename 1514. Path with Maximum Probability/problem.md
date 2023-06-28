# 1514. Path with Maximum Probability

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/path-with-maximum-probability/description/).
<!-- Badges -->
![Leetcode medium level problem](https://img.shields.io/badge/Medium-ffc01e)
^Tags:^
![Queue Tag](https://img.shields.io/badge/Queue-cfcfcf) ![Graph Tag](https://img.shields.io/badge/Graph-cfcfcf) ![Arrays Tag](https://img.shields.io/badge/Arrays-cfcfcf) ![Dynamic programming Tag](https://img.shields.io/badge/Dynamic_Programming-cfcfcf)

## Question statement

You are given an *undirected weighted graph* of `n` nodes **(0-indexed)**, represented by an edge list where `edges[i] = [a, b]` is an undirected edge connecting the nodes `a` and `b` with a probability of success of traversing that edge `succProb[i]`.

Given two nodes `start` and `end`, find the path with the maximum probability of success to go from `start` to `end` and return its *success probability*.

If there is no path from `start` to `end`, return `0`. Your answer will be accepted if it differs from the correct answer by at most `10⁻⁵`.


## Example:
![Undirectional Graph image](https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png)
**Input:**
    n = 3, edges = [ [0,1],[1,2],[0,2] ], succProb = [0.5,0.5,0.2], start = 0, end = 2

**Output:**
    0.25000

**Explaination:**
    There are two paths from start to end, one having a *probability of success = 0.2* and the other has *0.5 * 0.5 = 0.25*.


**Constraints:**
* `2 <= n <= 10⁴`
* `0 <= start, end < n`
* `start != end`
* `0 <= a, b < n`
* `a != b`
* `0 <= succProb.length == edges.length <= 2*10⁴`
* `0 <= succProb[i] <= 1`
* There is at most one edge between every two nodes.
