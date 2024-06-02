

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
void DFS(Node* node,vector<int>&res){
    if(!node){return;}
    if(node->right && !node->left){
        res.push_back(node->right->data);
    }
    else if(!node->right && node->left){
        res.push_back(node->left->data);
    }
    DFS(node->left,res);
    DFS(node->right,res);
}
vector<int> noSibling(Node* node)
{
    // code here
    vector<int>res;
    DFS(node,res);
    sort(res.begin(),res.end());
    return (res.size()==0)?vector<int>{-1}:res;
}
