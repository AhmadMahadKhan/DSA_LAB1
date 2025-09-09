#include <iostream>
#include <vector>
using namespace std;
// this method prints the matrix
void print_matrix(const vector<vector<int>> &M)
{
    for (const vector<int> &row : M)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}
// this naive methos will return a 2d vector 
vector<vector<int>> multiply_naive(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
// added method that will add the vectos
vector<vector<int>> add(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
// subract method that will subract the 2d vectos
vector<vector<int>> subtract(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
// implemeted the straseen algorithm whcih simplices the direct addition an dmultiplication 
// calculated m1 to m7 with help of geeksfor geek
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    if (n == 1)
    { // base case
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    // Split matrices
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
        A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)),
        B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Strassen’s 7 multiplications
    vector<vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));
    vector<vector<int>> M2 = strassen(add(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> M5 = strassen(add(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtract(A21, A11), add(B11, B12));
    vector<vector<int>> M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Combine results
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}
// test 2 with 2x2 matix
void test_2_matrix()
{
    cout << "test case1... 2x2 matrices" << endl;
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    auto naive = multiply_naive(A, B);
    auto stras = strassen(A, B);

    cout << "Naive result:" << endl;
    print_matrix(naive);
    cout << "Strassen result:" << endl;
    print_matrix(stras);
    cout << "test case passed..." << endl
         << endl;
}
// testing with random values with a 4x4 matirc
void test_4_matrix()
{
    cout << "test case2... 4x4 matrices" << endl;
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    vector<vector<int>> B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}};

    auto naive = multiply_naive(A, B);
    auto stras = strassen(A, B);

    cout << "Naive result:" << endl;
    print_matrix(naive);
    cout << "Strassen result:" << endl;
    print_matrix(stras);
    cout << "test case passed..." << endl
         << endl;
}
// testing with random values
void random_values()
{
    cout << "test case3... Fixed 4x4 values" << endl;
    vector<vector<int>> A = {
        {2, 1, 3, 4},
        {0, 5, 6, 1},
        {7, 2, 8, 3},
        {4, 9, 0, 5}};
    vector<vector<int>> B = {
        {6, 7, 2, 1},
        {3, 4, 5, 9},
        {8, 0, 6, 2},
        {1, 3, 7, 4}};

    auto naive = multiply_naive(A, B);
    auto stras = strassen(A, B);

    cout << "Naive result:" << endl;
    print_matrix(naive);
    cout << "Strassen result:" << endl;
    print_matrix(stras);
    cout << "test case passed..." << endl
         << endl;
}

int main()
{
    test_2_matrix();
    test_4_matrix();
    random_values();
    return 0;
}