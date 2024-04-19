#include <iostream>

using namespace std;

#define MAX_SIZE 10

// Rear ��ġ�� ����. �� ������ ���Ե� ��ġ�� ����Ų��.
// Front���� ����. ���� ���� �����Ͱ� ���� ��ġ�� ����Ų��.
// Front �� Rear�� �������� ť�� ����ִٰ� �����Ѵ�.
template <typename T>
class Queue {
private:
    int rear; // ������ ����� ť�� ��ġ
    int front; // ���� ���� ���� �������� ��ġ
    bool empty = true; // ť�� ����ִ��� Ȯ���ϱ� ���� ����
    int Array[MAX_SIZE] = {'\0',}; // ť ����

public:
    Queue() { // ������ ����
        rear = 0; // ť�� ��ġ �ʱ�ȭ
        front = 0; // ť�� ��ġ �ʱ�ȭ
    }
    ~Queue() {

    }

    void Enqueue(T inputdata) { // ť�� �����͸� �ֱ� ���� �Լ�
        if(IsFull() == true) { // ���� ���� ���ִٸ�
            cout << "ť�� �� �� �ֽ��ϴ�." << endl;
            cout << "���� �õ����ּ���." << endl;
        }
        else { // ť�� ������ ����ִٸ�
            cout << inputdata << "�� �ֽ��ϴ�." << endl;
            Array[rear] = inputdata; // ���� rear ��ġ�� �����͸� �ִ´�.
            rear = (rear + 1) % MAX_SIZE; // rear�� ����Ű�� ��ġ�� 1 ������Ų��.
            empty = false; // ť�� �����Ͱ� �����Ƿ� empty ������ false�� �����Ѵ�.
        }
    }

    void Dequeue() { // ť�� �����͸� �����ϱ� ���� �Լ�
        if(empty == false) { // ���� ť�� ������� �ʴٸ� �����մϴ�.
            cout << Array[front] << "�� ���ϴ�." << endl;
            front = (front + 1) % MAX_SIZE; // front���� ���� ������ �����Ѵ�.
            if(front == rear) { // ���� Dequeue�� ������ �� front�� ����Ű�� ���� rear�� ���ٸ� ť�� ����ִٴ� ���� �ȴ�.
                empty == true; // empty ������ true�� ����.
            }
        }
        else {
            cout << "ť�� ����ֽ��ϴ�." << endl;
        }
    }

    int Size() { // ť�� ����� �˷��ִ� �Լ�
        if(abs(rear - front) == 0 && empty == false) { // ���� front�� rear�� ����Ű�� ��ġ�� ������ ������� �ʴٸ�
            return MAX_SIZE; // ť�� ���� á�ٴ� ���̹Ƿ� MAX_SIZE�� ��ȯ�Ѵ�.
        }
        else { // ����Ű�� ��ġ�� �ٸ��ٸ�
            return abs(rear - front); // ť�� ũ�⸦ ��ȯ
        }
    }

    bool IsFull() { // ť�� ���� á���� Ȯ���ϱ� ���� �Լ�
        if(Size() == MAX_SIZE) { // ���� Size() �Լ��� �������� �� MAX_SIZE�� ��ȯ�Ѵٸ�
            return true; // ���� �������Ƿ� true
        }
        else { // �� ���� ��쿣 false
            return false;
        }
    }
    
    void PrintQueue() { // ť�� ����� ���� ����ϱ� ���� �Լ�
        cout << "���� ť�� ����Ǿ� �ִ� �� : ";
        int temp = front; // ���� front ��ġ�� �ӽ÷� �����ϱ� ���� ����
        if(Size() == MAX_SIZE) { // ���� ť�� �����Ͱ� ���� ���ִٸ�
            cout << Array[temp % MAX_SIZE] << " "; // ���� front���� ���� 1�� ����Ѵ�.
            temp++; // ���� front���� ����Ű���� temp ���� ������Ų��.
            for(temp; temp % MAX_SIZE != rear % MAX_SIZE; temp++) { // temp�� ���� rear�� ����Ű�� �ִ� ��ġ������ �ݺ��Ѵ�.
                cout << Array[temp % MAX_SIZE] << " "; // rear�� ����Ű�� �� ������ �ݺ��Ͽ� ����Ѵ�.
            }
        }
        else { // ť�� ������ ���°� �ƴ϶��
            while(temp % MAX_SIZE != rear % MAX_SIZE) { // front���� rear�� ����Ű�� ������ ����Ѵ�.
                cout << Array[temp % MAX_SIZE] << " "; 
                temp++;
            }
        }
        cout << endl;
    }
};

int main(void) {
    Queue<int> queue;

    // ũ�Ⱑ 10�� ť�� 15���� �����͸� �ִ´�.
    // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140
    for(int i = 0; i < 15; i++) {
        queue.Enqueue(i * 10);
        cout << "ť�� ������ : " << queue.Size() << endl;
        cout << endl;
    }

    // ���� �� �� Ȯ��
    // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90
    queue.PrintQueue();
    cout << endl;

    // 5���� ť�� �����.
    for(int i = 0; i < 5; i++) {
        queue.Dequeue();
    }
    cout << endl;

    // ���� �� �� Ȯ��
    // 50, 60, 70, 80, 90
    queue.PrintQueue();
    cout << endl;

    // 5���� �����͸� �ִ´�.
    // 100, 200, 300, 400, 500
    for(int i = 1; i <= 5; i++) {
        queue.Enqueue(i * 100);
    }
    cout << endl;

    // ���� �� �� Ȯ��
    // 50, 60, 70, 80, 90, 100, 200, 300, 400, 500
    queue.PrintQueue();

    cin.ignore();
    cin.get();

    return 0;
}