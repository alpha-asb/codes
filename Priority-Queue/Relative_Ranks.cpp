class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>heap;
        vector<string>res(score.size());
        for(int i=0;i<score.size();i++){
            heap.push({score[i],i});
        }
        int place = 1;
        while(!heap.empty()){
            int index = heap.top().second;
            heap.pop();
            if(place == 1){res[index]="Gold Medal";}
            else if(place == 2){res[index]="Silver Medal";}
            else if(place == 3){res[index]="Bronze Medal";}
            else{
                res[index] = to_string(place);
            }
            place++;
        }
        return res;
    }
};
