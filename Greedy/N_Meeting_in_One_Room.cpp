class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
       vector<pair<int,int>>meet;
       for(int i=0;i<n;i++){
           meet.push_back({end[i],start[i]});
       }
       sort(meet.begin(),meet.end());
       int cnt = 1;
       int last = meet[0].first;
       for(int i=1;i<n;i++){
           if(meet[i].second > last){
               cnt++;
               last = meet[i].first;
           }
       }
       return cnt;
    }
};
