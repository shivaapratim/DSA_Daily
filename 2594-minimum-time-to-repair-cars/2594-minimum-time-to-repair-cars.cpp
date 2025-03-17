class Solution {
public:
    typedef long long ll ;

    long long repairCars(vector<int>& ranks, int cars) {
        //Time = rank*(cars^2)
        //Cars = sqrt((Time/rank))-> floor ofc

        long long s=1; ll e= *min_element(ranks.begin(),ranks.end())*cars;
        e*=cars;
        long long ans=e;
        while(s<=e){
            ll mid= s+(e-s)/2;

            ll isok=0;
            for(auto it: ranks){
                isok+= sqrt(mid/it);
            }
            if(isok>=cars){
                ans=mid;// Means time
                e=mid-1;
            }
            else if(isok<cars){
                s=mid+1;
            }
        }
        return ans;
    }
};