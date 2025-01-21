class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        function <void(int)> dfs = [&](int idx) -> void {
            if (idx == nums.size()) {
                ans.push_back(curr);
                return;
            }
            curr.push_back(nums[idx]);
            dfs(idx+1);

            curr.pop_back();
            dfs(idx+1);
        };
        dfs(0);
        return ans;
    }
};