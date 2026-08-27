class DynamicArray {
int m_capacity {0};
int* m_ptr{nullptr};
int m_size{};

public:

    DynamicArray(int capacity) :
    m_capacity{capacity},
    m_ptr{new int[capacity]}
    {
    }

    ~DynamicArray()
    {delete[] m_ptr;}

    int get(int i) {
    return m_ptr[i];
    }

    void set(int i, int n) {
    m_ptr[i] = n;
    }

    void pushback(int n) {
        if(m_size == m_capacity)
            resize();
    m_ptr[m_size] = n;
    ++m_size;
    }

    int popback() {
    return m_ptr[--m_size];
    }

    void resize() {

    m_capacity *= 2;
    int* temp{ new int[m_capacity] };

    for(int i{0}; i < m_size; i++)
        temp[i] = m_ptr[i];

    delete[] m_ptr;
    m_ptr = temp;
    }

    int getSize() const {
        return m_size;
    }

    int getCapacity() const {
        return m_capacity;
    }
};
