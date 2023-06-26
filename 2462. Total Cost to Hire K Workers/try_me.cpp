#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int n);
    Solution(){
        vector<int> costs = {17,12,10,2,7,2,11,20,8};
        int k = 3, no_of_candidates = 4;
        std::cout << totalCost(costs, k, no_of_candidates) << std::endl; // 11
    }
};

// Calculate total Cost
long long Solution::totalCost(vector<int>& costs, int k, int n) {
    int i = 0;
    int j = costs.size() - 1;

    // Using Priority queue for min Heap
    priority_queue<int, vector<int>, greater<int>>candidatesFromFront, candidatesFromBack;

    long long hiringCost = 0;
    while(k--){
        while(candidatesFromFront.size() < n && i <= j){
            candidatesFromFront.push(costs[i++]);
        }
        while(candidatesFromBack.size() < n && i <= j){
            candidatesFromBack.push(costs[j--]);
        }

        int candidateWithLowestCostFromFront = !candidatesFromFront.empty() ? candidatesFromFront.top() : INT_MAX;
        int candidateWithLowestCostFromBack = !candidatesFromBack.empty() ? candidatesFromBack.top() : INT_MAX;

        if(candidateWithLowestCostFromFront <= candidateWithLowestCostFromBack){
            hiringCost += candidateWithLowestCostFromFront;
            candidatesFromFront.pop();
        }
        else{
            hiringCost += candidateWithLowestCostFromBack;
            candidatesFromBack.pop();
        }
    }
    return hiringCost;
}

int main(){
    Solution sol;
    return 0;
}