class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // Initialize pointers
        Node* curr = head->next, *prev = head, *nxt = NULL;
        
        // Loop to reverse the list until we return to the head
        while (curr != head) {
            nxt = curr->next;     // Store the next node
            curr->next = prev;    // Reverse the current node's next pointer
            prev = curr;          // Move 'prev' forward
            curr = nxt;           // Move 'curr' forward
        }
        
        head->next = prev;        // Reconnect the head to make the list circular again
        return prev;              // Return the new head (previously the tail)
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* temp = head->next, *prev = head;
        
        // Case 1: If the node to be deleted is the head
        if (head->data == key) {
            // Traverse to find the last node before head
            while (temp != head) {
                prev = temp;
                temp = temp->next;
            }
        }
        else {
            // Case 2: Traverse to find the node with the key
            while (temp != head && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }
        }

        // If the node to delete is found (either the head or another node)
        if (head->data == key || temp != head) {
            prev->next = temp->next;  // Bypass the node to be deleted
        }

        // If the head was deleted, return the new head, otherwise return the original head
        return (head->data == key) ? prev->next : head;
    }
};
