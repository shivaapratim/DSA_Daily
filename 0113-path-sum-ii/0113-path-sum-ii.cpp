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

    void solve(vector<int>&arr, vector<vector<int>>&ans, TreeNode*root, int k){
        if(root==NULL)return;
       
        arr.push_back(root->val);  
        k-=root->val;  
        
        if(root->left == nullptr && root->right==nullptr && k==0){
            ans.push_back(arr);
        }
        
        solve(arr,ans,root->left,k);
        solve(arr,ans,root->right,k);
        
        arr.pop_back();
         

    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>arr;

        solve(arr,ans,root,targetSum);
        return ans;

    }
};