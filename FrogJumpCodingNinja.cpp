/*  In this problem the frog can jump either one or two index , and cost is abs(a[i] - a[j] . Find the min cost from index 0 to 1)*/

/*Using memosiation
Time complexity --> O(N)
space complexity --> O(N) + O(N)
*/

int minjumps(int dp[] , int ind , vector<int>& nums) {
	if(ind == 0) return 0;
	int right = 1e9 + 1;
	int left = dp[ind] ==  -1 ?  minjumps(dp , ind - 1 , nums) + abs(nums[ind] - nums[ind - 1]) : dp[ind] ; 
	if(ind - 2 >= 0)
		right= dp[ind] ==  -1 ?  minjumps(dp , ind - 2 , nums) + abs(nums[ind] - nums[ind - 2]) : dp[ind]; 

	return dp[ind] = min(left , right);

}

int frogJump(int n, vector<int> &heights) {
    int dp[n + 1];
    memset(dp , -1 , sizeof(dp));
    return minjumps(dp , n - 1 , heights);
}

//Using tabulation

int frogJump(int n, vector<int> &nums) {
	int dp[n + 1];
	memset(dp , -1 , sizeof(dp));
   
    dp[0] = 0;
    dp[1] = abs(nums[1] - nums[0]);

    for(int i = 1;i < n; i++) {
    	if(i - 2 >= 0)
    	dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]) , dp[i - 2] + abs(nums[i] - nums[i - 2]));
    else
    	dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]) , (int)1e9 + 1);
    }
    return dp[n - 1];
}


//When nstead of jump upto two index if we allow jumping upto k index --

x
