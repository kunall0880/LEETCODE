class Solution {
public:
    int countv(string s){
        int count=0,n=s.length()-1;
        if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'){
                count++;
            }
        if(s[n]=='a'||s[n]=='e'||s[n]=='i'||s[n]=='o'||s[n]=='u'){
                count++;
            }
        if(count<2){
            return 0;
        }
        return 1;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>check(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(countv(words[i])){
                check[i]=1;
            }
        }
        for(int i=1;i<words.size();i++){
            check[i]=check[i]+check[i-1];
        }
        int n=queries.size();
        for(int i=0;i<n;i++){
            int s=queries[i][0],e=queries[i][1],count=0;
            if(s==0){
                count=check[e];
            }else{
                count=check[e]-check[s-1];
            }   
            ans.push_back(count);
        }
        return ans;
    }
};