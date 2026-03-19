class MyCalendarThree {
public:
    map<int,int>mp;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        
        mp[startTime]++;
        mp[endTime]--;

        int cross=0;
        int temp=0;

        for(auto it: mp){
            temp+=it.second;
            cross=max(cross,temp);
        }

        return cross;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */