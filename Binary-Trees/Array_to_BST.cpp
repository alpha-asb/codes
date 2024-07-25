class Solution {
  public:
    Node* makeBST(vector<int>& nums,int l,int r){
        if(l>r)return NULL;
        int mid = l + (r-l)/2;
        Node*root = new Node(nums[mid]);
        root->left = makeBST(nums,l,mid-1);
        root->right = makeBST(nums,mid+1,r);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
    }
};
