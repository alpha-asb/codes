#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>&arr,int l,int mid,int r){
    // two parts of array
    int n1 = mid-l+1;
    int n2 = r - mid;
    // temp arrays
    int a[n1];
    int b[n2]; 
    // copy int temp arrays
    for(int i=0;i<n1;i++){
        a[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[i+mid+1];
    }
    // putting sorted values in arr

    int i=0,j=0;
    int k = l;
    while (i<n1 && j<n2)
    {
        if(a[i]<b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] = b[j];
            j++;
            k++;
    }
 return;
}
void MergeSort(vector<int>&arr,int l,int r){
     if(l<r){
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
     }
}
int main(){
    vector<int>arr = {5,4,12,14,3,2,11,1,15};
    MergeSort(arr,0,arr.size()-1);

    cout<<"Sorted Array:";
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}