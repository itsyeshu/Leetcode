
/*
// Using HashMap

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

*/


/*
// Using Moore's Voting Algorithm

*/
class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int assumed_max_index = 0, count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[assumed_max_index] == nums[i])
                count++;
            else
                count--;
            if (count == 0) {
                assumed_max_index = i;
                count = 1;
            }
        }
        return nums[assumed_max_index];
    }

};