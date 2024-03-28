#include <iostream>

using namespace std;

struct Node {
    int znach;
    Node* next;
    Node(int _znach) : znach(_znach), next(nullptr) {}
};

struct Stack {
    Node* first;

    Stack() : first(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push(int n) {
        Node* t = new Node(n);
        t->next = first;
        first = t;
    }

    int top() {
        if (is_empty()) {
            return -1;
        }
        return first->znach;
    }

    void pop() {
        if (is_empty()) {
            return;
        }
        Node* d = first;
        first = d->next;
        delete d;
    }
};

int main(int argc, char* argv[]) {
    Stack st;
    string s;
    if (argc > 1) {
        s = argv[1];
    }
    else {
        s = "true";
    }
    if (s == "true") {
        cout << "Input:" << '\n';
    }
    int n, i = 1;
    while (true) {
        if (s == "true") {
            cout << 'a' << i << " =";
        }
        cin >> n;
        if (n == 0) {
            break;
        }
        st.push(n);
        i += 1;
    }
    int ans = 1;
    if (s == "true") {
        cout << "Output:" << '\n';
    }
    for (int j = i - 2; j >= 0; j--) {
        int value = st.top();
        st.pop();
        if (value > 0) {
            if (s == "true") {
                cout << 'n' << ans << " = ";
            }
            cout << value << '\n';
            ans += 1;
        }
    }
    return 0;
}
    