#include<iostream>

class KStack{
    public:
        int* arr;
        int* top;
        int* next;
        int freeSpot;

        KStack(int size, int k) {
            arr = new int[size];
            next = new int[size];
            top = new int[k];
            freeSpot = 0;

            for(int i = 0; i < k; i++) top[i] = -1;

            for(int i = 0; i < size; i++) {
                next[i] = i + 1;
            }
            next[size - 1] = -1;
        }

        void push(int data, int st);

        int pop(int st);
};

void KStack::push(int data, int st) {
    // overflow condition
    if(freeSpot == -1) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    // find index to push
    int index = freeSpot;

    // update freeSpot
    freeSpot = next[index];

    // update next[index]
    next[index] = top[st - 1];

    // update top
    top[st - 1] = index;

    // assign the data
    arr[index] = data;
}

int KStack::pop(int st) {
    // underflow condition
    if(top[st - 1] == -1) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    }

    // find index to be popped
    int index = top[st - 1];

    // update top
    top[st - 1] = next[index];

    // now next[index] is a freeSpot
    next[index] = freeSpot;

    // move freeSpot to poping index
    freeSpot = index;

    return arr[index];
}

int main() {
    KStack st(5, 3);

    st.push(10, 1);
    st.push(20, 2);
    st.push(30, 3);
    st.push(40, 2);
    st.push(60, 3);

    // st.push(20, 1);

    st.pop(1);
    // st.pop(1);

    st.pop(2);
    st.pop(2);
    st.pop(3);
    st.pop(3);

    std::cout << st.freeSpot << std::endl;

    st.push(10, 1);
    st.push(20, 2);
    st.push(30, 3);
    st.push(40, 2);
    std::cout << st.freeSpot << std::endl;
    
    st.push(60, 3);

    std::cout << st.freeSpot << std::endl;

    return 0;
}