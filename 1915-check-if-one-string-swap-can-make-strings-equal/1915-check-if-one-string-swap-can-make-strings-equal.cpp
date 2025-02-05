class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int l2=s2.length(),count=0;
        vector<pair<int,char>>str1(2),str2(2);
        for(int i=0;i<l2;i++){
            if(s1[i]!=s2[i]){
                count++;
                    if(count==1){
                        str1[0]={i,s1[i]};
                        str2[0]={i,s2[i]};
                    }else if(count==2){
                        str1[1]={i,s1[i]};
                        str2[1]={i,s2[i]};
                }
            }          
        }
        if(str1[1].second==str2[0].second&&str1[0].second==str2[1].second&&count==2){
            return true;
        }
        return false;
    }
};