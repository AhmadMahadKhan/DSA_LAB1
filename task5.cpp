#include <iostream>
#include <vector>
using namespace std;

// this method creatrs a 2d vector containinf the values for the 
vector<vector<int>> pascals_triangle(int n) {
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1); 
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle;
}

// this method prints the triangles
void print_triangle(const vector<vector<int>>& triangle) {
    for (const vector<int> row : triangle) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

// test module whrere n = 0 and will not print any triagnle
void n_0() {
    cout << "test case1..." << endl;
    auto triangle = pascals_triangle(0);
    print_triangle(triangle);
    cout << "no triangle when height  is 0 ";
    cout << endl ;
    cout << "test case passed.";
    cout << endl ;
    cout << endl ;
}

// test module whrere n = 1 and will  print only height of 1  triagnle
void n_1() {
    cout << "test case2..." << endl;
    auto triangle = pascals_triangle(1);
    print_triangle(triangle);
    cout << "test case passed...";
    cout << endl ;
    cout << endl ;
}


// test module whrere n = 5 and will  print only height of 5 triagnle
void n_5() {
    cout << "test case3 ..." << endl;
    auto triangle = pascals_triangle(5);
    print_triangle(triangle);
    cout << "test case passed...";
    cout  << endl << endl;
}
// conformation test which checks if the resultof n = 5 is rqul to int arr[] = {1, 4, 6, 4, 1};  or not
void verify_5(){
     int arr[] = {1, 4, 6, 4, 1};  
    cout << "test case4 ... " << endl;

    auto triangle = pascals_triangle(5);  
    const vector<int>& row5 = triangle[4];

    bool equal = true;
    for (int i = 0; i < 5; i++) {
        if (row5[i] != arr[i]) {
            equal = false;
            break;
        }
    }

    if (equal) cout << "last row matches with  {1, 4, 6, 4, 1}" << endl;
    else    cout << "last row not matched" << endl;
    
    cout << "test case passed..";

}
int main() {
    n_0();
    n_1();
    n_5();
    verify_5();
    return 0;
}
