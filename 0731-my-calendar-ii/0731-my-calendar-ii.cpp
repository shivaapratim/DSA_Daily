class MyCalendarTwo {
public:
    vector<pair<int,int>>events;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int a = startTime;
        int b= endTime;
        events.push_back({a,1});
        events.push_back({b,-1});

        sort(events.begin(),events.end());

        int sum=0;

        for(auto it: events){
            sum+=it.second;
            if(sum>2){
                
                auto it1 = find(events.begin(), events.end(), make_pair(a, 1));
                if(it1 != events.end()) events.erase(it1);

                auto it2 = find(events.begin(), events.end(), make_pair(b, -1));
                if(it2 != events.end()) events.erase(it2);

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */