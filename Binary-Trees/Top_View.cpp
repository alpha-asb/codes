class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        int idx = 0;
        mp[idx] = root->data;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node*temp = q.front().first;
                int curr_idx = q.front().second;
                q.pop();
                if(mp.find(curr_idx) == mp.end()){
                    mp[curr_idx] = temp->data;
                }
                if(temp->left){
                    q.push({temp->left,curr_idx-1});
                }
                if(temp->right){
                    q.push({temp->right,curr_idx+1});
                }
            }
        }
        vector<int>res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }

};
