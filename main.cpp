#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int **matrix = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) {
        matrix[i] = new int[n + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        matrix[0][i] = 0;
        matrix[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (a[i - 1] == b[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    cout << matrix[n][n] << endl;
    int *x = new int[matrix[n][n]];
    int *y = new int[matrix[n][n]];
    int i = n;
    int j = n;
    int length = matrix[n][n] - 1;
    while (i != 0 && j != 0) {
        if (a[i - 1] == b[j - 1]) {
            x[length] = i - 1;
            y[length] = j - 1;
            i--;
            j--;
            length--;
        } else {
            if (matrix[i][j] == matrix[i - 1][j])
                i--;
            else
                j--;
        }
    }
    for (int m = 0; m < matrix[n][n]; m++) {
        cout << x[m] << " ";
    }
    cout << endl;
    for (int m = 0; m < matrix[n][n]; m++) {
        cout << y[m] << " ";
    }
    cout << endl;
}
