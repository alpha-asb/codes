class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        string n1 ="",n2="";
        for(int i=0;i<arr.size();i++){
            if(i%2){
                n1 += to_string(arr[i]);
            }
            else{
                n2 += to_string(arr[i]);
            }
        }
        return addstring(n1,n2);
    }
    string addstring(string n1,string n2){
        int i = n1.size()-1,j = n2.size()-1;
        int carry = 0;
        string res ="";
        while(i>=0 || j>=0 || carry>0){
            int sum = 0;
            if(i>=0){sum += n1[i]-'0';i--;}
            if(j>=0){sum += n2[j]-'0';j--;}
            sum += carry;
            res += to_string(sum%10);
            carry = sum/10;
        }
        reverse(res.begin(),res.end());
        int idx = 0;
        while(res[idx] == '0'){
            idx++;
        }
        return res.substr(idx);
    }
};
