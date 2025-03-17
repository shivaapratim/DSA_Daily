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

    TreeNode* solve(TreeNode*&root, int target){

        if(root==NULL)return NULL;

        root->left=solve(root->left,target);
        root->right=solve(root->right,target);
       

        if(!root->left && !root->right && root->val==target){//Leaf node
            return NULL;
        }
        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //I think postorder can help. It first goes to left if left==target then it will be
        // deleted and same for right, then at last main parent node will be accessed. 
        return solve(root,target); 
    }
};