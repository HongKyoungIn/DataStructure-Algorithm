#include <iostream>

using namespace std;

#define MAX_SIZE 10

// Rear 위치에 삽입. 즉 다음에 삽입될 위치를 가리킨다.
// Front부터 삭제. 가장 먼저 데이터가 들어온 위치를 가리킨다.
// Front 와 Rear가 같아지면 큐가 비어있다고 간주한다.
template <typename T>
class Queue {
private:
    int rear; // 다음에 저장될 큐의 위치
    int front; // 가장 먼저 들어온 데이터의 위치
    bool empty = true; // 큐가 비어있는지 확인하기 위한 변수
    int Array[MAX_SIZE] = {'\0',}; // 큐 선언

public:
    Queue() { // 생성자 선언
        rear = 0; // 큐의 위치 초기화
        front = 0; // 큐의 위치 초기화
    }
    ~Queue() {

    }

    void Enqueue(T inputdata) { // 큐에 데이터를 넣기 위한 함수
        if(IsFull() == true) { // 만약 가득 차있다면
            cout << "큐가 꽉 차 있습니다." << endl;
            cout << "비우고 시도해주세요." << endl;
        }
        else { // 큐에 공간이 비어있다면
            cout << inputdata << "를 넣습니다." << endl;
            Array[rear] = inputdata; // 현재 rear 위치에 데이터를 넣는다.
            rear = (rear + 1) % MAX_SIZE; // rear가 가리키는 위치를 1 증가시킨다.
            empty = false; // 큐에 데이터가 있으므로 empty 변수를 false로 변경한다.
        }
    }

    void Dequeue() { // 큐에 데이터를 삭제하기 위한 함수
        if(empty == false) { // 만약 큐가 비어있지 않다면 동작합니다.
            cout << Array[front] << "를 뺍니다." << endl;
            front = (front + 1) % MAX_SIZE; // front값을 다음 값으로 변경한다.
            if(front == rear) { // 만약 Dequeue를 실행한 후 front가 가리키는 값이 rear와 같다면 큐가 비어있다는 뜻이 된다.
                empty == true; // empty 변수를 true로 변경.
            }
        }
        else {
            cout << "큐가 비어있습니다." << endl;
        }
    }

    int Size() { // 큐의 사이즈를 알려주는 함수
        if(abs(rear - front) == 0 && empty == false) { // 만약 front와 rear가 가리키는 위치가 같지만 비어있지 않다면
            return MAX_SIZE; // 큐가 가득 찼다는 뜻이므로 MAX_SIZE를 반환한다.
        }
        else { // 가리키는 위치가 다르다면
            return abs(rear - front); // 큐의 크기를 반환
        }
    }

    bool IsFull() { // 큐가 가득 찼는지 확인하기 위한 함수
        if(Size() == MAX_SIZE) { // 만약 Size() 함수를 실행했을 때 MAX_SIZE를 반환한다면
            return true; // 가득 차있으므로 true
        }
        else { // 그 외의 경우엔 false
            return false;
        }
    }
    
    void PrintQueue() { // 큐에 저장된 값을 출력하기 위한 함수
        cout << "현재 큐에 저장되어 있는 값 : ";
        int temp = front; // 현재 front 위치를 임시로 저장하기 위한 변수
        if(Size() == MAX_SIZE) { // 만약 큐에 데이터가 가득 차있다면
            cout << Array[temp % MAX_SIZE] << " "; // 현재 front값을 먼저 1개 출력한다.
            temp++; // 다음 front값을 가리키도록 temp 값을 증가시킨다.
            for(temp; temp % MAX_SIZE != rear % MAX_SIZE; temp++) { // temp의 값이 rear가 가리키고 있는 위치전까지 반복한다.
                cout << Array[temp % MAX_SIZE] << " "; // rear가 가리키는 값 전까지 반복하여 출력한다.
            }
        }
        else { // 큐가 가득찬 상태가 아니라면
            while(temp % MAX_SIZE != rear % MAX_SIZE) { // front부터 rear가 가리키는 값까지 출력한다.
                cout << Array[temp % MAX_SIZE] << " "; 
                temp++;
            }
        }
        cout << endl;
    }
};

int main(void) {
    Queue<int> queue;

    // 크기가 10인 큐에 15개의 데이터를 넣는다.
    // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140
    for(int i = 0; i < 15; i++) {
        queue.Enqueue(i * 10);
        cout << "큐의 사이즈 : " << queue.Size() << endl;
        cout << endl;
    }

    // 현재 들어간 값 확인
    // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90
    queue.PrintQueue();
    cout << endl;

    // 5개의 큐를 지운다.
    for(int i = 0; i < 5; i++) {
        queue.Dequeue();
    }
    cout << endl;

    // 현재 들어간 값 확인
    // 50, 60, 70, 80, 90
    queue.PrintQueue();
    cout << endl;

    // 5개의 데이터를 넣는다.
    // 100, 200, 300, 400, 500
    for(int i = 1; i <= 5; i++) {
        queue.Enqueue(i * 100);
    }
    cout << endl;

    // 현재 들어간 값 확인
    // 50, 60, 70, 80, 90, 100, 200, 300, 400, 500
    queue.PrintQueue();

    cin.ignore();
    cin.get();

    return 0;
}