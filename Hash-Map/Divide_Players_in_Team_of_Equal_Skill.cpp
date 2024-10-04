/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = 0;
        for(int num:skill){
            sum += num;
        }
        if(sum%(n/2) != 0){
            return -1;
        }
        long long teamSum = sum/(n/2); // n/2 teams , so each team  with 
                                       //sum/teams skill
        unordered_map<int,vector<int>>mp;
        vector<pair<int,int>>v;
        for(int i =0;i<n;i++){
            int need = teamSum - skill[i];
            if(mp.find(need) != mp.end()){
                v.push_back({i,mp[need][mp[need].size()-1]});
                mp[need].pop_back();

                if(mp[need].size() == 0){
                    mp.erase(need);
                }
            }
            else{
                mp[skill[i]].push_back(i);
            }
        }
        if(mp.size() != 0){
            return -1;
        }
        long long ans =0;
        for(auto it:v){
            ans = ans + (skill[it.first]*skill[it.second]);
        }
        return ans;
    }
};
*/

// O(n) Time and O(1) Space
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int>skillfreq(1001,0);
        long long sum =0;
        for(int num:skill){
           sum+=num;
           skillfreq[num]++;
        }
        if(sum%(n/2) != 0){return -1;}
        long long target = sum/(n/2);
        long long ans =0;
        for(int i=0;i<n;i++){
          int partnerskill = target - skill[i];

          if(skillfreq[partnerskill] == 0){
            return -1;                     // pairs not possible
          }
          ans +=  (long long)skill[i]* (long long)partnerskill;

          skillfreq[partnerskill]--;
        }
      return ans/2 ;  // each pair is counted twice
    }
};
