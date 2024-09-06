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
    ListNode*Delete(ListNode*head,unordered_set<int>s){
        if(!head)return NULL;
        // case when head needs to be deleted
        while(head && s.find(head->val) != s.end() ){
            ListNode*temp = head;
            head = head->next;
            delete temp;
        }
        ListNode*prev = NULL;
        ListNode*ptr = head;
        while(ptr){
            if(s.find(ptr->val) != s.end()){
                prev->next = ptr->next;
                delete ptr;
                ptr = prev->next;
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        head = Delete(head,s);
        return head;
    }
};


/*
Simplified version

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head)return NULL;
        unordered_set<int>s(nums.begin(),nums.end());
        // handling the case when head need to be deleted
        while(head && s.find(head->val)!=s.end()){
            ListNode*temp = head;
            head = head->next;
            delete temp;
        }
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr->next){
            if(s.find(curr->next->val)!= s.end()){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
*/
