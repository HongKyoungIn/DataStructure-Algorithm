#include <iostream>

using namespace std;

// ���� ���� ����Ʈ�� ��� ������ Ŭ������ ����
template <typename T>
class DoubleLinkedList {
public:
	struct Node {
		T data;
		Node* Prev;
		Node* Next;
	};

private:
	Node* Head = nullptr;
	Node* Tail = nullptr;

public:
	// ������
	DoubleLinkedList() : {
		
	}

	// �Ҹ���
	~DoubleLinkedList() {

	}

	// ��带 �����ϴ� �Լ�
	void InsertNode(Node* pos, T data) {
		if(Head == nullptr) {

		}
		// 1. �ְ��� �ϴ� ��ġ�� ã�´�.
		// 2. �� ��ġ�� �ش��ϴ� Next�� �ְ��� �ϴ� �ּҷ� �ٲ۴�.
		// 3. �ְ��� �ϴ� ����� Prev�� �ִ´�.
		// 4. 
	}

	// ��带 �����ϴ� �Լ�
	void DeleteNode() {

	}

	// Node Ž�� �Լ�
	Node* SearchNode(T data) {
		Node* temp = Head; // Head���� ����
		while(temp != nullptr) { // ����Ʈ�� ������ Ž��
			if(temp->data == data) {
				return temp; // �����Ͱ� ��ġ�ϴ� ��带 ã���� ��ȯ
			}
			else {
				temp = temp->Next; // ���� ���� �̵�
			}
		}
		return nullptr; // ã�� �������� nullptr ��ȯ
	}

	// ��带 ����ϴ� �Լ�
	void PrintNode() {

	}
};

int main() {
	DoubleLinkedList<int> DL;
	DL.InsertNode(DL.SearchNode(10), 20);

	return 0;
}