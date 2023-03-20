/*House robber
 Recurrsive solution
 
 Time complexity --> 2^n
*/
class Solution {
private:
    int maxMoneyRobbed(int ind , vector<int>& nums) {
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        int pick = nums[ind] + maxMoneyRobbed(ind - 2 , nums);
        int nonPick = maxMoneyRobbed(ind - 1 , nums);

        return max(pick , nonPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return maxMoneyRobbed(n - 1 , nums);
    }
};

/* Memoisation solution*/

class Solution {
private:
    int maxMoneyRobbed(int ind , vector<int>& nums , int dp[]) {
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick =nums[ind] + maxMoneyRobbed(ind - 2 , nums , dp);
        int nonPick = maxMoneyRobbed(ind - 1 , nums , dp);

        return dp[ind] = max(pick , nonPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1];
        memset(dp , -1 , sizeof(dp));
        return maxMoneyRobbed(n - 1 , nums , dp);
    }
};


/*top dowm dp*/

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() <= 1) return nums.front();
        int n = nums.size();
        int dp[n + 1];
        memset(dp , -1 , sizeof(dp));

        dp[0] = nums[0];
        dp[1] = nums[1];;

        for(int i = 2; i < n; i++) {
        if(i > 2) dp[i] = max(dp[i - 2] , dp[i - 3]) + nums[i];
        else
        dp[i] =dp[i - 2] + nums[i];
        }
        int maxi = -1;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};
