#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<unordered_set>

using std::vector;
using std::priority_queue;
using std::queue;
using std::pair;
using std::string;
using std::unordered_set;

class Solution {
public:

    struct State {
        int keys, i, j;
        State(int keys, int i, int j) : keys(keys), i(i), j(j) {}
    };
    int shortestPathAllKeys(vector<string>& grid);

    // Helper functions
    void printArray(vector<int>& nums, int start, int length);
    Solution(){
        vector<string> grid = {"@.a..","###.#","b.A.B"};
        std::cout << shortestPathAllKeys(grid) << std::endl;
    }
};

int main(){
    Solution sol;
    return 0;
}


// Helper functions
void Solution::printArray(vector<int>& nums, int start, int length){
    for(int i{}; i<length; i++){
        std::cout << nums[i + start] << " ";
    }
    std::cout << std::endl;
}

// SOLUTIONS **************************************************
// Uncomment any solution comment block (one at a time)

/*
// Solution 1
// Using Breadth-First search
// Time Complexity  : O(Grid.length * Grid[0].length * 2^(number of keys))
// Space Complexity : O(Grid.length * Grid[0].length * 2^(number of keys))

*/

int Solution::shortestPathAllKeys(vector<string>& grid) {
    int x = -1, y = -1, m = grid.size(), n = grid[0].length(), totalKeys = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c = grid[i][j];
            if (c == '@') {
                x = i;
                y = j;
            }
            if (c >= 'a' && c <= 'f') {
                totalKeys++;
            }
        }
    }
    State start(0, x, y);
    queue<State> q;
    unordered_set<string> visited;
    visited.insert(std::to_string(0) + " " + std::to_string(x) + " " + std::to_string(y));
    q.push(start);
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            State cur = q.front();
            q.pop();
            if (cur.keys == (1 << totalKeys) - 1) {
                return step;
            }
            for (auto dir : dirs) {
                int i = cur.i + dir[0];
                int j = cur.j + dir[1];
                int keys = cur.keys;
                if (i >= 0 && i < m && j >= 0 && j < n) {
                    char c = grid[i][j];
                    if (c == '#') {
                        continue;
                    }
                    if (c >= 'a' && c <= 'f') {
                        keys |= 1 << (c - 'a');
                    }
                    if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) {
                        continue;
                    }
                    if (visited.find(std::to_string(keys) + " " + std::to_string(i) + " " + std::to_string(j)) == visited.end()) {
                        visited.insert(std::to_string(keys) + " " + std::to_string(i) + " " + std::to_string(j));
                        q.push(State(keys, i, j));
                    }
                }
            }
        }
        step++;
    }
    return -1;
}