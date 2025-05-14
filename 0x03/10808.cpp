#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    string input;
    cin >> input;
    int abc[26]; // 전역변수에 선언하면 0이 들어가는 데, 지역변수라 쓰레기값이 들어감
    fill(abc, abc+26, 0);

    // for(int i=0; i<input.length(); i++){
    //     abc[input.at(i)-97]++;
    // }
    
    for(auto c: input){ // auto로 string을 그냥 뽑을 수 있다.
        // abc[(int)c - 97]++;
        abc[c - 'a']++;
    }

    for(int i: abc){
        cout << i << " ";
    }

    return 0;
}