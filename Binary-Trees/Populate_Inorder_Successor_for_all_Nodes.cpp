class Solution {
  public:
    Node*nxt = NULL;
    void postorder(Node *root){
        if(!root)return;
        postorder(root->right);
        root->next = nxt;
        nxt = root;
        postorder(root->left);
    }
    void populateNext(Node *root) {
        // code here
        postorder(root);
    }
};
