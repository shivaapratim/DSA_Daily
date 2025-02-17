// class Solution {
// public:
//     int minGroupsForValidAssignment(vector<int>& balls) {
//         unordered_map<int,int>mp;
//         for(int i=0; i<balls.size();i++){
//             mp[balls[i]]++;
//         }
//         int mini=INT_MAX;
//         for(auto it: mp){
//             if(it.second<mini){
//                 mini=it.second;
//             }
//         }
//         int cnt=0;
//         for(auto&it:mp){
//             if(it.second==mini){
//                 cnt++;
//             }
//             else{
//                 cnt= cnt+(it.second/(mini+1));
//                 if(it.second%(mini+1)!=0)cnt++;
//             }
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int,int>mp;
        for(int i=0; i<balls.size();i++){
            mp[balls[i]]++;
        }
        int mini = INT_MAX;
        for(auto it: mp){
            if(it.second < mini){
                mini = it.second;
            }
        }
        
        int finalAns = INT_MAX;
        
        for(int x = 1; x <= mini; x++) {
            bool possible = true;
            int groupSum = 0;
            
            for(auto& it: mp) {
                int freq = it.second;
                int a = freq/(x+1);  
                int b = freq%(x+1);  
                
                if(b == 0) {
                    groupSum += a;
                }
                else if(x - b <= a) {
                    groupSum += (a + 1);
                }
                else {
                    possible = false;
                    break;
                }
            }
            
            if(possible) {
                finalAns = min(finalAns, groupSum);
            }
        }
        
        return finalAns;
    }
};