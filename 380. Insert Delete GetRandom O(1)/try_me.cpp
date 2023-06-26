#include<iostream>
#include<iomanip> // IO manipulator

#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> ar;

    bool insert(int val);
    bool remove(int val);
    int getRandom();

    // Helper functions
    void printArray(vector<int>& nums, int start, int length);

    // Constructor
    RandomizedSet() {
        std::cout << std::boolalpha << "[";
        std::cout << "null, " << 
            insert(1) <<   ", " <<
            remove(2) <<   ", " <<
            insert(2) <<   ", " <<
            getRandom() << ", " <<
            remove(1) <<   ", " <<
            insert(2) <<   ", " <<
            getRandom() << "]" << std::endl;

            // [null, true, false, true, 2, true, false, 2]
    }
};

int main(){
    RandomizedSet set;
    return 0;
}

// Helper functions
void RandomizedSet::printArray(vector<int>& nums, int start, int length){
    for(int i{}; i<length; i++){
        std::cout << nums[i + start] << " ";
    }
    std::cout << std::endl;
}

// SOLUTION **************************************************

bool RandomizedSet:: insert(int val){
    if(mp.find(val) == mp.end()){
        ar.push_back(val);
        mp[val] = ar.size()-1;
        return true;
    }
    return false;
}

bool RandomizedSet:: remove(int val) {
    if(mp.find(val) != mp.end()){
        auto index = mp.find(val);
        // ar.pop(mp[val]); // is O(N) average alorithm
        // Way to remove an index with O(1) average time
        ar[mp[val]] = ar.back();
        ar.pop_back();
        mp[ar[index->second]] = index->second; 
        mp.erase(val);
        return true;
    }
    return false;
}

int RandomizedSet:: getRandom() {
    if(ar.size() > 0){
        int index = std::rand() % ar.size();
        return ar[index];
    }
    return -1;
}