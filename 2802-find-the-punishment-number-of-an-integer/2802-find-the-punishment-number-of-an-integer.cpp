class Solution {
public:
    bool solve(int idx,string s,int sum,int num){
        if(idx==s.length()){
            return sum==num;
        }
        if(sum>num){
            return false;
        }
        bool ans=false;
        for(int j=idx;j<s.length();j++){
            string str=s.substr(idx,j-idx+1);
            int val=stoi(str);
            ans=ans||solve(j+1,s,sum+val,num);
            if(ans){
                return ans;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            string str=to_string(num);
            if(solve(0,str,0,i)){
                sum=sum+num;
            }
        }
        return sum;
    }
};