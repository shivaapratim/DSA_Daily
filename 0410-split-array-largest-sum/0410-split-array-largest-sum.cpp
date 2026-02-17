class Solution {
public:
    
int ispossible(vector<int> &arr, int mid){
	int count=1;
	int sum=0;
	for(int i=0; i<arr.size(); i++){
		if(sum+arr[i]>mid){
		
			sum=arr[i];
				count++;
		}
		else{
			sum+=arr[i];
		}
	}
	return count;
}

int splitArray(vector<int> &arr, int k) {
	int low= *max_element(arr.begin(),arr.end());
	int high= accumulate(arr.begin(),arr.end(),0);
	int ans=low;
	while(low<=high){
		int mid=(low+high)/2;
		if(ispossible(arr,mid)>k){
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
		}
	}

return ans;

}

};

