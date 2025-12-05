class Solution {
public:

    void solve(vector<int>& nums, vector<int>op, int idx, vector<vector<int>>& ans ){

        //base case
        if( idx >= nums.size() ){
            ans.push_back(op);
            return;
        }

        //exclude
        solve( nums, op, idx+1, ans );

        //include case
        int element = nums[idx];
        op.push_back(element);
        solve( nums, op, idx+1, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int>op;
        int idx = 0;
        solve( nums, op, idx ,ans);
        return ans;

    }
};
