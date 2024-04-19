#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

void charAdd(char *arrayA, char *arrayB, char *result) {
    // 피보나치 수열에 사용할 앞선 2개의 숫자를 받을 배열 선언
    char num_a[100];
    char num_b[100];

    // 앞서 들어온 문자열을 num_a와 num_b에 저장
    strncpy_s(num_a, sizeof(num_a), arrayA, _TRUNCATE);
    strncpy_s(num_b, sizeof(num_b), arrayB, _TRUNCATE);

    // 자리수가 안 맞을 경우를 대비하기 위해 앞 자리를 0으로 채워 100자리를 맞출 배열 선언
    char num_a_[100];
    char num_b_[100];

    // 계산해서 나온 배열을 *result에 넘길 임시 결과 배열 선언
    char tempResult[101] = {};

    // 올림수
    int carry = 0;

    // 더한수
    int sum = 0;

    // 배열 출력을 위한 인덱스
    int i = 0;

    // num_a_와 num_b_에 0으로 채워 100자리 수를 만든다.
    sprintf_s(num_a_, sizeof(num_a_), "%099s", num_a);
    sprintf_s(num_b_, sizeof(num_b_), "%099s", num_b);

    // 올림수를 고려하여 더한 수를 저장하는 반복문
    for(i = sizeof(num_a_) - 2; i >= 0; i--) {
        sum = (num_a_[i] - '0') + (num_b_[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        tempResult[i + 1] = sum + '0';
    }
    tempResult[0] = carry + '0';

    // 결과 문자열의 앞부분에 있는 0을 제외하고 출력
    for(i = 0; tempResult[i] == '0'; i++);

    // 나온 결과를 *reuslt에 넘겨준다.
    strcpy_s(result, 100, &tempResult[i]);
}

int main() {
    // 피보나치 배열을 선언
    char fibonacci[101][101] = {{"0"},{'1'},};

    // 3번째 배열부터 앞의 2개의 숫자를 더해 저장
    for(int i = 2; i < 101; i++) {
        charAdd(fibonacci[i - 1], fibonacci[i - 2], fibonacci[i]);
    }

    // 결과 출력
    for(int i = 0; i < 2; i++) {
        cout << "[" << i << "] = " << fibonacci[i] << endl;
    }

    // 결과 출력
    for(int i = 2; i < 101; i++) {
        cout << "[" << i << "] = " << "[" << i - 2 << "] + [" << i - 1 << "] = " << fibonacci[i] << endl;
    }

    Sleep(2000);

    return 0;
}
