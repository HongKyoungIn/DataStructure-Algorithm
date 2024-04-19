#include "pch.h"
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

void rule() {
    cout << "1) 3자리 숫자와 위치가 모두 맞아야 성공입니다." << endl;
    cout << "2) 숫자는 1~9까지 구성되어 있으며, 각 숫자는 한번씩만 사용 가능합니다." << endl;
    cout << "3) 숫자와 자리의 위치가 맞으면 스트라이크(S), 숫자만 맞으면 볼(B) 입니다." << endl;
    cout << "4) 숫자가 하나도 맞지 않을 경우 아웃(OUT) 으로 표시됩니다." << endl;
    cout << endl;
}

int Duplication_Check(string str) {
    for(int i = 0; i < str.length(); i++) {
        char temp = str[i];
        string temp_str = "";

        for(int j = i + 1; j < str.length(); j++) {
            temp_str += str[j];
        }

        if(temp_str.find(temp) != string::npos) { // find 함수는 대상 문자열 안에 해당하는 찾고자 하는 문자열이 없다면 string::npos 반환합니다.
            return 1; // 따라서 string::npos를 반환하지 않는다면 찾고자 하는 문자열이 대상 문자열에 존재하므로 1을 반환합니다.
            break;
        }
    }
    return 0;
}


int main() {
    rule();

    string a = "123456789";
    string num;
    string baseball;

    int strike = 0;
    int ball = 0;
    int temp = 0;

    // srand 함수는 난수 생성기를 초기하는 데 사용됩니다. 이 함수에달하는 값이 난수 생성기의 "시드" 값이 됩니다.
    // time(NULL) : 이 부분은 현재 시간을 초 단위로 반환하는 함수입니다. time 함수의 인자로 NULL을 넣으면, 1970년 1월 1일 00:00:00(UTC)부터 현재까지의 시간을 초 단위로 계산해 반환합니다.
    // static_cast<unsigned int>는 주어진 값을 부호 없는 정수로 변환하려고 시도합니다.
    srand(static_cast<unsigned int>(time(NULL)));

    random_shuffle(a.begin(), a.end()); // a의 문자열을 랜덤하게 섞습니다.

    for(int i = 0; i < 3; i++) { // baseball 문자열에 무작위로 섞이 3자리 숫자를 넣습니다.
        baseball += a[i];
    }
    
    for(int n = 0; n < 10; n++) {
        cout << "(" << n + 1 << "번 째 시도)중복되지 않는 3자리 숫자를 입력하세요 : ";
        cin >> num;

        if(num.length() != 3) { // 만약 사용자가 3자리 수가 아닌 수를 입력하면 다시 입력 받습니다.
            cout << "3자리 수를 입력하세요." << endl;
            cout << endl;
            n--;
            continue;
        }
        if(Duplication_Check(num) == 1) { // 만약 사용자가 3자리 수가 아닌 수를 입력하면 다시 입력 받습니다.
            cout << "중복된 숫자가 있습니다." << endl;
            cout << endl;
            n--;
            continue;
        }

        for(int i = 0; i < 3; i++) { // 만약 입력한 문자열의 자리와 숫자가 일치하면 strike를 1 증가시킵니다.
            if(num[i] == baseball[i]) {
                strike++;
            }
        }

        for(int j = 0; j < 3; j++) { // 만약 입력한 값이 야구 숫자 문자열에 포함되어 있다면 ball을 1 증가시킵니다.
            if(baseball.find(num[j]) != string::npos) { 
                ball++; 
            }
        }

        if(strike == 0 && ball == 0) { // 만약 하나도 일치하는 숫자가 없다면 OUT을 반환합니다.
            cout << "OUT" << endl;
            cout << endl;
        }
        else { // OUT이 아니라면 Strike와 Ball을 알려줍니다.
            cout << strike << "S " << ball - strike << "B" << endl;
            cout << endl;
        }

        if(strike == 3) { // 만약 3Strike면 성공을 반환합니다.
            cout << "성공!" << endl;
            break;
        }

        if(n == 9 && strike != 3) { // 만약 10번안에 성공을 못 했을경우 실패를 반환합니다.
            cout << "실패!" << endl;
            cout << "정답 : " << baseball << endl;
            break;
        }

        strike = 0;
        ball = 0;
    }

    Sleep(3000);

    return 0;
}