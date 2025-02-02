class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int,int>mp;
        for(char & ch : s){
            mp[ch]++;
        }
        int oc=0,ec=1e9;
        for(auto it : mp){
            if(it.second%2==0){
                ec=min(ec,it.second);
            }else{
                oc=max(oc,it.second);
            }
        }
        return oc-ec;
    }
};