class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        int i=0,j=0,count=0;
        unordered_set<char>check;
        for(int i=0;i<n;i++){
            check.insert(s[i]);
        }
        for(char ch : check){
            int l_idx=-1,r_idx=-1;
            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    if(l_idx==-1){
                        l_idx=i;
                    }
                    r_idx=i;
                }
            }
            unordered_set<char>st;
            for(int i=l_idx+1;i<=r_idx-1;i++){
                st.insert(s[i]);
            }
            count+=st.size();
        }
        return count;
    }
};