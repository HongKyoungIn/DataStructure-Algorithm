#include <iostream>

using namespace std;

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct Dnode {
	struct Dnode *Prev;
	char data[5];
	struct Dnode *Next;
} dNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	dNode *head;
} linkedList_h;

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h *createLinkedList_h() {
	linkedList_h *DL;
	DL = (linkedList_h *)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// ���� ���� ����Ʈ�� ������� ����ϴ� ����
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

// pre �ڿ� ��带 �����ϴ� ����
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

// ���� ���� ����Ʈ���� old ��带 �����ϴ� ����
void DeleteNode(linkedList_h *DL, dNode *old) {
	if(DL->head == NULL) { // ���� ����Ʈ�� ��� ���� ���� �ߴ�
		return;
	}
	else if(old == NULL) { // ������ ��尡 ���� ��� ���� ���� �ߴ�
		return;
	}
	else {
		old->Prev->Next = old->Next;
		old->Next->Prev = old->Prev;
		free(old); // ���� ����� �޸� ����
	}
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
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

	DL = createLinkedList_h(); // ���� ����Ʈ ����
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	PrintList(DL);
	getchar();

	printf("(2) ���� ���� ����Ʈ�� [Mon] ��� �����ϱ�! \n");
	InsertNode(DL, NULL, "Mon");
	PrintList(DL);
	getchar();

	printf("(3) ���� ���� ����Ʈ�� [Mon] ��� �ڿ� [Wed] ��� �����ϱ�! \n");
	p = SearchNode(DL, "Mon");
	InsertNode(DL, p, "Wed");
	PrintList(DL);
	getchar();

	printf("(4) ���� ���� ����Ʈ�� [Wed] ��� �ڿ� [Fri] �����ϱ�! \n");
	p = SearchNode(DL, "Wed");
	InsertNode(DL, p, "Fri");
	PrintList(DL);
	getchar();

	printf("(5) ���� ���� ����Ʈ���� [Wed] ��� �����ϱ�! \n");
	p = SearchNode(DL, "Wed");
	DeleteNode(DL, p);
	PrintList(DL);
	getchar();

	return 0;
}