

/*
// Using Reverse method

class Solution {
public:

    void reversePortion(vector<int>& nums, int startIndex, int lastIndex){
        for(int i{startIndex}; i <= (lastIndex + startIndex) / 2; i++){
            std::swap(nums[i], nums[lastIndex + startIndex - i]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int lastIndex = nums.size() - 1;
        reversePortion(nums, 0, lastIndex - k);
        reversePortion(nums, lastIndex - k + 1, lastIndex);
        reversePortion(nums, 0, lastIndex);
    }
};

*/

/*
// Without using Reverse method

*/
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