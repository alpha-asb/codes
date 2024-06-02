class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>ratios;
        int n = quality.size();

// create a pair stores ratio of wage[i]/quality[i] ,later will sort them according to ratios
        for(int i=0;i<n;i++){
           ratios.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(ratios.begin(),ratios.end());
        priority_queue<int>maxHeap;
        int total_quality = 0;
        double maxRate = 0.0;
        for(int i=0;i<k;i++){
            total_quality += ratios[i].second;
            maxRate = max(maxRate,ratios[i].first);
            maxHeap.push(ratios[i].second);
        }
        double ans = maxRate*total_quality;
        for(int i=k;i<n;i++){
            total_quality -= maxHeap.top();
            maxHeap.pop();
            maxRate = max(maxRate,ratios[i].first);
            total_quality += ratios[i].second;
            maxHeap.push(ratios[i].second);
            ans = min(ans,maxRate*total_quality);
        }
        return ans;
    }
};
