class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int i=0,start=0,end=mp[s[0]];
        while(i<n){
            end=max(end,mp[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start=end+1;
            }
            i++;
        }
        return ans;
    }
};