#include<iostream>
#include<vector>
#include<unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
public:
    int majorityElement_MooresVotingAlgorithm(vector<int>& nums) {
        int assumed_max_index = 0, count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[assumed_max_index] == nums[i])
                count++;
            else
                count--;
            if (count == 0) {
                assumed_max_index = i;
                count = 1;
            }
        }
        return nums[assumed_max_index];
    }

    int majorityElement_usingHashMap(vector<int>& nums) {
        unordered_map<int, int> occurence_map;
        int size = nums.size();

        int solution;

        for(int num : nums){
            occurence_map[num]++;
        }
        for(auto num : occurence_map){
            if(num.second > size/2) solution = num.first;
        }
        return solution;
    }

    Solution(){
        vector<int> nums {3, 2, 3};

        // Uncomment each block at a time

        /*
        // Using Hashmap
        */
        std::cout << majorityElement_usingHashMap(nums) << std::endl; // 3

        /*
        // Using Moore's Voting Algorithm
        std::cout << majorityElement_MooresVotingAlgorithm(nums) << std::endl; // 3
        */
    }
};

int main(){
    Solution sol;
    return 0;
}