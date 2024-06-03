class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll countStrings(int n) {
	    // code here
	    if(n==1){return 2;}
	    if(n==2){return 3;}
	    int a = 1;
	    int b = 1;
	    int ans = 3;
	    for(int i=3;i<=n;i++){
	        int c = (a+b)%mod;
	        a = b;
	        b = c;
	        ans = (ans + c)%mod;
	    }
	    return ans;
	}
};
