class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {
        set<string>st;
        set<string>vis;
        queue<string>q;

        for(int i=0; i<bank.size();i++){
            st.insert({bank[i]});
        }

        q.push(s);
        vis.insert(s);
        int level=0;
        while(!q.empty()){
            int n=q.size();

            while(n--){
                
            string temp=q.front();
            q.pop();

            if(temp==e)return level;

                for(char ch: "ACGT"){
                    for(int i=0; i<temp.length();i++){
                        string ne=temp;
                        ne[i]=ch;

                        if(st.find(ne)!=st.end() && vis.find(ne)==vis.end()){
                            vis.insert({ne});
                            st.insert({ne});
                            q.push(ne);
                        }
                    }
                }
            }
            level++;
        }

        return -1; 

    }
};