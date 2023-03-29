#include <iostream>
#include <cstdlib>

template <typename T>
class Node {
public:
    Node() : next(nullptr), prev(nullptr) {}
    Node(const T& v) : val(v), next(nullptr), prev(nullptr) {}

    T val;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {
        while (head != nullptr) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }

    void push_back(const T& v) {
        Node<T>* new_node = new Node<T>(v);
        if (tail != nullptr) {
            tail->next = new_node;
            new_node->prev = tail;
        }
        tail = new_node;
        if (head == nullptr) {
            head = tail;
        }
        ++size;
    }

    void push_front(const T& v) {
        Node<T>* new_node = new Node<T>(v);
        if (head != nullptr) {
            head->prev = new_node;
            new_node->next = head;
        }
        head = new_node;
        if (tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    void pop_back() {
        if (tail == nullptr) {
            return;
        }
        Node<T>* tmp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete tmp;
        --size;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node<T>* tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete tmp;
        --size;
    }

    bool empty() const {
        return size == 0;
    }

    size_t length() const {
        return size;
    }

    void print() const {
        Node<T>* curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};

int main() {
    List<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_front(4);
    my_list.pop_back();
    my_list.pop_front();
    std::cout << "List size: " << my_list.length() << std::endl;
    my_list.print();
    return 0;
}
