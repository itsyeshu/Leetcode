class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_copy{m-1}, n_copy {n-1};
        while(m_copy>=0 && n_copy>=0){
            if(nums1[m_copy] > nums2[n_copy]){
                nums1[m_copy + n_copy + 1] = nums1[m_copy];
                m_copy--;
            }else{
                nums1[m_copy + n_copy + 1] = nums2[n_copy];
                n_copy--;
            }
        }
        while(n_copy>=0){
            nums1[n_copy] = nums2[n_copy];
            n_copy--;
        }
    }

    void printArray(vector<int>& array){
        for(int i : array){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

};