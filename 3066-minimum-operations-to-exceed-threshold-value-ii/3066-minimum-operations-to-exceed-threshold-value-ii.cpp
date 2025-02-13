class Solution {
public:

    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>,greater<long long>>pq;

        for(int i=0; i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();

            if(a>=k)return ans;

            long long put= (a*2) + b;
            ans++;
            pq.push(put);
        }
        if(pq.top()>=k)return ans;
        return -1;
    }
};