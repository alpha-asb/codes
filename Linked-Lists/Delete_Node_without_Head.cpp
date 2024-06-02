/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*temp = node;
        ListNode*remove = NULL;
        while(temp->next){
            temp->val = temp->next->val;
            remove = temp;
            temp = temp->next;
        }

        if(remove){
            remove->next = NULL;
        }
    }
};
