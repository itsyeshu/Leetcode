#include<iostream>
#include<vector>
// #include<iomanip>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canReach = nums[0];
        if(n<=1){
                std::cout << "You've reached your destination at index : " << n - 1 << std::endl;
            return true;
        }else{
            std::cout << "At index : 0" << " and can reach upto index : " << canReach << std::endl;
        }
        for(int i{1};i<n;i++){
            // Can't reach Index 'i'
            if(canReach < i){
                std::cout << "Sorry! You can't index : " << i << std::endl << std::endl;
                return false;
            }else if(i>=n-1){
                std::cout << "You've reached your destination at index : " << i << std::endl << std::endl;
                return true;
            }else{
                std::cout << "At index : " << i << " and can reach upto index : " << canReach << std::endl;
            }
            canReach = std::max(canReach, i + nums[i]);
        }
        return true;
    }

    Solution(){
        vector<int> nums {3, 2, 1, 0, 4};

        std::cout << std::boolalpha;
        std::cout << canJump(nums) << std::endl; // false
    }
};

int main(){
    Solution sol;
    return 0;
}