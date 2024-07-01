class Solution {
  public:
    TreeNode*makeTree(Node *&head, TreeNode *&root){
        if(!head)return NULL;
        int val = head->data;
        head = head->next;
        TreeNode*temp = new TreeNode(val);
        temp->left = makeTree(head,root);
        temp->right = makeTree(head,root);
        root = temp;
        return root;
    }
    void convert(Node *head, TreeNode *&root) {
        root = makeTree(head,root);
    }
};
