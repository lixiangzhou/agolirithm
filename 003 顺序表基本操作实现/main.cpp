#include<iostream>
using namespace std;

template <class E>
class ArrayList {
private:
    int m_length;
    int m_capacity;
    int* m_list;
    void checkAdd(int idx);
    void check(int idx);
public:
    ArrayList(int capacity);
    ~ArrayList();
    void insert(int idx, E value);
    void append(E value);
    void update(int idx, E value);
    E get(int idx);
    void remove(int idx);
    void traverse();
    
};

template <class E>
ArrayList<E>::ArrayList(int capacity) :m_capacity(capacity) {
    if (capacity <= 0) {
        throw "长度必须大于0";
    }
    m_list = new int[capacity]();
}

template <class E>
ArrayList<E>::~ArrayList() {
    delete[] m_list;
}

template <class E>
void ArrayList<E>::insert(int idx, E value) {
    checkAdd(idx);
    
    for (int i = m_length - 1; i >= idx; i--) {
        m_list[i + 1] = m_list[i];
    }
    
    m_list[idx] = value;
    ++m_length;
}
    
template <class E>
void ArrayList<E>::append(E value) {
    insert(m_length, value);
}

template <class E>
E ArrayList<E>::get(int idx) {
    check(idx);
    return m_list[idx];
}

template <class E>
void ArrayList<E>::remove(int idx) {
    check(idx);
    for (int i = idx; i < m_length - 1; i++) {
        m_list[i] = m_list[i + 1];
    }
    --m_length;
}



template <class E>
void ArrayList<E>::update(int idx, E value) {
    check(idx);
    m_list[idx] = value;
}

template <class E>
void ArrayList<E>::checkAdd(int idx) {
    if (idx < 0 || idx > m_length) {
        throw "索引越界";
    }
    
    if (m_capacity == m_length) {
        throw "容量已满";
    }
}
    
template <class E>
void ArrayList<E>::check(int idx) {
    if (idx < 0 || idx >= m_length) {
        throw "索引越界";
    }
}

template <class E>
void ArrayList<E>::traverse() {
    for (int i = 0; i < m_length; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << m_list[i];
    }
    cout << endl;
}


int main(){
    ArrayList<int> *array = new ArrayList<int>(20);
    
    array->insert(0, 3);
    array->insert(1, 4);
    array->append(34);
    array->append(45);
    array->insert(2, 12);
    
    array->traverse();
    
    array->update(2, 222);
    array->traverse();
    
    cout << array->get(2) << endl;
    
    array->remove(2);
    array->traverse();
    
    delete array;
    
    cout << endl;
    return 0;
}
