# 2462. Total Cost to Hire K Workers

>**Note :** This problem can be found at [Leetcode ⧉](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/).
>
>I've changed `candidates` to `n` as `no. of candidates`, so that the question can be easy to understand.
<!-- Badges -->
![Leetcode medium level problem](https://img.shields.io/badge/Medium-ffc01e)

## Question statement

You are given a **0-indexed** integer array costs where `costs[i]` is the cost of hiring the `i`^`th`^ worker.

You are also given two integers `k` and `n` no.of candidates for interview. We want to hire exactly `k` workers according to the following rules:
* You will run `k` sessions and hire exactly one worker in each session.
* In each hiring session, choose the worker with the *lowest cost* from either the first `n` workers or the last `n` workers. Break the tie by the smallest index.
* A worker can only be chosen *once*.
* Return the *total cost* to hire exactly `k` workers.

>**For example:**
>`costs = [3,2,7,7,1,2]` and `n = 2`, then in the first hiring session, we will choose the `4`^th^ worker because they have the lowest cost `[3,2,7,7,`**`1`**`,2]`.
> In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index `[3,`**`2`**`,7,7,`~~`1`~~`,2]`. Please note that the indexing may be changed in the process.
>If there are fewer than `n` workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.

## Example:
**Input:**
    costs = [17,12,10,2,7,2,11,20,8], k = 3, n = 4

**Output:**
    11

**Explanation:**
- We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from `[17,12,10,2,7,2,11,20,8]`. The lowest cost is `2`, and we break the tie by the smallest index, which is `3`. The `total cost = 0 + 2 = 2`.
- In the second hiring round we choose the worker from `[17,12,10,7,2,11,20,8]`. The lowest cost is 2 (index 4). The `total cost = 2 + 2 = 4`.
- In the third hiring round we choose the worker from `[17,12,10,7,11,20,8]`. The lowest cost is `7` (index `3`). The total cost = 4 + 7 = 11. Notice that the worker with index `3` was common in the first and last four workers.
- The total hiring cost is `11`.

**Constraints:**
* `1 <= costs.length <= 10`*^5^*
* `1 <= costs[i] <= 10`*^5^*
* `1 <= k`, `n <= costs.length`

___

**Similar problems :**
* [2532. Time to Cross a Bridge](https://leetcode.com/problems/time-to-cross-a-bridge/)