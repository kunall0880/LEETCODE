class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k==s.length()){
            return true;
        }
        if(k>s.length()){
            return false;
        }
        unordered_map<char,int>mp;
        int oddcount=0;
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto it : mp){
            if(it.second%2!=0){
                oddcount++;
            }
            cout<<it.first<<" "<<it.second<<endl;
        }
        if(oddcount<=k){
            return true;
        }
        return false;
    }
};