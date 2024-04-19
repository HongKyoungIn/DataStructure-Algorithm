#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *link;
};

class Stack {
public:
    Node *top = NULL; // 스택의 top을 나타내는 포인터, 초기화 추가
};

void Init(Stack *s) { // 포인터로 전달받음
    s->top = NULL; // 포인터를 사용하여 멤버에 접근
}

bool Is_Empty(Stack &s) { // 참조로 전달
    return (s.top == NULL);
}

void push(Stack &s, int item) { // 참조로 전달
    Node *temp = new Node(); // 동적노드 생성
    temp->data = item; // 새로운 노드에 입력할 값 복사
    temp->link = s.top; // 새로운 노드가 기존의 top 노드를 가르키도록 함
    s.top = temp; // temp 노드가 top 노드로 선언
}

int pop(Stack &s) { // 참조로 전달
    if(Is_Empty(s)) { // 스택이 비어 있는지 확인
        cout << "stack empty" << endl;
        return -1; // 스택이 비어있으면 -1 반환
    }
    else {
        Node *temp = s.top; // temp포인터를 top노드를 가르키도록 함
        int data = temp->data; // 삭제한 값 반환하기 위해서 기존의 데이터를 temp노드에 삽입
        s.top = s.top->link; // top 노드는 기존의 top노드가 가르키는 노드가 됨
        delete temp; // 동적 메모리 해제, C++에서는 free 대신 delete 사용
        return data; // 삭제할 값 반환
    }
}

void print_stack(Stack &s) { // 참조로 전달
    for(Node *p = s.top; p != NULL; p = p->link)
        cout << p->data << "-> ";
    cout << "NULL" << endl;
}

int main() {
    Stack s;
    Init(&s); // 포인터를 전달
    push(s, 11); print_stack(s);
    push(s, 22); print_stack(s);
    push(s, 33); print_stack(s);
    push(s, 44); print_stack(s);

    pop(s); print_stack(s);
    pop(s); print_stack(s);
    pop(s); print_stack(s);
    pop(s); print_stack(s);
    return 0;
}
