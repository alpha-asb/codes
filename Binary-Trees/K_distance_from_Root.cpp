
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    vector<int>res;
    void solve(Node*root,int k,int level){
        if(!root || level>k){return;}
        if(level == k){
            res.push_back(root->data);
        }
        solve(root->left,k,level+1);
        solve(root->right,k,level+1);
    }
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      solve(root,k,0);
      return res;
    }
};


