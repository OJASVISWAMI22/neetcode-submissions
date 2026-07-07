class MyHashSet {
    vector<vector<int>>buckets;
    int size=1009;
public:
    MyHashSet() {
        buckets.resize(size);
    }
    
    void add(int key) {
        int h=key%size;
        for(int i:buckets[h]){
            if(i==key)
            return;
        }
        buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h=key%size;
        auto &tmp=buckets[h];
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]==key){
                tmp.erase(tmp.begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h=key%size;
        for(int i:buckets[h]){
            if(i==key)
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */