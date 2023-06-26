#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

class Solution {
public:
    int hIndex(vector<int>& citations);

    // Helper functions
    void printArray(vector<int>& nums, int start, int length);
    Solution(){
        // Input
        vector<int> citations = {1, 3, 1};

        hIndex(citations); // 3
    }
};

int main(){
    Solution sol;
    return 0;
}

// Helper functions
void Solution::printArray(vector<int>& nums, int start, int length){
    for(int i{}; i<length; i++){
        std::cout << nums[i + start] << " ";
    }
    std::cout << std::endl;
}

// SOLUTIONS **************************************************

// Optimal solution - using Hashmap
int Solution::hIndex(vector<int>& citations){
    // Citations : |1|3|1|

    vector<int> papers(1001, 0);
    // Papers    : |0|0|0|0|0|...|0|

    std::cout << "Papers    : ";
    printArray(papers, 0, 8);
    
    for(int citation : citations){
        papers[citation]++;
    }
    // Papers    : |0|2|0|1|0|...|0|
    std::cout << "Papers    : ";
    printArray(papers, 0, 8);

    for(int i=papers.size() - 2; i>=0; i--){
        papers[i] += papers[i+1];
    }

    int h_index = papers.size() - 1;
    while(papers[h_index] < h_index){
        h_index--;
    }
    h_index = std::max(h_index, 0);
    // Papers    : |3|3|1|1|0|...|0|
    //                ^
    //            h-index (1)

    std::cout << "Papers    : ";
    printArray(papers, 0, 8);

    int spaces = 2*h_index + 12;
    while(spaces--){
        std::cout << " ";
    }
    std::cout << "^" << std::endl;
    spaces = 2*h_index - 4 + 12;
    while(spaces--){
        std::cout << " ";
    }
    std::cout << "h-index (" << h_index << ")" << std::endl;

    return h_index;
}