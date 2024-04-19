#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <Windows.h>

#define MAX_WORDS 100
#define MAX_LENGTH 15   // 단어의 최대 알파벳 숫자는 14개, 끝은 ‘\0’

// 문자열의 길이를 알아내는 함수
int string_length(char *str) {
    int length = 0;

    while(str[length] != '\0') {
        length++;
    }

    return length;
}

char words[MAX_WORDS][MAX_LENGTH] = {
    "elephant",
    "computer",
    "keyboard",
    "television",
    "umbrella",
    "backpack",
    "restaurant",
    "astronaut",
    "basketball",
    "pineapple",
    "hamburger",
    "telephone",
    "notebook",
    "calendar",
    "landscape",
    "calculator",
    "motorcycle",
    "chocolate",
    "watermelon",
    "skateboard",
    "microphone",
    "helicopter",
    "binoculars",
    "refrigerator",
    "headphones",
    "backwards",
    "celebrate",
    "definitely",
    "knowledge",
    "whispering",
    "vegetables",
    "refreshing",
    "incredible",
    "determined",
    "wonderful",
    "generation",
    "expensive",
    "brilliant",
    "invisible",
    "university",
    "happiness",
    "terrifying",
    "vacuuming",
    "appreciate",
    "interested",
    "beautifully",
    "discovery",
    "disgusting",
    "encouraged",
    "excitement",
    "accidentally",
    "continuous",
    "destruction",
    "development",
    "environment",
    "fascinating",
    "imagination",
    "independent",
    "information",
    "intelligence",
    "mathematics",
    "opportunity",
    "personality",
    "photography",
    "population",
    "preparation",
    "realization",
    "satisfaction",
    "technically",
    "understanding",
    "appropriate",
    "communication",
    "comprehensive",
    "complicated",
    "consciousness",
    "consideration",
    "determination",
    "entertainment",
    "environmental",
    "implementation",
    "impressionist",
    "intentionally",
    "international",
    "interpretation",
    "investigation",
    "organization",
    "participation",
    "perspective",
    "professional",
    "recommendation",
    "responsibility",
    "sophisticated",
    "technological",
    "unfortunately",
    "administration",
    "communication",
    "consideration",
    "demonstration",
    "environmental",
    "implementation"
};

int main() {
    srand(time(NULL));
    int random_variable = rand() % 100;

    // 실패한 횟수를 저장하는 변수
    int fail = 0;

    // words에서 랜덤하게 뽑은 문자열을 저장하는 변수
    char *str = *(words + random_variable);
    
    // 문자열의 길이를 알아내는 함수 호출
    int length = string_length(str);
    printf("length : %d\n", length);

    // 사용자가 입력하는 문자를 저장하는 변수
    char c;

    // 사용자가 입력한 문자가 문자열에 다 맞는지 확인하는 변수
    int succes = 0;

    // 사용자가 입력한 문자가 맞았을 때 문자열을 저장하는 배열
    // 널 및 string 길이만큼 '_' 로 초기화
    char saveUserString[15] = {'\0',};
    for(int i = 0; i < length; i++) {
        saveUserString[i] = '_';
    }
    
    printf("3번 실패하면 패배합니다.\n\n");

    // 처음 실행 시 글자수를 보여주기 위한 반복문
    for(int i = 0; i < length; i++) {
        printf("_");
    }

    printf("\n\n");

    while(fail <= 3) {
        // 입력한 문자가 문자열에 있는지 없는지 확인하는 변수
        bool chrCheck = 0;
        // 아직 실패한 횟수가 3이 아닐 때의 조건문
        if(fail != 3) {
            printf("문자를 입력하세요 : ");

            // 사용자의 문자를 입력 받는다.
            c = getchar();
            // 엔터 입력 시 엔터도 버퍼에 동시에 들어오므로 엔터 입력을 제거한다.
            while(getchar() != '\n');

            // 사용자의 입력과 정답 문자열과 비교하는 반복문
            for(int i = 0; i < length; i++) {
                // 만약 같은 문자가 정답 문자열에 있다면
                if(str[i] == c) {
                    // 이미 입력했던 문자 정답에 해당하지만 이전에 입력한 문자가 아니라면
                    if(saveUserString[i] != c) {
                        // 새로운 문자를 저장한다.
                        saveUserString[i] = c;
                        // 성공 여부를 위한 변수 증가
                        succes++;
                        // 일치한 문자가 있는지 확인하기 위한 변수를 true로 대입
                        chrCheck = 1;
                    }
                    // 이미 입력했던 문자인지 확인
                    else {
                        chrCheck = 1;
                    }
                }
            }
            // 이전에 입력했던 문자열을 반영하여 문자열 출력
            printf("%s\t", saveUserString);

            // 만약 입력한 문자열이 포함되어 있지 않다면
            if(chrCheck == 0) {
                // 실패 횟수 증가
                fail++;
                printf("Wrong  = %d ", fail);
            }
            printf("\n");
        }
        // 만약 3번 실패했다면 실패 문구 출력
        else {
            printf("실패했습니다.\n");
            printf("정답은 \"%s\" 입니다.", str);
            break;
        }

        // 성공했을 시 성공 문구 출력
        if(succes == length) {
            printf("성공했습니다.\n");
            printf("정답은 \"%s\" 입니다.", str);
            break;
        }
    }

    Sleep(2000);

    return 0;
}
