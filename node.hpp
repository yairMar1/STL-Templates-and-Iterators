#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node {
private:
    T data;
    vector<Node<T>*> children;

public:
    Node(T data);
    ~Node();
    T get_data() const;
    void print_node() const;
    const vector<Node<T>*>& get_children() const;
    void add_child(Node<T>* child); // New method to add a child
};

template <typename T>
Node<T>::Node(T data) : data(data) {}

template <typename T>
Node<T>::~Node() {
    // for (Node<T>* child : children) {
    //     delete child;
    // }
}

template <typename T>
T Node<T>::get_data() const {
    return data;
}

template <typename T>
void Node<T>::print_node() const {
    cout << "Node data: " << data << endl;
}

template <typename T>
const vector<Node<T>*>& Node<T>::get_children() const {
    return children;
}

template <typename T>
void Node<T>::add_child(Node<T>* child) {
    children.push_back(child);
}

#endif // NODE_HPP
