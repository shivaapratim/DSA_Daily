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
    int n;

    TreeNode* solve(string&s, int&i, int depth){
        if(i>=n){
            return NULL;
        }
        int j=i;
        while(j<n && s[j]=='-'){
            j++;

        }
        int dash= j-i;

        if(dash!=depth){
            return NULL;
        }

        i+=dash;

        int num=0;
        while(i<n && isdigit(s[i])){
            num= num*10 +s[i]-'0';
            i++;
        } 
        TreeNode* root= new TreeNode(num);
        root->left=solve(s,i,depth+1);
        root->right=solve(s,i,depth+1);

        return root;
    }

 
    TreeNode* recoverFromPreorder(string traversal) {
        // Okay so something i can think of is the way preorder works

        //Also the major part is to identify the pattern

        //Which somehow i think is to check the dashes and use them to assign values

        //For example 1-2--3--4 is somehow related in a way that dash successive to 1 is 0
        //And dash successive to 2 is 1 so actually the dash represent the level as well
        //as a reference for other values 

        //The main thing is to identify that when we assign 3 at the left then how to calc for 4

        //Let's take a way that 4's just succsessive dash is --(2) and 3's is same also,
        //So when we get same dashes we go towards one level up meaning that these two 
        //Values connect to a same parent.
        
        //Then when we reach a state where successive dash of 4 is greater than some previous value
        //We make 4 as it's node..and recursion here works like magic cause we have already explored the
        //Left side so it won't go there. And thus the new value(4) will be assigned to right side.

        //Most important pieces are -> How to handle return statements and how to manage parents

        //HAHAHA i dunno why this is giving me a space for DSU but I'll surely not go there!

        n=traversal.length();
        int i=0;
        int depth=0;
        return solve(traversal,i,depth);
        
    }
};














