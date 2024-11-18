class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>res;
        int n=str.size();
        for(int i=0;i<n;i++){
            string a=str[i];
            sort(a.begin(),a.end());
            res[a].push_back(str[i]);
        }
        for(auto it: res){
            ans.push_back(it.second);
        }
        return ans;
    }
};