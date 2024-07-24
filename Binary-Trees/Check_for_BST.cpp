class Solution {
  public:
    bool solve(Node*root,int minVal,int maxVal){
        if(!root)return true;
        if(root->data <= minVal || root->data >= maxVal)return false;
        return solve(root->left,minVal,root->data) && solve(root->right,root->data,maxVal);
    }
    bool isBST(Node* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
