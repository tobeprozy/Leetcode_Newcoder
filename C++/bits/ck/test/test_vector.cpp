#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> vec(5, 0);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    vec.resize(4);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}
