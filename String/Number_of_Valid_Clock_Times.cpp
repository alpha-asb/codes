class Solution {
public:
    int countTime(string time) {
    int res = 1;
    if(time[4] == '?'){
        res*=10;
    }
    if(time[3] == '?'){
        res*=6;
    }
    if(time[1] == '?' && time[0] == '?'){
          res*=24;
    }
    else if(time[1] == '?'){
        if(time[0] - '0' < 2){
            res*=10;
        }
        else{
            res*=4;
        }
    }
    else if(time[0] == '?'){
        if(time[1] - '0'>3){
            res*=2;
        }
        else{
            res*=3;
        }
    }
    return res;
    }
};
