class Solution {
  public:
    int min_val = 0,max_val = 0;
    void dfs(Node*root,int val){
        if(!root){return;}
        min_val = min(min_val,val);
        max_val = max(max_val,val);
        dfs(root->left,val-1);
        dfs(root->right,val+1);
    }
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        if(!root)return 0;
        dfs(root,0);
        return 1+abs(min_val) + max_val ;
    }
};
