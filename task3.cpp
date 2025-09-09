#include <iostream>
#include <vector>
using namespace std;
// a function that wll return all the indicies of the given key
vector<int> find_indicies(vector<int> arr, int key)
{
    vector<int> indicies;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            indicies.push_back(i);
        }
    }
    return indicies;
}
// a test module to check the dublicancy od the indicies
void multiple_occurence(vector<int> arr)
{

    int key = 2;
    cout << "test case 1 ...";
    cout << endl;
    vector<int> result1 = find_indicies(arr, key);
    cout << "Indices of " << key << " in arr1: ";
    if (result1.empty())
    {
        cout << "Not found";
    }
    else
    {
        for (int index : result1)
            cout << index << " ";
        cout << endl;
    }
    cout << "test case passed...";
    cout << endl;
}
// a module to check if the  key is present or not 
// by using find_indicies function if empty no key exits
void key_not_present(vector<int> arr)
{
    cout << "test case2....";
    cout << endl;
    int key = 10;
    vector<int> result = find_indicies(arr, key);
    cout << "Indices of " << key << " in arr2: ";
    if (result.empty())
    {
        cout << "Not found";
    }
    else
    {
        for (int idx : result)
            cout << idx << " ";
        cout << endl;
    }
    cout << endl;
    cout << "test case2 passed..";
    cout << endl;
}

// this modules check if the array is empty  or not 
//  the result is determinded bu the find_indicies module
void empty_array(vector<int> arr)
{

    cout << "test case3...";
    cout << endl;
    int key = 1;
    vector<int> result = find_indicies(arr, key);
    cout << "Indices of " << key << " in arr: ";
    if (result.empty())
        cout << "Not found";
    else
        for (int idx : result)
            cout << idx << " ";
    cout << endl;
    cout << "test case 3 passed";
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 5, 6, 7, 2, 2, 8, 9};
    multiple_occurence(arr);
    key_not_present(arr);
    empty_array(arr);

    return 0;
}