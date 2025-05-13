#include <iostream>
#include <vector> // stl 잘 외워두자 -> 배열쓰기

using namespace std;

struct pt{
    int x, y;
};

void swap(int& a, int& b){ // cpp 참조연산자 -> int reference
    int tmp = a;
    a = b;
    b = tmp;
}

void vector_prac(){
    vector<int> v(100); // 자바의 Arraylist<Integer> k = new ArrayList(100);
    v[20] = 100;
    v[23] = -10;
    cout << v[20] << endl;
    cout << v[23] << endl;
}

// 구조체와 stl(vector)는 함수 인자로 전달하면 복사본을 보내기 때문에 원본에 영향을 주지 않는다.
// 원본에서 복사본 만들 때 O(n) -> 이걸 해결하려면 reference 연산자를 사용하면 된다.
bool cmp(vector<int>& v1, vector<int>& v2, int idx){ // 참조대상의 주소만 넘겨서 쓰기 때문에 의도한 대로 O(1)짜리 코드가 됨
    return  v1[idx] > v2[idx]; 
}

void getline_input(){
    string s;
    getline(cin, s);
    cout << s;
}

// scanf, printf말고, cin, cout 쓸 때는 아래 두 줄 꼭 외우기 - stream이 c, cpp 다르니까 섞어 쓰지마라
// ios::sync_with_stdio(0); cin.tie(0); // 이거 안하면 입출력 많을 때 시간초과 남 
// endl 절대 쓰지마라 -> 개행문자 출력하고 출력버퍼 비우라는 말

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 버퍼를 다루기 때문에 main함수 안에서 작성
    // 디버거는 따로 쓰지말고, print로 확인하는 습관 들일 것
    int k = 0;
    // short, int(4byte), long long(8byte), unsigned long long, string
    // float(4byte - 유효숫자 6자리), double(8byte - 유효숫자 15자리 k*10^x)
    // 실수를 써야되면 무조건 float 쓰기    
    // long long 은 최대 19자리 -> double에 넣으면 문제가 생김 -> int는 double에 넣어도 됨
    // 실수비교는 등호 사용 금지
    // abs(a-b) < 1e-12 -> 소수자리 0.000000000001보다 작은 차이를 가지면 같다고 봐도 됨
    // cin >> k;
    // cout << "Hello, World! " << k << endl;
    vector_prac();
    getline_input();
    
    return 0;
}