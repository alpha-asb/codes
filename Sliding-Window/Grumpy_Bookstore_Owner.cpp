class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                total+=customers[i];
            }
        }
        int window =0;
        int i =0;
        int j=0;
        while(i<minutes){
            if(grumpy[i]==1){
               window+=customers[i];
            }
            i++;
        }
        int max_total = max(total,total + window);
        while(i<n){
            
            if(grumpy[j]==1){
                window-=customers[j];
            }
            if(grumpy[i]==1){
                window+=customers[i];
            }
            max_total = max(max_total,total + window);
            i++;
            j++;
        }
        return max_total;
    }
};
