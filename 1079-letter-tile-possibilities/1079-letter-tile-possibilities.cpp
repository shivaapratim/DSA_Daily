class Solution {
public:
    set<string>st;

    void solve(int i, string&curr, vector<bool>&used, string&tiles){
        
        st.insert(curr);

        for(int i=0; i<tiles.size(); i++){
            if(used[i])continue;

            curr.push_back(tiles[i]);
            used[i]=true;
            solve(i+1,curr,used,tiles);

            //Undo
            curr.pop_back();
            used[i]=false;
        }
        return;
    }


    int numTilePossibilities(string tiles) {
       
        int n=tiles.size();
        vector<bool>used(n,false);

        string curr="";
        solve(0,curr,used,tiles);
        return st.size()-1; //Exculed the empty sequence
        
    }
};