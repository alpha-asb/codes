class Solution {
  public:
    bool find = false;
    void dfs(Node*root,int target,vector<int>&res){
        if(!root || find)return;
        if(root->data == target){
            find = true;
            return;
        }
        
        res.push_back(root->data);
        
        dfs(root->left,target,res);
        dfs(root->right,target,res);
        if(!find){res.pop_back();}
        
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int>res;
        dfs(root,target,res);
        reverse(res.begin(),res.end());
        return res;
    }
};
