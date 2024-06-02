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
    TreeNode* solve(TreeNode*root,int val,int depth,int curr){
        if(!root){return nullptr;}
        if(curr == depth -1){
            TreeNode*l = root->left;
            TreeNode*r = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = l;
            root->right->right = r;
        }
        solve(root->left,val,depth,curr+1);
        solve(root->right,val,depth,curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
            TreeNode*newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return solve(root,val,depth,1);
    }
};
