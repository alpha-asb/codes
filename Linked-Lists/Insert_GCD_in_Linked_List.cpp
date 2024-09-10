// one pass
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)return head;
        ListNode*ptr1 = head;
        ListNode*ptr2 = head->next;

        while(ptr2){
          // gcd calculation
          int GCD = gcd(ptr1->val,ptr2->val);
          ListNode*newnode = new ListNode(GCD);

          ptr1->next = newnode;
          newnode->next = ptr2;
          ptr1 = ptr2;
          ptr2 = ptr2->next;

        }
        return head;
    }
};

// two pass
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)return head;
        ListNode*ptr1 = head;
        ListNode*ptr2 = head->next;
        vector<int>v;
        while(ptr2){
            v.push_back(gcd(ptr1->val,ptr2->val));
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode*ptr = head;
        int i=0;
        while(ptr->next){
          ListNode*temp = ptr->next;
          ptr->next = new ListNode(v[i]);
          i++;
          ptr->next->next = temp;
          ptr = temp;
        }
        return head;
    }
};
