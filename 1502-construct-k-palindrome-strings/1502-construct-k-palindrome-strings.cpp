class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k==s.length()){
            return true;
        }
        if(k>s.length()){
            return false;
        }
        char arr[26];
        int oddcount=0;
        for(auto ch : s){
            int idx = ch-'a';
            arr[idx]++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]%2!=0){
                oddcount++;
            }
        }
        if(oddcount<=k){
            return true;
        }
        return false;
    }
};