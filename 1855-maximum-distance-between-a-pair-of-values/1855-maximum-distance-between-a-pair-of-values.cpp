class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int tail=0;
        int head=-1;

        int n=nums1.size();
        int m=nums2.size();

        int ans=0;

        while(tail<n && head<m){

            while(head+1<m && nums1[tail]<=nums2[head+1]){
                head++;
            }

            ans=max(ans,head-tail);

            if(tail<=head){
                tail++;
            }

            else if(tail>head){
                tail++;
                head=tail-1;
            }
        }
        return ans;
    }
};