class Solution {
  public:
    int isValid(string str) {
        int cnt = 0;
        int dots = 0;
        string temp = "";
        for(char c:str){
            
            // leading zero condition
           if(temp.size()>1 && temp[0] == '0'){
               return false;
           }
           // range validation condition
           if(c == '.' && !temp.empty()){
               int num = stoi(temp);
               //cout<<num<<endl;
               if(num < 0 || num >255){
                   return false;
               }
               dots++;
               cnt++;
               temp = "";
           }
           // adjusent dots condition
           else if(c == '.' && temp.empty()){
               return false;
           }
           else{
               temp+=c;
           }
        }
        // last num 
        if(!temp.empty()){
            int num = stoi(temp);
            if(num < 0 || num >255){
                   return false;
               }
            cnt++;
               
        }
        return cnt == 4 && dots == 3;
    }
};
