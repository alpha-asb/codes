class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one =0,zero=0;
        for(int x:students){
            if(x==1){one++;}
            else{zero++;}
        }
        int remaining = sandwiches.size();
        for(int x:sandwiches){
            // if studdent want 1/0 sanwich and no more 1/0 sanwich remaining
          if( x==1 && one == 0 || x==0 && zero ==0 || remaining ==0){
            break;
          }
          if(x==1){one--;}
          else{zero--;}
          remaining--;
        }
    
        return remaining;
    }
};
