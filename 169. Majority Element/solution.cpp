class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> occurence_map;
        int size = nums.size();

        int solution;

        for(int num : nums){
            occurence_map[num]++;
        }
        for(auto num : occurence_map){
            if(num.second > size/2) solution = num.first;
        }
        return solution;
    }
};