class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        bool flag = false ;
        for(int i=0;i<n;i++){
            flag = false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    flag = true;
                }
            }
            if(!flag){
                break;
            }
        }
    }
};
