class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int n) {
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
};