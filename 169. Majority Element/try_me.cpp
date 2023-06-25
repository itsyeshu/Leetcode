#include<iostream>
#include<vector>
#include<unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
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
        std::cout << majorityElement(nums) << std::endl; // 3
    }
};

int main(){
    Solution sol;
    return 0;
}