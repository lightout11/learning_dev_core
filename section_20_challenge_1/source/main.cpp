#include <iostream>
#include <deque>

using namespace std;

bool is_palindrome(const string& s) {
    deque<char> d;
    for (char c : s) {
        if (c != ' ') {
            d.push_back(c);
        }
    }
    while (!d.empty()) {
        if (d.front() == d.back()) {
            d.pop_front();
            if (!d.empty()) {
                d.pop_back();
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << boolalpha << is_palindrome(s) << endl;
}