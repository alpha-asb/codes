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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        while(head){
                while(!st.empty() && st.top()<head->val){
                    st.pop();
                }
                st.push(head->val);

            head=head->next;
        }
        ListNode*newhead = new ListNode();
        ListNode*ptr = newhead;
        while(!st.empty()){
            newhead->next = new ListNode(st.top());
            st.pop();
            newhead = newhead->next;
        }
        return reverse(ptr->next);
    }

    ListNode*reverse(ListNode*head){
        if(!head){return NULL;}
        ListNode*before = NULL;
        while(head){
            ListNode*temp = head->next;
            head->next = before;
            before  = head;
            head = temp;
        }
        return before;
    }
};
