#include<iostream>
using namespace std ;
// in nave method one by one a set of char is used as a string
// which is compared to retrunr the asner
int naive_patern_match(const string& text, const string& pattern) {
    if (pattern.empty()) return -1; 

    int n = text.size();
    int  m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) {
            return i; 
        }
    }
    return -1; 
}
// test module 1 : whreer the patterne in presetn and is at the beginging
void pattern_at_the_begining() {

    cout << "test case1..." ;
    cout << endl;
    string text = "this is a test string";
    string pattern = "his";
    
    cout << "Index of matching : " << naive_patern_match(text, pattern) ;
    cout << endl;
    cout << "test case passsed";
cout << endl;
}

// test module 2 : whreer the patterne in presetn and is at the end
void pattern_at_the_end() {
    string text = "this is a test";
    string pattern = "test";
    cout << "test case 2...." ;
    cout << endl ;
   cout << "Index of matching : " << naive_patern_match(text, pattern) ;
   cout << endl ;
cout << "test case passsed";
cout << endl;
}

// test module 3 : whreer the patterne in not presetn 
void pattern_not_present() {
    string text = "abcdef";
    string pattern = "xyz";
    cout << "test case3...";
    cout << endl;
    cout << "-1 if the pattern not exists: " << naive_patern_match(text, pattern) ;
    cout<< endl;
    
cout << "test case passsed";
cout << endl;
}

// test module 1 : whreer the patterne in not presetn 
void empty_pattern() {
    string text = "abcdef";
    string pattern = "";
    
    cout << "-1 if there was no pattern: " << naive_patern_match(text, pattern) ;
    cout<< endl ;
    cout << "test case passsed";
cout << endl;
}

int main() {
    pattern_at_the_begining();
    pattern_at_the_end();
    pattern_not_present();
    empty_pattern();
    return 0;
}