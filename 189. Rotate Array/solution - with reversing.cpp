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