class Solution {
private:
    bool canMake(vector<pair<int,int>>& arr){
        sort(arr.begin(),arr.end());
        int count=0;
        int e=arr[0].first+1;
        for(auto it:arr){
            int start=it.first;
            int end= it.second;
            if(start >= e) count++;
            e=max(e,end);
        }
        return count >= 2;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> hori;
        vector<pair<int,int>> veri;
        for(auto it:rectangles){
            hori.push_back({it[0],it[2]});
            veri.push_back({it[1],it[3]});
        }
        return canMake(hori) || canMake(veri);
    }
};