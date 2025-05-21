/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> solve(int start, int end){
        if(start>end){
            return{NULL};
        }
        if(start==end){
            TreeNode*root= new TreeNode(start);
            return {root};
        }

        vector<TreeNode*>ans;

        for(int i=start; i<=end; i++){
            vector<TreeNode*>left_bst = solve(start,i-1); 
            vector<TreeNode*>right_bst= solve(i+1,end);

            for(auto leftRoot: left_bst){
                for(auto rightRoot: right_bst){
                    TreeNode*root= new TreeNode(i);

                    root->left= leftRoot;
                    root->right= rightRoot;

                    ans.push_back(root);
                }    
            }
    
        }
        return ans;
        
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};