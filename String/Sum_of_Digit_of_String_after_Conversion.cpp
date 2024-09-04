class Solution {
public:
    string transform(string n){
        int sum = 0;
        for(char c:n){
          sum += c-'0';    
        }
        return to_string(sum);
    }
    int getLucky(string s, int k) {
        int sum =0;
        string num ="";
        for(char c:s){
            int dig = c - 'a'+1;
            num += to_string(dig);
        }
        cout<<num<<endl;
        string res = num;
        while(k--){
            res =  transform(res);
        }
        return stoi(res);
    }
};
