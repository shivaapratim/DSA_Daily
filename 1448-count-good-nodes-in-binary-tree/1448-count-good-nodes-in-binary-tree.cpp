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
    int solve(TreeNode*root,int&cnt, int maxi){
        if(root==NULL)return 0;

        if(root->val>=maxi)cnt++;
        maxi=max(maxi,root->val);

        solve(root->left,cnt,maxi);
        solve(root->right,cnt,maxi);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        int cnt=0;
        return solve(root,cnt,INT_MIN);
    }
};