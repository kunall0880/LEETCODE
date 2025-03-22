class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> st;
        for (auto it : supplies) {
            st.insert(it);
        }
        vector<string> ans;
        int n = recipes.size();
        // for (int i = 0; i < n; i++) {
        //     int l = ingredients[i].size();
        //     int f = 0;
        //     for (int j = 0; j < l; j++) {
        //         if (st.find(ingredients[i][j]) == st.end()) {
        //             f = 0;
        //             break;
        //         }
        //         f = 1;
        //     }
        //     if (f == 1) {
        //         ans.push_back(recipes[i]);
        //         st.insert(recipes[i]);
        //     }
        // }
        int siz = n;
        while (siz--) {
            for (int i = 0; i < n; i++) {
                if(st.find(recipes[i])!=st.end()){
                    continue;
                }
                int l = ingredients[i].size();
                int f = 0;
                for (int j = 0; j < l; j++) {
                    if (st.find(ingredients[i][j]) == st.end()) {
                        f = 0;
                        break;
                    }
                    f = 1;
                }
                if (f == 1) {
                    ans.push_back(recipes[i]);
                    st.insert(recipes[i]);
                }
            }
        }
        return ans;
    }
};