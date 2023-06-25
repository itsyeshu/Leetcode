class Solution {
public:

    /*
     * This kind of solution is known as "Two-pointer algorithm"
     * Read more at https://leetcode.com/articles/two-pointer-technique/.
    */

    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        
        int ptr{};
        int i{};
        while(i < nums.size()){
            int count{1};
            while(i+count < nums.size() && nums[i] == nums[i+count]){
                count++;
            }
            int preferred_count = (count>2)?2:count;
            
            // Shifting other elements
            while(preferred_count--){
                nums[ptr + preferred_count] = nums[i];
            }
            preferred_count = (count>2)?2:count;
            ptr += preferred_count;

            i += count;
        }

        return ptr;
    }
};