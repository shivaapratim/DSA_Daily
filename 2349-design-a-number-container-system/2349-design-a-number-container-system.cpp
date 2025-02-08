class NumberContainers {
public:
    unordered_map<int,int>mp;// Easy access than vectors
    unordered_map<int,set<int>>sp;// To store sorted way
   

    NumberContainers() {
        //Clear..not necessary..Leave constructor.
    }
    
    void change(int index, int number) {
        if(mp.count(index)){
            int prev= mp[index];// Take value from mp and
            sp[prev].erase(index);// delete it from sp->set

            if(sp[prev].empty()){
                sp.erase(prev); // If the number occurence(index) become 0 we no longer need it
            }
        }
        //Inserting new values
        mp[index]=number;
        sp[number].insert(index);
    }
    
    int find(int number) {
        if(sp.count(number)){// Finding number in the map, and then giving first iteration as result from set
            return *sp[number].begin();
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