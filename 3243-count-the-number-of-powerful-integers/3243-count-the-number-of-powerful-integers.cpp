class Solution {
public:
    long long solve(string &str,string & suff,int limit){
        if(str.length()<suff.length()){
            return 0;
        }
        long long count=0;
        string remaining=str.substr(str.length()-suff.length());
        int len=str.length()-suff.length();
        //cout<<len<<" "<<remaining.length()<<endl;
        for(int i=0;i<len;i++){
            int digit = str[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1,len-i-1);
            }else{
                count +=pow(limit+1,len-i);
                return count;
            }
        }
        if(remaining>=suff){
            count++;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startstr = to_string(start-1);
        string endstr = to_string(finish);
        return solve(endstr,s,limit)-solve(startstr,s,limit);
    }
};