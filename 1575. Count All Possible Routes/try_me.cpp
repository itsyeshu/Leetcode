#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    long int solve(vector<int>& locations, int currentCity, int finish, int fuelLeft, vector<vector<int>>& memo){
        // Don't do this, as reiteration is possible
        // if(currentCity == finish) return 1;

        // Unable to find a path to reach "finish" before
        // fuel runs out
        if(fuelLeft < 0) return 0;

        if(memo[currentCity][fuelLeft] != -1){
            return memo[currentCity][fuelLeft];
        }

        int totalRoutes = (currentCity == finish) ? 1 : 0;
        for(int nextCity{}; nextCity<locations.size(); nextCity++){
            if(nextCity != currentCity)
                totalRoutes =  (totalRoutes + solve(
                locations, nextCity, finish,
                fuelLeft - abs(locations[currentCity] - locations[nextCity]), memo)) % 1000000007;
        }
        return memo[currentCity][fuelLeft] = totalRoutes;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel){

        vector<vector<int>> memo(locations.size(), vector<int>(fuel+1, -1));

        return (int)solve(locations, start, finish, fuel, memo) % 1000000007;
    }

    Solution(){
        vector<int> locations = {8, 9, 10};
        int start = 0,
            finish = 2,
            fuel = 3;
        
        std::cout << countRoutes(locations, start, finish, fuel) << std::endl;
    }
};


int main(){
    Solution sol;
    return 0;
}