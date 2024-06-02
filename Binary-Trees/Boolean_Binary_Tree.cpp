class Solution {
public:
    bool dfs(TreeNode*root){
        if(!root->right && !root->left){
            return root->val == 1;
        } 
        bool left = false;
        bool right = false;
        if(root->left){
            left = dfs(root->left);
        }
        if(root->right){
            right = dfs(root->right);
        }
        if(root->val == 2){
            return left || right;
        }
        else{
            return left && right;
        }
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
