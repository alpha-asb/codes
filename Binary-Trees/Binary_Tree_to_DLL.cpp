class Solution {
  public:
    Node*head = NULL;
    Node*prev = NULL;
    void solve(Node*root){
        if(!root)return;
        solve(root->left);
        if(prev){
            prev->right = root;
            root->left = prev;
        }
        if(!head){
            head = root;
        }
        prev = root;
        solve(root->right);
    }
    Node* bToDLL(Node* root) {
        solve(root);
        return head;
    }
};
