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
    int distributeCoins(TreeNode* root,TreeNode* parent= NULL) {
        int moves=0;
        rec(root, moves);
        return moves;
    }
    int rec(TreeNode* root, int &moves){
        if(root==NULL) return 0;
        int left = rec(root->left, moves);
        int right = rec(root->right, moves);
        moves += abs(left)+abs(right);
        return root->val+left+right-1;
    }
};
