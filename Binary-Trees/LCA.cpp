class Solution
{
    public:
    bool findnode(Node*root,int n,vector<Node*>&v){
        if(!root)return false;
        if(root->data == n){
            v.push_back(root);
            return true;
        }
        v.push_back(root);
        if(findnode(root->left,n,v) || findnode(root->right,n,v)){
            v.push_back(root);
            return true;
        }
        v.pop_back();
        return false;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
      if(root->data == n1 || root->data == n2){
          return root;
        }
      vector<Node*>v1,v2;
      bool f1 = findnode(root,n1,v1);
      bool f2 = findnode(root,n2,v2);
      
      if(!f1 || !f2){
          return NULL;
      }
      int i =0;
      while(i < v1.size() && i < v2.size() && v1[i]->data == v2[i]->data){
              i++;
        }
        return v1[i-1];
    }
};
