class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,[](Job a, Job b){
            return a.dead < b.dead;
        });
        priority_queue<int>pq;
        int time = 1;
        for(int i=0;i<n;i++){
            if(arr[i].dead >= time){
                pq.push(-arr[i].profit);
                time++;
            }
            else {
                if(pq.top() < arr[i].profit){
                pq.push(-arr[i].profit);
                pq.pop();
            }
            }
        }
        int jobs = pq.size();
        int profit = 0;
        while(!pq.empty()){
            profit += -pq.top();
            pq.pop();
        }
        return {jobs,profit};
    } 
};
