class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.rbegin(),players.rend());
        sort(trainers.rbegin(),trainers.rend());

        int j=0;

        int ans=0;

        for(int i=0; i<trainers.size();i++){
            
            while(j<players.size() && trainers[i]<players[j]){
                j++;
            }

            if(j==players.size()){
                break;
            }
            
            if(trainers[i]>=players[j]){
                ans++;
                j++;
            }
        }

        return ans;
    }
};