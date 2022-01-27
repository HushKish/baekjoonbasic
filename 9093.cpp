#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    cin.ignore();/*in을 사용하면 무조건 \n이 버퍼에 입력되는데 getline은 cin과 다르게 입력된 것이 없더라도 \n을 만나면 입력을 종료하고 
    cin다음 getline을 하면 공백문자가 들어감
    cin은 scanf와 달리 타입과 상광없이 동일함,즉 문자열을 받을때나 정수를 받을때나 버퍼상황같은 것이 동일*/
    while(t--){
        string str;
        getline(cin,str);//공백포함 문장 입력받을때
        str+='\n';
        stack<char> s;
        for(char ch : str){
            if(ch==' ' || ch=='\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
            }
            else{
                s.push(ch);
            }
        }
    }
    return 0;
}