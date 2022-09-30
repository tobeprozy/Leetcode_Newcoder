#include "../bits/stdc++.h"

using namespace std;

int main(){

    int *a,*b,c;
    a=(int *)0x500;
    b=(int *)0x520;
    c=b-a;
    cout<<c<<endl;
    a+=0x020;
    c=b-a;
    cout<<c<<endl;
    return 0;
}