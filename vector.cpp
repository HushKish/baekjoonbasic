#include<iostream>
#include<vector>
using namespace std;
int main(void){
    //vector선언,int대신 자른 자료형or클래스를 넣어도됨,만들어지는 메모리크기만 달라지는 것
    vector<int> v;
    vector<int> v = { 1, 2, 3 };//백터생성 후 1,2,3으로 초기화
    vector< pair<int,int> > p;
    vector<int> v[10];
    vector<vector<int>> v;//2차원
    vector<int> v(5);//5개의 원소를 5로 초기화
    vector<int> v(5,3);//5개의 원소를 3으로 초기화
    vector<int> v2(v);//백터 v를 복사해서 백터 v2생성
    int myInt[]={31,2,35,45,23,76,56,3};
    vector<int> v(myInt,myInt+8);//첫번째 인자에 들어있는 주소부터 두번째 주소까지의 원소복사 두번째인자는 위 배열의 끝을 가리킴

    //vector값 추가
    v.push_back(10);//마지막위치에 10추가
    vector<int>::iterator it = v.begin();
    it = v.insert(it, 2);//맨앞에 2를 삽입 it=이렇게 리턴값을 it에 담아주지 않으면 it에 안드로매다값이 담김
    it = v.insert(it, 2, 3);//맨앞에 3을 2개삽입 이후 it에는 삽입된 3중 앞에있는 3의 앞을 가리킴
    it = v.insert(it+2,2,4);
    

    //vector 값 삭제
    v.pop_back();//마지막에 있는 원소제거
    v.erase(v.begin()+10);//idx가 10인 값을 제거->여기서 idx는 배열과 같은 의미(0부터시작)
    v.erase(v.begin(), v.begin()+5);
    v.clear();//vector의 모든값제거

    //vector 크기 구하기
    v.size();//들어있는 원소의 개수
    v.capacity();//vector의 물리적 크기(현재 최종저장가능한 크기)

    //vector 값 출력
    for(int i=0; i < v.size(); i++) cout << v[i] <<" ";
    cout << v[2] << v.front() << v.back();//2번째요소,1번째요소,마지막 원소출력가능


    return 0;
}