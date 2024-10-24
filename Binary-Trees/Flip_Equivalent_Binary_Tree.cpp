/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       return solve(root1,root2);
    }
    bool solve(TreeNode* root1, TreeNode* root2){
         if(!root1 && !root2)return true;
        if(!root1 || !root2)return false;
        if(root1->val != root2->val){
          return false;
        }
        return (solve(root1->left, root2->left) || solve(root1->left, root2->right)) &&
               (solve(root1->right, root2->right) || solve(root1->right, root2->left));
    }
};
