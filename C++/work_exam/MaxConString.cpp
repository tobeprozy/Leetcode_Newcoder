#include<bits/stdc++.h>

using namespace std;

//循环字符串中最大连续相同字符串的长度，，，，acoesa-----aa-----2
int main(int argc, const char** argv) {
    string str;cin>>str;
    int size=str.size();
    //vector<string> path(size);
    vector<string> path(size,"");
    int maxsize=0;
    int maxindex=0;
    for(int i=0;i<size;i++){
        int index=i;
        path[i]+=str[index];
        char pre=str[i];
        while(true){
        index=(index+1)%(str.size());
        if(pre==str[index]) path[i]+=str[index];
        else {
            if(maxsize>=path[i].size()){
            }else{
                maxsize=path[i].size();
                maxindex=i;
            }
           break; 
        }
    }
        
    }
    cout<<path[maxindex].size();
    return 0;
}