class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int half_len = (len%2 == 0)?len/2:len/2 +1;
        long first_half = stol(n.substr(0,half_len));

        vector<long>Ways;
        // mirror of half
        Ways.push_back(makePalindrome(first_half,len%2==0));
        // increment by 1 on mirror
        Ways.push_back(makePalindrome(first_half+1,len%2==0));
        //decrement by 1 on mirror
        Ways.push_back(makePalindrome(first_half-1,len%2==0));
        // Edge case like 99 , 1000
        Ways.push_back((long)pow(10,len)+1);  // 10001 like
        Ways.push_back((long)pow(10,len-1)-1);  // 99

        long diff = LONG_MAX,res = 0,given = stol(n);
        for(auto way:Ways){
            if(way == given)continue;
            if(abs(way - given)<diff){
                res = way;
                diff = abs(way - given);
            }
            else if(abs(way - given) == diff){
                res = min(res,way);
            }
        }
        return to_string(res);
    }
    long makePalindrome(long left,bool even){
        long res = left;
        if(!even){left/=10;}
        while(left){
            res = res*10 + left%10;
            left /= 10;
        }
        return res;
    }
};
