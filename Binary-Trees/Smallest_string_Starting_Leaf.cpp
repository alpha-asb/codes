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

    void dfs(TreeNode*root,string &s,string &res){
       if(!root){return;}
// adding charecter from front because we want root to left string and we are traversing from root to leaf
       char temp = 'a'+root->val;
       s = temp + s;
       if(!root->left && !root->right){
         res = min(res,s);
       }
       dfs(root->left,s,res);
       dfs(root->right,s,res);
       s = s.substr(1,s.size()-1);
    }
    string smallestFromLeaf(TreeNode* root) {
       string s="";
       int treeSize = 8500;
       char character = 'z';
       std::string res(treeSize, character);
       dfs(root,s,res);
       return res;
    }
};
