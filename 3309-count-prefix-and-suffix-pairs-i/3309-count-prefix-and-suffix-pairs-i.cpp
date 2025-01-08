class Solution {
public:
    bool isPrefixAndSuffix(string str1,string str2){
        int l1=str1.length(),l2=str2.length();
        if(l1>l2){
            return false;
        }
        for(int i=0;i<l1;i++){
            if(str2[i]!=str1[i]){
                return false;
            }
            if(str2[l2-1-i]!=str1[l1-1-i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0,n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};