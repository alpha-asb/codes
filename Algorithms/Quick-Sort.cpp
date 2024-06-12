#include <iostream>
#include <vector>
using namespace std;

int Pivot(int lo,int hi,int arr[]){
    int pi_element = arr[hi];
    int i=lo; int j = hi;
    while(i<j){
        while(arr[i]<pi_element){
            i++;
        }
        while(arr[j]>=pi_element){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    } 
    swap(arr[i],arr[hi]);
    return j;
}
void QuickSort(int lo,int hi,int arr[]){
    if(lo<hi){
    int pivot = Pivot(lo,hi,arr);
    QuickSort(lo,pivot-1,arr);
    QuickSort(pivot+1,hi,arr);
    return;
    }
}
int main(){
    int n =5;
    int arr[5] = {15,4,71,1,2};
    cout<<"Array Before Sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(0,n-1,arr);
    cout<<"Array After Sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}