class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                unordered_set<int> st;
                int prod1 = (nums[i] * nums[j]);
                for (int k = i + 1; k < j; k++) {
                    if (prod1 % nums[k] == 0) {
                        int d = prod1 / nums[k];
                        if (st.count(d)) {
                            count++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return count * 8;
    }
};