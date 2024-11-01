
class Solution {
public:
    int level[100001];
    int height[100001];
    int levelmax[100001];
    int levelsecondmax[100001];
    int findheight(TreeNode* root,int lev){
        if(!root)return 0;
        level[root->val] = lev;
        height[root->val] = 1 + max(findheight(root->left,lev+1),findheight(root->right,lev+1));
        if(height[root->val] > levelmax[lev]){
            levelsecondmax[lev] =  levelmax[lev];
            levelmax[lev] = height[root->val];
        }
        else if(height[root->val] > levelsecondmax[lev]){
            levelsecondmax[lev] = height[root->val];
        }
        return height[root->val] ;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findheight(root,0);
        vector<int>res;
        for(int node:queries){
          int L = level[node];
          int H = (levelmax[L] == height[node])?levelsecondmax[L]:levelmax[L];
          int query_ans = L + H -1;
          res.push_back(query_ans);
        }
        return res;
    }
};
