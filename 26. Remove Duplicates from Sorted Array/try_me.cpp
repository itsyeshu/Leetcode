#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:

    /*
     * This kind of solution is known as "Two-pointer algorithm"
     * Read more at https://leetcode.com/articles/two-pointer-technique/.
    */

    int removeDuplicates(vector<int>& nums) {
        int last_occurence{};
        
        for(int i{1}; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                last_occurence++;
                nums[last_occurence] = nums[i];
            }
        }

        return ++last_occurence;
    }

    void printArray(vector<int>& array, int end){
        for(int i{}; i< array.size(); i++){
            if(i >= end) std::cout << "_ ";
            else std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    Solution(){
        vector<int> nums {1, 1, 2};
        printArray(nums, removeDuplicates(nums));
    }
};

int main(){
    Solution sol;
    return 0;
}