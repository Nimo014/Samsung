#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
    if (l > r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    for (int i = l; i <= r; i++) {
        int coins = 0;
        if(nums[l - 1] != 1 && nums[r + 1] != 1){
             coins = nums[l - 1] * nums[r + 1];
        }
        else if(nums[l - 1] != 1){
             coins = nums[l - 1];
        }
        else if(nums[r + 1] != 1){
             coins = nums[r + 1];
        }
        else{
            coins = nums[i];
        }
        coins += helper(l, i - 1, nums, dp) + helper(i + 1, r, nums, dp);
        dp[l][r] = max(dp[l][r], coins);
    }

    return dp[l][r];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    cout << helper(1, nums.size() - 2, nums, dp) << endl;

    return 0;
}
