class Solution {
public:
    void convert(vector<int>&arr, string i){
        int number = stoi(i, nullptr, 2);
        arr.push_back(number);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        for(int i=0; i<nums.size();i++){
            convert(arr,nums[i]);
        }   
        
        int n = nums[0].length();   
        
        for(int i=0; i<arr.size()-1;i++){
            if(arr[i]+1!=arr[i+1]){
                string result = bitset<32>(arr[i]+1).to_string();
                return result.substr(32 - n);  
            }
        }

        string result = bitset<32>(arr.back()+1).to_string();
        return result.substr(32 - n);   
    }
};