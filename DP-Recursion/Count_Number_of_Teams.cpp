class Solution {
public:
    int numTeams(vector<int>& rating) {
        /*
        Brutt Force Approach: O(n^3)

        int n = rating.size();
        int teams = 0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(rating[i] > rating[j] && rating[j] > rating[k])teams++;
                    else if(rating[i] < rating[j] && rating[j] < rating[k])teams++;
                }
            }
        }
        return teams;
        */
        // Dynamic Programming Approach: consider each soldier as middle soldier and 
        // get the number of smaller rating soldier in left size and larger rating 
        // soldier in right side
        // add the possibilities to the result

        int n = rating.size();
        int res = 0;
        for(int mid = 1;mid < n-1;mid++){
            int leftSmaller = 0;
            int rightLarger = 0;

            for(int left = 0;left<mid;left++){
                if(rating[left]<rating[mid])leftSmaller++;
            }
            for(int right = mid+1;right<n;right++){
                if(rating[mid]<rating[right])rightLarger++;
            }
            // this is for ascending team
            res += leftSmaller*rightLarger;
            
            // for descending team
            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - 1 - mid - rightLarger;
            res += leftLarger*rightSmaller;
        }
        return res;
    }
};
