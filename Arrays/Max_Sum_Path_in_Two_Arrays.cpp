class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int total_sum =0,sum1=0,sum2=0;
        int i=0,j=0;
        while(i<arr1.size() and j<arr2.size()){
            if(arr1[i] < arr2[j]){
                sum1 += arr1[i++];
            }
            else if(arr1[i] > arr2[j]){
                sum2 += arr2[j++];
            }
            else{
                // include common element
                sum1 += arr1[i++];
                sum2 += arr2[j++];
                total_sum += max(sum1,sum2);
                // get sum of next chunks
                sum1 = 0 ; sum2 =0;
            }
        }
        while(i < arr1.size()){
            sum1 += arr1[i++];
        }
        while(j < arr2.size()){
            sum2 += arr2[j++];
        }
        total_sum += max(sum1,sum2);
        return total_sum;
    }
};
