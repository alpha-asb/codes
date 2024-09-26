class Solution {
  public:
  bool loop = false;
  Node*prev = NULL;
    Node* findloop(Node*head){
        Node*slow = head;
        Node*fast = head;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                loop = true;
                return slow;
            }
        }
        return nullptr;
    }    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        Node*imposter = findloop(head);
        if(loop){
            // if loop start at head
            Node*start = head;
            if(start == imposter){
                while(imposter->next != start){
                    imposter = imposter->next;
                }
                imposter->next = NULL;
                return ;
            }
            // find the loopstart
            while(start-> next != imposter->next){
                start = start->next;
                imposter = imposter->next;
            }
            imposter->next = NULL;
        }
    }
};
