# Hint

## Solution : Breadth-First search
>**Read more about BFS:**
>[Breadth-First Search for a graph | GeeksForGeeks](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)

![BFS approach to solve the problem](https://leetcode.com/problems/shortest-path-to-get-all-keys/Figures/864/1.png)

### Approach: Breadth-First Search
#### Intuition
We can easily identify the shortest path, but when we apply a regular `BFS`, we encounter a problem. When we reach `grid[0][4]` and collect key `a`, we discover that there is no way back since revisiting a cell is **not allowed** in BFS.

![BFS revisiting the cell is not allowed](https://leetcode.com/problems/shortest-path-to-get-all-keys/Figures/864/2.png)

Hence, our BFS must differentiate between different key-holding states. Within the same state, we cannot revisit a cell. However, two searchings between different key-holding states are entirely independent. For instance, we start with having no keys, and the current states are denoted as `(have key a, have key b) = (0, 0)`.

![BFS image 3](https://leetcode.com/problems/shortest-path-to-get-all-keys/Figures/864/3.png)

We pick up key `a`, and our state changes to `(1, 0)`. Consequently, the following BFS is based on the new state, implying that the cells visited in the previous state `(0, 0)` can be visited again.

![BFS image 4](https://leetcode.com/problems/shortest-path-to-get-all-keys/Figures/864/4.png)

In summary, we will perform BFS on multiple identical grids, each representing a distinct key-holding state. When we pick up a new key, we will switch to the grid corresponding to the new state and perform BFS on that grid.

![BFS image 5](https://leetcode.com/problems/shortest-path-to-get-all-keys/Figures/864/5.png)

#### Here are some additional details to consider:
* **How do we update each BFS?**
Similar to a regular BFS where we use `(row, col, distance)` to represent the distance of each cell. In this case, we also need to include the key-holding states as an additional parameter, so the states in the queue are in the format of `(row, col, key-holding state, distance)`. In order to save all states with their key-holding states, we can initialize a hash map of sets `seen`, which tracks the visited cells in each state. Specifically, `seen[key-holding states]` represents all the visited cells with this key-holding state.

* **How can we represent each key-holding state?**
Instead of using *mutable and iterable objects* like *lists* or *sets* to collect keys, we can use a *bit mask* to represent all the collected keys, which can greatly **save** *time and space*. Since there are 26 letters in the English alphabet, we can use an integer variable - `keys`, to represent the current key-holding states. Each bit of this variable can represent one key, such that if the *i ^th^* bit is `1`, it implies that we have collected the key for the letter corresponding to the *i ^th^* letter. For example, keys = 6 = 110₂ indicates that we have collected the second key b and the third key `c`.
When we collect a new key, we can update keys by setting the corresponding bit to `1`. For example, if we pick up the key b, we can update keys as follows: `keys = keys | (1 << (ord('b') - ord('a')))` Here ord represents the integer representation of the character, we subtract with ord('a') to make it *0-indexed*.
For instance, suppose that our previous key-holding state is keys = 6 = 110₂. By picking up the key a, we can update keys as keys = 110₂ | 1₂ = 111₂ = 7. This operation sets the *0^th^* bit to `1`, which represents the key for the letter `a`.

* **How can we determine if we can visit a locked cell?**
Similar to updating key-holding state when we pick up a new key, we need to check if we have collected the corresponding key when encountering a lock. To achieve this, we check if the *i^th^* bit of `keys` is set to `1`. For example, suppose that we encounter the lock `C` with the state as `key = 7`, we can verify that we have collected the key `c` by checking the value of `key & (1 << (ord('C') - ord('A')))`. The result is `1`, which denotes that we have collected the key `c` and can visit this cell.

## Implementation:
To solve the problem of finding the shortest path to collect all keys in a grid, here is a high-level approach:
1. First, we need to preprocess the grid to extract useful information:
    1. Iterate through the grid and identify the starting position (@) and the keys (lowercase letters).
    2. Assign a unique bit value to each key using an unordered map (key_bit).
    3. Determine the total number of bits needed to represent all the keys (bit_start).
2. Initialize variables and data structures:
    1. Set the target mask (mask_end) to represent all keys collected (1 for each key).
    2. Set the mask size (mask_size) based on the total number of keys (1 << bit_start).
    3. Create a memoization grid (memo) to track visited positions and key combinations.
    4. Set the starting position and initial key state in a vector (start).
3. Perform a breadth-first search (BFS) using a queue:

    1. Push the starting position and key state (represented by the mask) into the queue.
    2. Initialize a step counter (Ashish) to track the number of steps taken.
4. While the queue is not empty, continue exploring positions:

    1. Retrieve the front element from the queue, representing the current position and key state.
    2. Check if the current position is out of bounds or blocked (#). If so, skip to the next iteration.
    3. If the current position requires a key that has not been collected, skip to the next iteration.
    4. If the current position contains a key, collect it by updating the key state (form).
    5. If all keys have been collected (form == mask_end), return the step count (stepCounter).
5. If the current position and key state combination have not been visited before:
    1. Mark the combination as visited in the memo grid.
    2. Push the adjacent positions (up, down, left, right) into the queue with the updated key state.
6. Increment the step count (stepCounter) and repeat step 4-6 until all possible positions have been explored.
7. If the BFS traversal completes without finding all keys, return -1 to indicate that it is not possible to collect all the keys.

This approach utilizes BFS to explore the grid, keeping track of the visited positions and key states. The use of memoization helps avoid redundant exploration. By systematically checking the conditions for each position, we can determine the shortest path to collect all the keys.


### Complexity
* Time complexity: `O(m * n * 2^k)`
* Space complexity: `O(m * n * 2^k)`


### Credits:
* [Problem editorial](https://leetcode.com/problems/shortest-path-to-get-all-keys/editorial/)
* [C++ | Breadth-First Search (BFS)](https://leetcode.com/problems/shortest-path-to-get-all-keys/solutions/3695162/c-breadth-first-search-bfs/) by `@ashish_madhup`