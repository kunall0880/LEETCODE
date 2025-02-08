class NumberContainers {
public:
    unordered_map<int,int>idxnum;
    unordered_map<int,set<int>>numidx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxnum.count(index)){
            int prev=idxnum[index];
            numidx[prev].erase(index);
            if(numidx[prev].empty()){
                numidx.erase(prev);
            }
        }
        idxnum[index]=number;
        numidx[number].insert(index);
    }
    
    int find(int number) {
        if(numidx.count(number)){
            return *numidx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */