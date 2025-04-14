
// jai shree ram



/*

Problem Description
 
 

Given a string A, Check if the length of the longest repeating sub-sequence is greater than or equal to 2,
A longest repeating sub-sequence is defined such that,
the two subsequences have the same string character at the same position
any ith character in the two subsequences shouldn’t have the same index in the original string
NOTE: If the Sub-sequence length is greater than or equal to 2 return 1, else return 0.

 



Problem Constraints
 1 <= |A| <= 100



Input Format
The first and only argument of input contains a string A.



Output Format
Return an integer, 0 or 1:

    => 0 : Length of Repeating subsequence is less than 2
    => 1 : Length of Repeating subsequence is greater than or equal to 2
 



Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"
 



Example Output
Output 1:

 1
Output 2:

 0
 

*/




int f(int i , int j , string &s , vector<vector<int>> &dp) {
    if(i == s.size() || j == s.size()) {
        return 0;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int op1 = 0 , op2 = 0;
    
    if(i == j || s[i] != s[j]) {
        op1 = f(i+1 , j , s , dp);
        op2 = f(i , j+1 , s , dp);
    }
    else {
        if(s[i] == s[j]) {
            op1 = 1 + f(i+1 , j+1 , s , dp);
        }
    }
    return dp[i][j] = max(op1 , op2);
}

int Solution::anytwo(string A) {
    int n = A.size();
    vector<vector<int>> dp(n , vector<int> (n , -1));
    int x = f(0 , 0 , A , dp);
    if(x >= 2) return 1;
    return 0;
}
