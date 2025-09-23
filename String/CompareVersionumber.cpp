class Solution {
public:
    int solve(string version1, string version2,int n,int m){
        int i = 0,j=0;
        int num1 = 0,num2 =0;
        while(i<n or j<m){
            if(version1[i] == '.'){
                i++;
            }
            if(version2[j] == '.'){
                j++;
            }
            if(num1 > num2){
                return 1;
            }
            else if(num1 < num2){
                return -1;
            }
            num1 = 0;
            num2 = 0;
            
            while(version1[i] != '.' and i<n){
                num1 = num1*10 + (version1[i] - '0');
                i++;
            }
            while(version2[j] != '.' and j<m){
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }
        }
        if(num1 > num2){
                    return 1;
                }
                else if(num1 < num2){
                    return -1;
                }

        return 0;
    }
    int compareVersion(string version1, string version2) {
        int n = size(version1);
        int m = size(version2);
        return  solve(version1,version2,n,m);
    }
};
