class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        if(!root)return root;
        
        Node*left = RemoveHalfNodes(root->left);
        Node*right = RemoveHalfNodes(root->right);
        
        if(!left && right || left && !right){
            return left?left:right;
        }
        else{
            root->left = left;
            root->right = right;
        }
        return root;
    }
};
