class Solution {
public:
    // set<string>st;

    // void solve(string&curr, vector<bool>&used, string&tiles){
        
    //     st.insert(curr);

    //     for(int i=0; i<tiles.size(); i++){
    //         if(used[i])continue;

    //         curr.push_back(tiles[i]);
    //         used[i]=true;
    //         solve(curr,used,tiles);

    //         //Undo
    //         curr.pop_back();
    //         used[i]=false;
    //     }
    //     return;
    // }


    int n=0;
    void solve(vector<int>&v, int&cnt){
        cnt++;

        for(int i=0; i<26; i++){
            if(v[i]==0)continue;    
            v[i]--;
            solve(v,cnt);
            v[i]++;
        }
        return;
    }


    int numTilePossibilities(string tiles) {
       
        n=tiles.size();
        
        // vector<bool>used(n,false);

        // string curr="";
        // solve(curr,used,tiles);
        // return st.size()-1; //Exculed the empty sequence


        //2nd approach

        vector<int>v(26);
        for(int i=0; i<tiles.size();i++){
            v[tiles[i]-'A']++;
        }
        int cnt=0;
        solve(v,cnt);
        return cnt-1;
        
    }
};