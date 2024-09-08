
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode*ptr = head;
        while(ptr){
            len++;
            ptr = ptr->next;
        }
        vector<ListNode*>res(k,nullptr);
        int div = len/k;
        int rem = len%k;
        int i = 0;
        while((div || rem)  && head){
           res[i] = head;
           i++;
           ListNode*prev = NULL;
           if(div){
              int ahead = div;
              while(ahead--){
                prev = head;
                head = head->next;
              }
           }
           if(rem){
             prev = head;
             head = head->next;
             rem--;
           }
           prev->next = nullptr;
        }
        return res;
    }
};
