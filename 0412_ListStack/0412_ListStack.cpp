#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node *link;
}Node;

typedef struct {
	Node *top; // 스택의 top을 나타내는 포인터
}Stack;

void Init(Stack *s) {
	s->top = NULL;
}

bool Is_Empty(Stack *s) {
	return (s->top == NULL);
}

void push(Stack *s, int item) {
	Node *temp = (Node *)malloc(sizeof(Node)); // 동적노드 생성
	temp->data = item; // 새로운 노드에 입력할 값 복사
	temp->link = s->top; // 새로운 노드가 기존의 top 노드를 가르키도록 함
	s->top = temp; // temp 노드가 top 노드로 선언
}

int pop(Stack *s) {
	if(Is_Empty(s)) { // 스택이 비어 있는지 확인
		printf("stack empty\n");
	}
	else {
		Node *temp = s->top; // temp포인터를 top노드를 가르키도록 함
		int data = temp->data; // 삭제한 값 반환하기 위해서 기존의 데이터를 temp노드에 삽입
		s->top = s->top->link; // top 노드는 기존의 top노드가 가르키는 노드가 됨
		free(temp); // 동적 메모리 해제
		return data; // 삭제할 값 반환
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