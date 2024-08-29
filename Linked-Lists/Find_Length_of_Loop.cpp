class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {

        Node*slowptr = head;
        Node*fastptr = head;
        bool loop = false;
        while(fastptr != NULL && fastptr->next != NULL){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr){
                loop = true;
                break;
            }
        }
        int cnt =0;
        if(loop){
            slowptr = slowptr->next;
            cnt++;
            while(slowptr != fastptr){
                slowptr = slowptr->next;
                cnt++;
            }
        }
        return cnt;
    }
};
