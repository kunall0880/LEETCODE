class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int mp[51]={0};
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int count=0;
            for(auto it : mp){
                if(it==2){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};