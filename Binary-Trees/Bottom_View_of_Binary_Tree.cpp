class Solution {
  public:
    map<int,pair<int,int>>mp;
    void dfs(Node*root,int pos,int level){
        /*
        Approach 1: O(NlogN) Time and O(N) space
        if(!root)return;
        
        if(mp.find(pos)== mp.end() || mp[pos].first <= level){
          mp[pos] = {level,root->data};  
        }
        
        dfs(root->left,pos-1,level+1);
        dfs(root->right,pos+1,level+1);
    }
    vector <int> bottomView(Node *root) {
        int level = 0;
        dfs(root,0,level);
        vector<int>res;
        for(auto it:mp){
            res.push_back(it.second.second);
        }
        return res;
        */
        
        // Approach 2: O(N) Time and O(N) Space
        /*
        using BFS we can avoid nlogn time of map serch 
        use map to store the horizontal distance and node val
        update the mp[hd] = node->data after every pop from front of queue
        if left child push in queue {root-left,hd-1}
        if right child push in queue {root-right,hd+1}
        
        iterate over the mp and pushback in res vector
        */
        
    }
};
