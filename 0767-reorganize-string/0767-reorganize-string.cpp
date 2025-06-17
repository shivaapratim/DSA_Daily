class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;

        int maxi=0;
        int running_sum=0;

        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            maxi= max(maxi, mp[s[i]]);
        }

        int rem_sum=s.length()-maxi;

        if(rem_sum<maxi-1)return "";

        priority_queue<pair<int,char>, vector<pair<int,char>>>pq;

        for(auto it: mp){
            char u= it.first; 
            int v= it.second;

            pq.push({v,u});
        }

        string ans="";

        while(!pq.empty()){
            int  fitop= pq.top().first;
            char ftop= pq.top().second;
            
            pq.pop();

            if(pq.empty()){
                ans.push_back(ftop);
                break;
            }
            int  sitop= pq.top().first;
            char stop= pq.top().second;
            
            pq.pop();

            ans.push_back(ftop);
            ans.push_back(stop);

            fitop--;
            sitop--;

            if(fitop>0){
                pq.push({fitop,ftop});
            }

            if(sitop>0){
                pq.push({sitop,stop});
            }  
        }

        return ans;

    }
};