class StockSpanner {
public:
    //Here count cannot be used because it will shorten the calculations if pop is done
    //Rather take an array and do things on it with indexes also 
    //Take stack<pair<int,int>>

    vector<int>ans;
    stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int index = ans.size() - 1;

        while(!st.empty() && st.top().first<=price)st.pop();
        
        
        int span = st.empty() ? (index + 1) : (index - st.top().second);
        
        st.push({price,index});

        return span;
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */