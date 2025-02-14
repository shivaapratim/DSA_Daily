class ProductOfNumbers {
public:
    vector<long long>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        if(ans.size()<2)return ans[0];
        
        long long p=1;
        for(int i=ans.size()-k; i<ans.size(); i++){
            p*=ans[i];
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */