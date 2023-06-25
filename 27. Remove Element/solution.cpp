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

};