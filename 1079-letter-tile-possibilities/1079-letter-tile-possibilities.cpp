class Solution {
public:
    set<string>st;

    void solve(string&curr, vector<bool>&used, string&tiles){
        
        st.insert(curr);

        for(int i=0; i<tiles.size(); i++){
            if(used[i])continue;

            curr.push_back(tiles[i]);
            used[i]=true;
            solve(curr,used,tiles);

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
        solve(curr,used,tiles);
        return st.size()-1; //Exculed the empty sequence
        
    }
};