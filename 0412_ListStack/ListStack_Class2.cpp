#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *link;
};

class Stack {
public:
    Node *top = NULL; // ������ top�� ��Ÿ���� ������, �ʱ�ȭ �߰�
};

void Init(Stack *s) { // �����ͷ� ���޹���
    s->top = NULL; // �����͸� ����Ͽ� ����� ����
}

bool Is_Empty(Stack &s) { // ������ ����
    return (s.top == NULL);
}

void push(Stack &s, int item) { // ������ ����
    Node *temp = new Node(); // ������� ����
    temp->data = item; // ���ο� ��忡 �Է��� �� ����
    temp->link = s.top; // ���ο� ��尡 ������ top ��带 ����Ű���� ��
    s.top = temp; // temp ��尡 top ���� ����
}

int pop(Stack &s) { // ������ ����
    if(Is_Empty(s)) { // ������ ��� �ִ��� Ȯ��
        cout << "stack empty" << endl;
        return -1; // ������ ��������� -1 ��ȯ
    }
    else {
        Node *temp = s.top; // temp�����͸� top��带 ����Ű���� ��
        int data = temp->data; // ������ �� ��ȯ�ϱ� ���ؼ� ������ �����͸� temp��忡 ����
        s.top = s.top->link; // top ���� ������ top��尡 ����Ű�� ��尡 ��
        delete temp; // ���� �޸� ����, C++������ free ��� delete ���
        return data; // ������ �� ��ȯ
    }
}

void print_stack(Stack &s) { // ������ ����
    for(Node *p = s.top; p != NULL; p = p->link)
        cout << p->data << "-> ";
    cout << "NULL" << endl;
}

int main() {
    Stack s;
    Init(&s); // �����͸� ����
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
