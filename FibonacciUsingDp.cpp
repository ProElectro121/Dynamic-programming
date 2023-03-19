class Solution {
private:
    int fibo(int n , int dp[]) {
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
public:
    int fib(int n) {
        // int dp[n + 1];
        // memset(dp , -1 , sizeof(dp));

        return fibo(n , dp);
    }
};

/*
   Time complexity --> O(N)
   space complexity --> O(N) -> dp array
                        O(N) -> recurrsion stack
*/



/*using tabulation method*/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int dp[n + 1];
        memset(dp , -1 , sizeof(dp));

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

Time complexity --> O(N)
space complexity --> O(N)


/*Using tabulation with space optimistation*/

class Solution {
public:
    int fib(int n) {
        int prev = 1;
        int prev1 = 0;

        int curr = n;
        for(int i = 2; i <= n; i++) {
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};
Time complexity --> O(N)
space complexity --> O(1)
