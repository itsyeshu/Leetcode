#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:

    void reversePortion(vector<int>& nums, int startIndex, int lastIndex){
        for(int i{startIndex}; i <= (lastIndex + startIndex) / 2; i++){
            std::swap(nums[i], nums[lastIndex + startIndex - i]);
        }
    }

    void rotate_withReversing(vector<int>& nums, int k) {
        int lastIndex = nums.size() - 1;
        reversePortion(nums, 0, lastIndex - k);
        reversePortion(nums, lastIndex - k + 1, lastIndex);
        reversePortion(nums, 0, lastIndex);
    }

    void rotate_withoutReversing(vector<int>& nums, int k) {
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
    
    void printArray(vector<int>& array){
        for(int i : array){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    Solution(){
        vector<int> nums {1,2,3,4,5,6,7};
        int k = 3;

        // Uncomment one of the below comment blocks at a time
        /*
        // With reversing the given array at breakpoint "k"
        */
        rotate_withReversing(nums, k);

        /*
        // Without reversing the given array at breakpoint "k"
        rotate_withoutReversing(nums, k);
        */

        printArray(nums); // 5 6 7 1 2 3 4
    }
};

int main(){
    Solution sol;
    return 0;
}