#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
    } else {
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(topElement);
    }
}

void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(28);
    st.push(29);
    st.push(30);
    st.push(31);

    cout << "Original Stack: ";
    printStack(st);

    st.push(28);
    st.push(29);
    st.push(30);
    st.push(31);

    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
