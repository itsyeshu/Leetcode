#include<iostream>
#include<vector>
// #include<iomanip>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        for(int i{1};i<n;i++){
            nums[i] = std::max(nums[i-1], i + nums[i]);
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        int i{};
        int ans{};
        while(i < n - 1)
        {
          ans++;
          i = nums[i];
        }
        return ans;
    }
    Solution(){
        vector<int> nums {2, 3, 1, 1, 4};
        std::cout << jump(nums) << std::endl; // 2
    }
};

int main(){
    Solution sol;
    return 0;
}