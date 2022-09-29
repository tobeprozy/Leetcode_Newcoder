#include<bits/stdc++.h>

using namespace std;

bool iseq(string &s1,string &s2){
    
    int a=-1;int b=-1;
    
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            if(a==-1) a=i;
            else if(b==-1) b=i;
            else return false;
        }
    }
    return s1==s2||a!=-1&&b!=-1&&s1[a]==s2[b]&&s1[b]==s2[a];
}

bool iseq2(string &s1,string &s2){
    int n1,n2,i;
    if(s1==s2) return true;
    
    for(int i=0;s1[i]==s2[i]&&i<s1.size();i++);
    n1=i;
    for(int i=n1+1;s1[i]==s2[i]&&i<s1.size();i++);
    if(i==s1.size()) return false;
    n2=i;
    for(int i=n2+1;i<s1.size()&&s1[i]==s2[i];i++);
    if(s1[n1]==s2[n2]&&s1[n2]==s2[n1]&&i==s1.size()) return true;
    else return false;
    
}

int main(){
    int n;cin>>n;
    
    while(n--){
        string str1,str2;
        cin>>str1>>str2;
        if(iseq(str1,str2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
    
}