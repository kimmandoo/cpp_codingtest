#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    // deque stl은 인덱스 접근이 가능한 특이한 성질이 있음
    deque<int> dq;

    dq.push_back(3);
    dq.push_front(2);
    for(auto c: dq){
        cout << c << "\n";
    }
    dq.empty();
    dq.clear();
    dq[2] = 1;
    dq.insert(dq.begin()+1, 33); // 2번째 위치에 33 삽입 
    dq.erase(dq.begin()+3);
    // vector와 비슷한 것 같지만 메모리 상 연속구조가 아니다.

    return 0;
}