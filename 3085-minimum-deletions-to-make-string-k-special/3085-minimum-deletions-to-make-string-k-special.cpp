class Solution {
public:
    //IMP

    int minimumDeletions(string word, int k) {
        vector<int>f(26,0);

        for(int i=0; i<word.size();i++){
            f[word[i]-'a']++;
        }

        vector<int> arr;
        for (int x : f)
            if (x > 0)
                arr.push_back(x);
 
        int res=word.length();

        for(int i=0; i<arr.size();i++){
            int del = 0;

            for(int j=0; j<arr.size();j++){
                if(i==j)continue;

                if(arr[j]<arr[i]){
                    del+=arr[j];// arr[i]=4 and arr[j]=1, toh 1 ko hata do
                }
                else if(abs(arr[j]-arr[i]>k)){
                    del+=abs(arr[j]-arr[i]-k);
                }
            }
            res=min(res,del);

        }
        return res;
    }
};