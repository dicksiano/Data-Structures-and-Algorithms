int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
    int res = 0;
    vector< vector<int> > dp((int)matrix.size(), vector<int>((int)matrix[0].size(), 0) );
    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[0].size(); j++) 
            if(matrix[i][j] == '1') {
                dp[i][j] = 1;
                if(i > 0 && j > 0) dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1] ) ) ;
                res = max(res, dp[i][j]);
            } 
    return res * res;
}