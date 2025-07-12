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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>arr;

        if(root==NULL)return{};

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int n= q.size();
            vector<int>temp;

            while(n--){
                
                TreeNode*node= q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }

                if(node->right != nullptr){
                    q.push(node->right);
                }

            }

            arr.push_back(temp);

        }

        reverse(arr.begin(),arr.end());
        return arr;
    }
};