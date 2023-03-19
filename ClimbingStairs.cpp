class Solution {
private:
    int fib(int dp[] , int n) {
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];
        dp[n] = fib(dp , n - 1) + fib(dp , n - 2);

        return dp[n]; 
    }
public:
    int climbStairs(int n) {
        int dp[n + 1];
        memset(dp , -1 , sizeof(dp));

        return fib(dp , n);
    }
};

/* Time complexity --> O(N)
   space complexity --> O(N) + O(N)
*/

/*Using tabulation*/
class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        memset(dp , -1 , sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*Time complexity --> O(N)
  space complexity --> O(N)
*/

/*Using tabulation with space optimisation*/
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;

        int curr = 1;
        for(int i = 2; i <= n; i++) {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
