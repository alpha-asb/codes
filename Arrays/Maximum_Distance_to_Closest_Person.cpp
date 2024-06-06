class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
  // case 1: empty seats in middle
  // case 2: empty seats in sarting
  // case 3: empty seats in ending
// consider all three casees and return maximum of them
        int count =0;
        int maxlen = 0;
        int n = seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==0){count++;}
            else{
                maxlen = max(maxlen,count);
                count =0;
            }
        }
        maxlen = max(maxlen,count);
        int i =0,start;
        int j = n-1,end;
        while(seats[i]==0){
            i++;
        }
        start = i;
        while(seats[j]==0){
            j--;
        }
        end = n-j-1;
        int ans = (maxlen/2)+(maxlen%2);
        return max(max(ans,start),end);
    }
};
