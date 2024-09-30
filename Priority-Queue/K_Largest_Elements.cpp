class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>, std::greater<int>>pq;
	    for(int i=0;i<k;i++){
	        pq.push(arr[i]);
	    }
        for(int i=k;i<n;i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
	    vector<int>res;
	    while(!pq.empty()){
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(res.begin(),res.end());
        return res;
	}
};
