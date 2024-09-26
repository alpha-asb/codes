class Solution{
public:	
    bool allsame(vector<int>mp){
        int val = -1;
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
              val = mp[i];
              break;
            }
        }
        for(int i=0;i<26;i++){
            if(mp[i] != 0 and mp[i] != val){
                return false;
            }
        }
        return true;
    }
	bool sameFreq(string s)
	{
	    vector<int>mp(26,0);
	    for(char c:s){
	        mp[c-'a']++;
	    }
	    if(allsame(mp)){
	        return true;
	    }
	    for(int i=0;i<26;i++){
	        if(mp[i] != 0){
	            mp[i] -= 1;
	            if(allsame(mp)){
	                return true;
	            }
	            mp[i] += 1;
	        }
	    }
        return false;
	} 
};
