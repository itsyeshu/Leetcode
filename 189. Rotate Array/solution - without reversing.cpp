class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(!k || !n) return; // No change needed

        int count{}, start{}, current{}, prev{nums[0]};

        while(count < n){
            current = (current + k) % n; // Trimming to fit inside the bounds of the nums array
            
            std::swap(nums[current], prev);
            count++;

            if(current == start){
                start++;
                current = start;
                prev = nums[start];
            }
        }
    }
};