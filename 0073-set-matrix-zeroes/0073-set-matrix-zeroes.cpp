class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_set<int> rows_with_zero;
    unordered_set<int> cols_with_zero;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rows_with_zero.insert(i);
                cols_with_zero.insert(j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows_with_zero.count(i) ||  cols_with_zero.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
    }
    };
