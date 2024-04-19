#include <iostream>

using namespace std;

// 이중 연결 리스트의 노드 구조를 클래스로 정의
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
	// 생성자
	DoubleLinkedList() : {
		
	}

	// 소멸자
	~DoubleLinkedList() {

	}

	// 노드를 삽입하는 함수
	void InsertNode(Node* pos, T data) {
		if(Head == nullptr) {

		}
		// 1. 넣고자 하는 위치를 찾는다.
		// 2. 그 위치에 해당하는 Next를 넣고자 하는 주소로 바꾼다.
		// 3. 넣고자 하는 노드의 Prev를 넣는다.
		// 4. 
	}

	// 노드를 삭제하는 함수
	void DeleteNode() {

	}

	// Node 탐색 함수
	Node* SearchNode(T data) {
		Node* temp = Head; // Head부터 시작
		while(temp != nullptr) { // 리스트의 끝까지 탐색
			if(temp->data == data) {
				return temp; // 데이터가 일치하는 노드를 찾으면 반환
			}
			else {
				temp = temp->Next; // 다음 노드로 이동
			}
		}
		return nullptr; // 찾지 못했으면 nullptr 반환
	}

	// 노드를 출력하는 함수
	void PrintNode() {

	}
};

int main() {
	DoubleLinkedList<int> DL;
	DL.InsertNode(DL.SearchNode(10), 20);

	return 0;
}