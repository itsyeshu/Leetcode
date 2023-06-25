#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:

    /*
     * This kind of solution is known as "Two-pointer algorithm"
     * Read more at https://leetcode.com/articles/two-pointer-technique/.
    */

    int removeElement(vector<int>& nums, int val){
        int size = nums.size();
        int k{};
        for(int i{}; i<size; i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

    void printArray(vector<int>& array, int end){
        for(int i{}; i< array.size(); i++){
            if(i >= end) std::cout << "_ ";
            else std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    Solution(){
        vector<int> nums {3, 2, 2, 3};
        int val = 3;
        printArray(nums, removeElement(nums, val));
    }
};

int main(){
    Solution sol;
    return 0;
}