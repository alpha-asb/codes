class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Approach 1 : with custom comparator 
        // declaing custom comparator class
        /*
        class comparator{
            public:
                   bool operator()(const pair<int,int>&p1,const pair<int,int>&p2){
                    return p1.first*p2.second >p1.second*p2.first;
                   }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>heap;

        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                heap.push({arr[j],arr[i]});
            }
        }
        while(k-1){
            heap.pop();
            k--;
        }
        return {heap.top().first,heap.top().second};
        */

        // Approach 2: heap<double, pair<int,int>>  a little bit optimized

        priority_queue<pair<double,pair<int,int>>>heap;
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                double frac = (double)arr[j]/(double)arr[i];
                if(heap.size()==k){
                    if(frac < heap.top().first){
                    heap.pop();
                    heap.push({frac,{arr[j],arr[i]}});
                    }
                }
                else{
                    heap.push({frac,{arr[j],arr[i]}});
                }
            }
        }
        return {heap.top().second.first,heap.top().second.second};
    }
};
