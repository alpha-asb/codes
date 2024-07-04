class Solution {
  public:
    unordered_map<string,int>mp;
    vector<Node*>res;
    vector<Node*> printAllDups(Node* root) {
        dfs(root);
        return res;
    }
    string dfs(Node* root){
        if(!root){return "#";}
        
        string curr = to_string(root->data) + " ";
        curr += dfs(root->left);
        curr += dfs(root->right);
        
        if(mp.find(curr)!=mp.end() && mp[curr]==1){
            res.push_back(root);
        }
        mp[curr]++;
        return curr;
    }
};
