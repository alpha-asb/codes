class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev = NULL;
        ListNode*nex = head->next;
        vector<int>temp;
        int cnt = 1;
        while(nex){
            if(prev!=NULL and nex!=NULL){
               if( prev->val < head->val && head->val > nex->val){
                temp.push_back(cnt);
               }
               else if(prev->val > head->val && head->val < nex->val){
                temp.push_back(cnt);
               }
            }
            prev = head;
            head = head->next;
            nex = head->next;
            cnt++;
        }
        cout<<temp.size();
        if(temp.size()<2){return {-1,-1};}
        int mini = INT_MAX;
        for(int i=0;i<temp.size()-1;i++){
            mini = min(mini,temp[i+1]-temp[i]);
        }
        return {mini , temp[temp.size()-1]-temp[0]};
    }
};
