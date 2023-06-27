#include<iostream>
#include<vector>
#include<queue>
#include <utility>

using std::vector;
using std::priority_queue;
using std::pair;
using std::greater;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

    // Helper functions
    void print2dArray(vector<vector<int>>& arr);
    Solution(){
        vector<int> nums1 = {1,7,11};
        vector<int> nums2 = {2,4,6};
        int k = 3;
        vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);
        print2dArray(ans); // [[1, 2], [1, 4], [1, 6]]
    }
};

// Helper functions
void Solution::print2dArray(vector<vector<int>>& arr){
    std::cout << "[";
    for(int i{}; i<arr.size(); i++){
        if(i==0) std::cout << "[";
        else std::cout << ", [";
        for(int j{}; j<arr[0].size(); j++){
            if(j==0) std::cout << "";
            else std::cout << ", ";
            std::cout << arr[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]";
}


int main(){
    Solution sol;
    return 0;
}


// SOLUTION ************************************************

// Using minHeap (Implementation using Priority Queue)
vector<vector<int>> Solution:: kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans; // Result vector to store the pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Priority queue to store pairs with smallest sums, sorted by the sum

    // Push the initial pairs into the priority queue
    for(int x : nums1) {
        pq.push({x + nums2[0], 0}); // The sum and the index of the second element in nums2
    }

    // Pop the k smallest pairs from the priority queue
    while(k-- && !pq.empty()) {
        int sum = pq.top().first; // Get the smallest sum
        int pos = pq.top().second; // Get the index of the second element in nums2

        ans.push_back({sum - nums2[pos], nums2[pos]}); // Add the pair to the result vector
        pq.pop(); // Remove the pair from the priority queue

        // If there are more elements in nums2, push the next pair into the priority queue
        if(pos + 1 < nums2.size()) {
            pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
        }
    }

    return ans; // Return the k smallest pairs
}
