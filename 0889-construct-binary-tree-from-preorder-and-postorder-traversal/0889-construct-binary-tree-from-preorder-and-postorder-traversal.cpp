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
    //Imp

    //Pre ka next humesha left side of tree btayega
    //Toh pre ke next(+1) ko post me dhudh lo or usse pehle vaalon ki tree bna do recursion use krke same
    //Right ke liye prestart+number of nodes+1
    //Or j ka next hai poststart.

    TreeNode*solve(int prestart, int poststart, int preend, vector<int>&preorder, vector<int>&postorder, unordered_map<int,int>&mp){
        if(prestart>preend){
            return NULL;
        }

        TreeNode*root=new TreeNode(preorder[prestart]);
        if(prestart==preend)return root;// This is for the outer bound condition...Like if prestart+1 exceeds the range of array

        int nextnode=preorder[prestart+1];

        int j=mp[nextnode];

        int num= j-poststart+1;//right

        root->left=solve(prestart+1,poststart,prestart+num,preorder,postorder,mp);
        root->right=solve(prestart+num+1,j+1,preend,preorder,postorder,mp);

        return root;

    }



    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[postorder[i]]=i;
        }

        return solve(0,0,n-1,preorder,postorder,mp);
    }
};