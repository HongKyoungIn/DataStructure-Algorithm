#include <iostream>

using namespace std;

// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct Dnode {
	struct Dnode *Prev;
	char data[5];
	struct Dnode *Next;
} dNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	dNode *head;
} linkedList_h;

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h *createLinkedList_h() {
	linkedList_h *DL;
	DL = (linkedList_h *)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
void PrintList(linkedList_h *DL) {
	dNode *p;
	printf("DL = (");
	p = DL->head;
	while(p != NULL) {
		printf("%s", p->data);
		p = p->Next;
		if(p != NULL) {
			printf(", ");
		}
	}
	printf(") \n");
}

// pre 뒤에 노드를 삽입하는 연산
void InsertNode(linkedList_h *DL, dNode *pre, const char *x) {
	dNode *newNode;
	newNode = (dNode *)malloc(sizeof(dNode));
	strcpy_s(newNode->data, x);
	if(DL->head == NULL) {
		newNode->Next = NULL;
		newNode->Prev = NULL;
		DL->head = newNode;
	}
	else {
		newNode->Next = pre->Next;
		pre->Next = newNode;
		newNode->Prev = pre;
		if(newNode->Next != NULL) {
			newNode->Next->Prev = newNode;
		}
	}
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void DeleteNode(linkedList_h *DL, dNode *old) {
	if(DL->head == NULL) { // 공백 리스트인 경우 삭제 연산 중단
		return;
	}
	else if(old == NULL) { // 삭제할 노드가 없는 경우 삭제 연산 중단
		return;
	}
	else {
		old->Prev->Next = old->Next;
		old->Next->Prev = old->Prev;
		free(old); // 삭제 노드의 메모리 해제
	}
}

// 리스트에서 x 노드를 탐색하는 연산
dNode *SearchNode(linkedList_h *DL, const char *x) {
	dNode *temp;
	temp = DL->head;
	while(temp != NULL) {
		if(strcmp(temp->data, x) == 0) {
			return temp;
		}
		else {
			temp = temp->Next;
		}
	}
	return temp;
}

int main() {
	linkedList_h *DL;
	dNode *p;

	DL = createLinkedList_h(); // 공백 리스트 생성
	printf("(1) 이중 연결 리스트 생성하기! \n");
	PrintList(DL);
	getchar();

	printf("(2) 이중 연결 리스트에 [Mon] 노드 삽입하기! \n");
	InsertNode(DL, NULL, "Mon");
	PrintList(DL);
	getchar();

	printf("(3) 이중 연결 리스트에 [Mon] 노드 뒤에 [Wed] 노드 삽입하기! \n");
	p = SearchNode(DL, "Mon");
	InsertNode(DL, p, "Wed");
	PrintList(DL);
	getchar();

	printf("(4) 이중 연결 리스트에 [Wed] 노드 뒤에 [Fri] 삽입하기! \n");
	p = SearchNode(DL, "Wed");
	InsertNode(DL, p, "Fri");
	PrintList(DL);
	getchar();

	printf("(5) 이중 연결 리스트에서 [Wed] 노드 삭제하기! \n");
	p = SearchNode(DL, "Wed");
	DeleteNode(DL, p);
	PrintList(DL);
	getchar();

	return 0;
}