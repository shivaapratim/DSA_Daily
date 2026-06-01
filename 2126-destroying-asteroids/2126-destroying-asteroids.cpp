class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());

        long long Psize=mass;

        for(int i=0; i<ast.size(); i++){
            if(Psize<ast[i]){
                return false;
            }
            Psize+=ast[i];
        }
        return true;
    }
};