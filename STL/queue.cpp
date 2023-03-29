template<typename T>
class QueueUsingArray {
public:
    QueueUsingArray() : head(0), tail(0), size(0) {}
    void push(const T& data) {
        if (size == MAX_SIZE) return;
        q[tail] = data;
        tail = (tail + 1) % MAX_SIZE;
        size++;
    }
    void pop() {
        if (size == 0) return;
        head = (head + 1) % MAX_SIZE;
        size--;
    }
    T front() {
        return q[head];
    }
    bool empty() const {
        return size == 0;
    }
    size_t getSize() const {
        return size;
    }
private:
    static constexpr int MAX_SIZE = 1000;
    T q[MAX_SIZE];
    int head, tail, size;
};
