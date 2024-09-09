class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l=0,m=0,h = arr.size()-1;
        while(m <= h){
            if(arr[m] == 0){
                swap(arr[m],arr[l]);
                m++;
                l++;
            }
            else if(arr[m] == 1){
                m++;
            }
            else if(arr[m] == 2){
                swap(arr[m],arr[h]);
                h--;
            }
        }
    }
};
