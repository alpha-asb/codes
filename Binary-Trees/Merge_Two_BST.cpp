class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node*root,vector<int>&arr){
        if(!root)return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>bst1;
        vector<int>bst2;
        inorder(root1,bst1);
        inorder(root2,bst2);
        vector<int>arr;
        int i = 0,j=0;
        int n = bst1.size(),m = bst2.size();
        while(i<n || j<m){
            if(i<n && j<m){
                if(bst1[i]<bst2[j]){
                    arr.push_back(bst1[i]);
                    i++;
                }
                else{
                    arr.push_back(bst2[j]);
                    j++;
                }
            }
            else if(i<n){
                arr.push_back(bst1[i]);
                i++;
            }
            else{
                arr.push_back(bst2[j]);
                j++;
            }
        }
        return arr;
    }
};
