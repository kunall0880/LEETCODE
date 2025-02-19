class Solution {
public:
    void solve(vector<string>&nums,int n,string & str){
        if(str.length()==n){
            nums.push_back(str);
            return;
        }
        for(char ch ='a';ch<='c';ch++){
            if(!str.empty()&&str.back()==ch){
                continue;
            }
            str.push_back(ch);
            solve(nums,n,str);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr="";
        vector<string>res;
        solve(res,n,curr);
        if(res.size()<k){
            return "";
        }
        return res[k-1];
    }
};