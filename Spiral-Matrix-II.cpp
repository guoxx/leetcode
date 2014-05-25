/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

void _fill(int *matrix, int x, int size, int n){
    if(x == size - x - 1){
        matrix[x * size + x] = n;
        n = n + 1;
        return;
    }

    for(int i = x; i <= size - x - 1; ++i){
        matrix[x * size + i] = n;
        n = n + 1;
    }
    for(int i = x + 1; i <= size - x - 2; ++i){
        matrix[i * size + (size - x - 1)] = n;
        n = n + 1;
    }
    for(int i = size - x - 1; i >= x; --i){
        matrix[(size - x - 1) * size + i] = n;
        n = n + 1;
    }
    for(int i = size - x - 2; i >= x + 1; --i){
        matrix[i * size + x] = n;
        n = n + 1;
    }

    x = x + 1;
    if((x + 1) * 2 <= size){
        _fill(matrix, x, size, n);
    }
    else{
        if((x + 1) * 2 - size == 1){
            _fill(matrix, x, size, n);
        }
    }
}

int *_matrix(int n){
    int *m = (int*)malloc(sizeof(n) * n * n);
    _fill(m, 0, n, 1);
    return m;
}

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n <= 0){
            return vector<vector<int>>(n, vector<int>(n));
        }

        int *arr = _matrix(n);
        vector<vector<int>> vec(n, vector<int>(n));
        for (int i = 0; i < n; ++i){
            vec[i].assign(arr + i * n, arr + (i + 1) * n);
        }
        return vec;
    }
};
