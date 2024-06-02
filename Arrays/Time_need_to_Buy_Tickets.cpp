class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // O(n^2) --> worst case
        
        // int time = 0;
        // while(true){
        //   for(int i=0;i<tickets.size();i++){
        //     if(tickets[i]>0){
        //         time++;
        //         tickets[i]--;
        //     }
        //     if(tickets[k]==0){
        //     return time;
        //   }
        //   }
          
        // }
        // return 0;

        // O(n)
        int time =0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                time += min(tickets[i],tickets[k]);
            }
            else{
                time += min(tickets[i],tickets[k]-1);
            }
        }
        return time;
    }
};
