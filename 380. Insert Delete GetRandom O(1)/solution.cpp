class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> ar;
    RandomizedSet() {
        std::cout << "RandomizedSet constructor called" << std::endl;
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            ar.push_back(val);
            mp[val] = ar.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
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
    
    int getRandom() {
        if(ar.size() > 0){
            int index = std::rand() % ar.size();
            return ar[index];
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */