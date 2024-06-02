class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int>res(deck.size(),0);
        queue<int>q;
        for(int i;i<deck.size();i++){
            q.push(i);
        }
        int i=0;
        //simulation
        while(!q.empty()){
           int idx = q.front();
           q.pop();
           res[idx]=deck[i];
           if(!q.empty()){
            q.push(q.front());
            q.pop();
           }
           i++;
        }
        return res;
    }
};
