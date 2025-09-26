class Solution {
  public:
    void reverseDQ(deque<int>& dq, int start, int end){
        while(start < end){
            swap(dq[start],dq[end]);
            start++;
            end--;
        }
    }
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n = dq.size();
        if(n == 0)return;
        k = k%n;
        if(k == 0)return;
        /*
        int temp;
        if(type == 1){
            while(k){
                temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
                k--;
            }
        }
        else{
            while(k){
                temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                k--;
            }
        }
        return;
        */
        
        // Reversal Approach
        if(type == 1){
            reverseDQ(dq,0,n-1);
            reverseDQ(dq,0,k-1);
            reverseDQ(dq,k,n-1);
        }
        else{
            reverseDQ(dq,0,k-1);
            reverseDQ(dq,k,n-1);
            reverseDQ(dq,0,n-1);
        }
        
    }
};
