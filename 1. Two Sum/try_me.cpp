#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);

    // Helper functions
    void printArray(vector<int>& nums, int start, int length);
    Solution(){
        // Input
        vector<int> nums = {2,7,11,15};
        int target = 9;
        vector<int> ans = twoSum(nums, target);
        printArray(ans, 0, ans.size()); // {0, 1}
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
// Brute-force solution

vector<int> Solution::twoSum(vector<int>& nums, int target){
    vector<int> ans(2);
    int size = nums.size();
    int i{}, j{};
    for(; i<size; i++){
        bool found = false;
        for(j = i+1; j<size; j++){
            if(nums[i] + nums[j] == target){
                found = true;
                break;
            }
        }
        if(found) break;
    }
    ans = {i, j};

    return ans;
}
*/

/*
// Optimal solution - using Hashmap
*/
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    int n=nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int key=nums[i];
        if(mp.count(target - key)){
            ans.push_back(mp[target - key]);
            ans.push_back(i);
            break;
        }else{
            mp[key] = i;
        }
    }
    return ans;
}