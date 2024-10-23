/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.
 */
class Solution {
public:
    vector<long long >level;
    void LevelSum(TreeNode* root,int lev){
     if(!root){return;}
     level[lev] += root->val;
     LevelSum(root->left,lev+1);
     LevelSum(root->right,lev+1);
    }
    TreeNode*solve(TreeNode*root,int sibling,int lev){
        root->val = level[lev] - sibling;
        long long  temp =0;
        if(root->left){
            temp+= root->left->val;
        }
        if(root->right){
            temp+= root->right->val;
        }
       if(root->left){
        solve(root->left,temp,lev+1);
       }
       if(root->right){
        solve(root->right,temp,lev+1);
       }
       return root;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        level.resize(100001);
        LevelSum(root,0);
        return solve(root,root->val,0);
    }
};
