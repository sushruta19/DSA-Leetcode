class Solution {
private:
    void subset_gen(const vector<int>& nums, int idx, vector<int>& ds, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        subset_gen(nums, idx+1, ds, ans);

        ds.pop_back();
        subset_gen(nums, idx+1, ds, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset_gen(nums, 0, ds, ans);
        return ans;
    }
};