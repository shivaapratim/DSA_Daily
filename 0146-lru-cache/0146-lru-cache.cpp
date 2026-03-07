class LRUCache {
public:
//Simple queue won't work because if suppose k3 was the operation i inserted a long time
//ago but i wanted it(get) then if the capacity is filled it will remove k3 which i just used
//but it was present in the first

// q3...q1...q2...q4...q3-> as i used q3 at last it will still remove q3 once the capacity
//gets filled.


    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mp; // key,{address,value}
    int n;

    LRUCache(int capacity) {
        n=capacity;
    }

    void mostrecent(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        //Erase krke front pe le aao means freshly use hua hai
        mostrecent(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            mostrecent(key);
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            int key_del=dll.back();
            mp.erase(key_del);
            dll.pop_back();//Buzurg log
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */