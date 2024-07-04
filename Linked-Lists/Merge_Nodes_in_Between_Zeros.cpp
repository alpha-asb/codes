/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        /* this approach uses space

        ListNode*newhead = new ListNode(0);
        ListNode*ptr = newhead;
        int sum =0;
        head = head->next;
        while(head){
           if(head->val == 0){
            newhead->next = new ListNode(sum);
            newhead = newhead->next;
            sum=0;
           }
           else{
            sum+= head->val;
           }
           head = head->next;
        }
        return ptr->next;
        */
        
        // Approach 2: without using extraspace
       
        ListNode*modify = head->next;
        ListNode*getsum = modify;

        while(getsum){
            int sum = 0;
            while(getsum->val != 0){
                sum+= getsum->val;
                getsum = getsum->next;
            }
            modify->val = sum;
            getsum = getsum->next;
            modify->next = getsum;
            modify = modify->next;
        }
        return head->next;
    }
};
