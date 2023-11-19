#include<bits/stdc++.h>
using namespace std;


int f(int ind , int W , vector<int>&wt , vector<int>&val , vector<vector<int>>&dp)
{
    if(ind == 0)
    {
        if(wt[0]<= W)
        {
            return val[0];
        }
        return 0;
    }

    if(dp[ind][W] != -1) 
    {
       return dp[ind][W];
    }

    int notTake =  0 + f(ind-1 , W, wt , val  , dp);
    int take = INT_MIN;
    if(wt[ind]<=W)
    {
        take = val[ind]+f(ind-1 , W-wt[ind],wt, val , dp);
    }
    return dp[ind][W] = max(take , notTake);
}

int knapsack(int n , int W , vector<int>&wt , vector<int>&val)
{
    vector<vector<int>>dp(n ,vector<int>(W+1,-1));
    return f(n-1 ,W,wt, val ,dp );
}

int tabulation(vector<int>& wt, vector<int>& val, int n, int W) {
    // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base condition: Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }

            // Update the DP table
            dp[ind][cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][W];
}
int main()
{
    cout<<"Enter the number of items : ";
    int n ; 
    cin>>n;
    cout<<endl;
    vector<int>wt;
    vector<int>val;
    cout<<"Enter the weights and profits of the items : ";
    
    int x ,y;
    for(int i = 0 ; i<n ;i++)
    {
        cin>>x;
        wt.push_back(x);
        
    }
    for(int i = 0 ;i<n ;i++)
    {
        cin>>y;
        val.push_back(y);
    }
    cout<<endl;
    cout<<"Enter capacity of knapsack : ";
    int W;
    cin>>W;
    cout<<"Maximum Profit : (Memoization) " <<knapsack(n , W , wt , val)<<endl;
    cout<<"Maximum Profit : (Tabulation) " <<tabulation( wt , val , n , W);
    return 0;
}
/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/