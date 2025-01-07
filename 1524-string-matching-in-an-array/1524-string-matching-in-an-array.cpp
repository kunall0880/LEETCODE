class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st;
        vector<string>ans;
        for(int i=0;i<n;i++){
            string str=words[i];
            for(int j=0;j<n;j++){
                if(words[j].find(str)!=string::npos&&i!=j){
                    st.insert(str);
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};