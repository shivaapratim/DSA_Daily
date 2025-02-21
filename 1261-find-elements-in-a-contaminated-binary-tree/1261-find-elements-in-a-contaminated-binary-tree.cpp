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
class FindElements {
public:
    TreeNode*root;

    void recover(TreeNode*root,int t){
        if(!root)return;

        root->val=t;

        recover(root->left,2*t+1);
        recover(root->right,2*t+2);
    }


    bool search(TreeNode*root, int target){
        if(root==NULL)return false;

        if(root->val==target)return true;

        return search(root->left,target) || search(root->right,target);
    }

    FindElements(TreeNode* root) {
       this->root=root;
       if(root){
          recover(root,0);
       }
    }
    
    bool find(int target) {
       return search(root,target);
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */