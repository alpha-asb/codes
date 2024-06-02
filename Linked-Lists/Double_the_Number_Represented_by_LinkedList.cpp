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
    ListNode*reverse(ListNode* head){
        if(!head){return NULL;}
        ListNode*before =NULL;
        while(head){
            ListNode*temp = head->next;
            head->next = before;
            before = head;
            head =temp;
        }
        return before;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*newhead = reverse(head);
        ListNode*ptr = newhead;
        int carry =0;
        int curr_val = 0;
        while(newhead){
            curr_val = (2*newhead->val + carry);
            carry = curr_val/10;
            newhead->val = curr_val%10;
            if(newhead->next == NULL && carry>0){
                newhead->next = new ListNode(carry);
                break;  // important to add this break,otherwise it will overwrite the added node and give unexpected results
            }
            newhead = newhead->next;
        }
        return reverse(ptr);
    }
};
