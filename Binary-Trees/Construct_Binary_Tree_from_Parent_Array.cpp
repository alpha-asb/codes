class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        vector<Node*>v;
        for(int i=0;i<parent.size();i++){
            v.push_back(new Node(i));
        }
        Node*root = NULL;
        
        for(int i=0;i<parent.size();i++){
            if(parent[i] == -1){
                root = v[i];
            }
            else{
                if(v[parent[i]]->left == NULL){
                    v[parent[i]]->left = v[i];
                }
                else{
                    v[parent[i]]->right = v[i];
                }
            }
        }
        return root;
    }
};
