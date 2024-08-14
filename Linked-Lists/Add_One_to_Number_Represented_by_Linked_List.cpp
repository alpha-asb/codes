class Solution {
  private:
  Node*reverse(Node*head){
      Node*prev = NULL;
      while(head){
          Node*temp = head->next;
          head->next = prev;
          prev = head;
          head = temp;
      }
      return prev;
  }
  public:
    Node* addOne(Node* head) {
        Node*rev = reverse(head);
        Node*ptr = rev;
        int carry = 1;
        Node*prev = NULL;
        while(rev && carry){
            int digit = rev->data+carry;
            rev->data = digit%10;
            carry = digit/10;
            prev = rev;
            rev = rev->next;
        }
        if(carry){
            prev->next = new Node(carry);
        }
        return reverse(ptr);
    }
};
