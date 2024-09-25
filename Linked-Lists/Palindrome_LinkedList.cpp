class Solution {
  public:
    // Function to check whether the list is palindrome.
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
    bool isPalindrome(Node *head) {
        Node*slow = head;
        Node*fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node*secondhalf = reverse(slow);
        while(secondhalf){
            if(head->data != secondhalf->data){
                return false;
            }
            secondhalf = secondhalf->next;
            head = head->next;
        }
        return true;
    }
};
