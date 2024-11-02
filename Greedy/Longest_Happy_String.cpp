class Solution {
public:
    string res = "";
    void solve(int a,int b,int c){
        if( c>0 && c>= b && b>= a && (res.size()<2 || !(res[res.size()-2]=='c' && res[res.size()-1]=='c'))){
            res += "c";
            longestDiverseString(a,b,c-1);
        }
        else if(b>0 && b>=a && b>=c && (res.size()<2 || !(res[res.size()-2]=='b' && res[res.size()-1]=='b'))){
            res += "b";
            longestDiverseString(a,b-1,c);
        }
        else if(a>0 && a>=b && a>=c && (res.size()<2 || !(res[res.size()-2]=='a' && res[res.size()-1]=='a'))){
            res += "a";
            longestDiverseString(a-1,b,c);
        }
        else if(c>0 && (res.size()<2 || !(res[res.size()-2]=='c' && res[res.size()-1]=='c'))){
            res += "c";
            longestDiverseString(a,b,c-1);
        }
        else if(b>0 && (res.size()<2 ||!(res[res.size()-2]=='b' && res[res.size()-1]=='b'))){
            res += "b";
            longestDiverseString(a,b-1,c);
        }
        else if(a>0 && (res.size()<2 || !(res[res.size()-2]=='a' && res[res.size()-1]=='a'))){
            res += "a";
            longestDiverseString(a-1,b,c);
        }
        return;
    }
    string longestDiverseString(int a, int b, int c) {
          solve(a,b,c);
          return res;
    }
};
