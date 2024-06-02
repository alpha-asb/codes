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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
        // Approach 1: using O(n) space and O(n) Time complexity
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        int end = k-1;
        while(end < arr.size()){
           int curr_start = start;
           int curr_end = end;
           for(int i=0;i<k/2;i++){
            swap(arr[curr_start],arr[curr_end]);
            curr_start++;
            curr_end--;
           }
           start = start + k;
           end = end + k;
        }
        ListNode*newhead = new ListNode(0);
        ListNode*ptr = newhead;
        for(int i=0;i<arr.size();i++){
          newhead->next = new ListNode(arr[i]);
          newhead = newhead->next;
        }
        return ptr->next;
        */

        // Approach 2 : using stack O(k) space and O(n) Time : replacing values
        ListNode*fast = head;
        ListNode*slow = head;
        stack<int>st;
        while(fast){
            st.push(fast->val);
            if(st.size()==k){
                while(!st.empty()){
                slow->val = st.top();
                st.pop();
                slow = slow->next;
                }
            }
          fast = fast->next;
        }
        return head;
    }
};
