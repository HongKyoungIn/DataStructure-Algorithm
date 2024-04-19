#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node *link;
}Node;

typedef struct {
	Node *top; // ������ top�� ��Ÿ���� ������
}Stack;

void Init(Stack *s) {
	s->top = NULL;
}

bool Is_Empty(Stack *s) {
	return (s->top == NULL);
}

void push(Stack *s, int item) {
	Node *temp = (Node *)malloc(sizeof(Node)); // ������� ����
	temp->data = item; // ���ο� ��忡 �Է��� �� ����
	temp->link = s->top; // ���ο� ��尡 ������ top ��带 ����Ű���� ��
	s->top = temp; // temp ��尡 top ���� ����
}

int pop(Stack *s) {
	if(Is_Empty(s)) { // ������ ��� �ִ��� Ȯ��
		printf("stack empty\n");
	}
	else {
		Node *temp = s->top; // temp�����͸� top��带 ����Ű���� ��
		int data = temp->data; // ������ �� ��ȯ�ϱ� ���ؼ� ������ �����͸� temp��忡 ����
		s->top = s->top->link; // top ���� ������ top��尡 ����Ű�� ��尡 ��
		free(temp); // ���� �޸� ����
		return data; // ������ �� ��ȯ
	}
}

void print_stack(Stack *s) {
	for(Node *p = s->top; p != NULL; p = p->link)
		printf("%d-> ", p->data);
	printf("NULL \n");
}

int main() {
	Stack s;
	Init(&s);
	push(&s, 11); print_stack(&s);
	push(&s, 22); print_stack(&s);
	push(&s, 33); print_stack(&s);
	push(&s, 44); print_stack(&s);

	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}