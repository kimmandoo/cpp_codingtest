#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0), ios::sync_with_stdio(0);
    queue<int> q;
    q.push(1);
    q.pop();
    q.size();
    q.front();
    q.back();
    // front back pop은 q가 비어있을 경우 runtime error 가능성 있음

    return 0;
}