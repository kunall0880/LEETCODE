class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int i=0,j=0,end=mp[s[0]];
        while(i<n){
            while(j<=end){
                end=max(end,mp[s[j]]);
                j++;
            }
            ans.push_back(j-i+1-1);
            i=j;
            end=max(end,mp[s[j]]);
            j++;
        }
        return ans;
    }
};