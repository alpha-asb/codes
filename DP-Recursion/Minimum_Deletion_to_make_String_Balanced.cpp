class Solution {
public:
    int minimumDeletions(string s) {
      /* Approach : pre calculate the no of b before each index and 
      no of a after each index 
      take the minimum of sum of pre calculated array of no of a and b

      O(n) time and O(n) Space
      
       int n = s.size();
       vector<int>prefix_a(n,0); 
       vector<int>prefix_b(n,0); 
       int cnt_b =0,cnt_a=0;
       for(int i=0;i<n;i++){
          prefix_b[i] = cnt_b;
          if(s[i] == 'b')cnt_b++;
       }
       for(int i=n-1;i>=0;i--){
        prefix_a[i] = cnt_a;
        if(s[i] == 'a')cnt_a++;
       }
       int res = INT_MAX;
       for(int i=0;i<n;i++){
        res = min(res,prefix_a[i]+prefix_b[i]);
       }
       return res;
       */

       // O(n) Time and O(1) Space Approach
       // using two variables to track the total count of a and b

       int cnt_a = 0,cnt_b = 0,n = s.size();

       for(int i=0;i<n;i++){
         if(s[i] == 'a')cnt_a++;
       }
       int min_deletion = n;
       for(int i=0;i<n;i++){
         if(s[i] == 'a'){
            cnt_a--;
         }
         min_deletion = min(min_deletion,cnt_a + cnt_b);
         if(s[i] == 'b'){
            cnt_b++;
         }
       }
    return min_deletion;
    }
};
