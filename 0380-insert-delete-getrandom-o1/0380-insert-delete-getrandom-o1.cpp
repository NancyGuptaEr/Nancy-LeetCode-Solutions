class RandomizedSet {
    unordered_map<int, int> m;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end())  {
            m[val]=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end())    {
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = m.begin();
        advance(it, rand()%m.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */