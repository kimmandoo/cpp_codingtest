#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// 야매 연결리스트
struct NODE{
    struct Node *prev, *nxt;
    int data;
};

const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX]; // 이전, 다음 원소의 포인터 대신 인덱스 저장하기
int unused = 1; // 새로운 원소가 들어갈 수 있는 인덱스 

void traverse(){
    int cur = nxt[0];
    while (cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur]; // 출력하고, cur이 다음 원소로 가리키고 있는 값을 cur로 해줌
    }
    cout << "\n\n";
}

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = unused; 
  // 삽입할 원소의 주소에서 다음 원소를 가리키고 있는 경우에는 
  // 다음원소가 가리키고 있는 이전 주소 위치를 삽입한 위치로 옮긴다
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  nxt[pre[addr]] = nxt[addr]; // 지워버릴 위치가 다음 위치로 가리키고 있는 곳을 지워버릴 위치의 이전원소랑 연결시켜서 삭제
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    // 0번지는 root로 시작원소 고정 // dummy node를 안 쓸 경우 아예 빈 LinkedList에 대한 예외처리가 필요함
    // int len; 길이 정보가 필요하면 원소 삽입 삭제 때 +/- 하면된다

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);


    list<int> L = {1,2}; // 1 2 초기화 시키기
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값 = 1을 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
    t = L.erase(t); 
    // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
    // 10 6 1 5, t가 가리키는 값은 5
    cout << *t << '\n'; // 5
    for(auto i : L) cout << i << ' '; // 순회 꿀팁 ^cpp11+
    cout << '\n';
    // cpp 11 미만이면 이터레이터 걸어서 돌려줘야됨
    for(list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';

    return 0;
}