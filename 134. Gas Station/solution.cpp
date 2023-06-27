class Solution {
public:

// SOLUTIONS **************************************************
// Uncomment any solution comment block (one at a time)

/*
// Solution 1
// Using prefix and suffix product
// Time Complexity  : O(N)
// Space Complexity : O(N)

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> prefixProduct(n);
        vector<int> suffixProduct(n);
        prefixProduct[0] = 1;
        for(int i=1; i<n; i++){
            prefixProduct[i] = prefixProduct[i-1] * nums[i-1];
        }
        suffixProduct[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            answer[i] = prefixProduct[i] * suffixProduct[i];
        }
        return answer;
    }
*/


/*
// Solution 2
// Optimal soltion : using division
// Time Complexity  : O(N)
// Space Complexity : O(1)

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        long int product {1};
        bool hasZero = false;
        for(int num : nums){
            if(num!=0)
                product *= num;
            if(hasZero && num==0) return answer; 
            hasZero = hasZero || (num==0);
        }
        int i{};
        for(int num : nums){
            if(num!=0){
                if(!hasZero) answer[i] = (int)(product/num);
            }else{
                answer[i] = product;
            }
            i++;
        }
        return answer;
    }
*/

/*
// Solution 3
// Optimal soltion : using prefix and suffix product
// Time Complexity  : O(N)
// Space Complexity : O(1)

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        // 1. compute the prefix product and store in answer
        // answer[i] = product of elements in nums from index 0, 1, ... to i - 1
        for (int i = 0; i < n - 1; ++i) {
            answer[i + 1] = nums[i] * answer[i]; 
        }
        // 2. and 3. compute the suffix product and final answer
        int suffixProduct = 1;
        for (int j = n - 1; j > 0; --j) {
            suffixProduct *= nums[j];
            answer[j - 1] *= suffixProduct;
        }
        return answer;
    }
*/


/*
// Solution 4 : Further optimising Solution 3
// Optimal soltion : using prefix and suffix product
// Time Complexity  : O(N)
// Space Complexity : O(1)
*/

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int hasZero = false;
        // 1. compute the prefix product and store in answer
        // answer[i] = product of elements in nums from index 0, 1, ... to i - 1
        for (int i = 0; i < n - 1; ++i) {
            answer[i + 1] = nums[i] * answer[i];
            if(hasZero && !nums[i]) return vector<int> (n, 0);
            hasZero = hasZero || (nums[i] == 0);
        }
        // 2. and 3. compute the suffix product and final answer
        int suffixProduct = 1;
        for (int j = n - 1; j > 0; --j) {
            suffixProduct *= nums[j];
            answer[j - 1] *= suffixProduct;
        }
        return answer;
    }

};