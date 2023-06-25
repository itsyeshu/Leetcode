class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canReach = nums[0];
        if(n<=1) return true;
        for(int i{1};i<n;i++){
            if(canReach < i) return false; // Can't reach Index 'i'
            else if(i>=n-1) return true;
            canReach = std::max(canReach, i + nums[i]);
        }
        return true;
    }
};