#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

using namespace std;

template <typename T, int maxChildren = 2>
class Tree {
    private:
        Node<T>* root;
    public:
        Tree();
        ~Tree();

        //***** opetetion on tree */
        void add_root(Node<T>& root_node);
        string add_sub_node(Node<T>& parent, Node<T>& child_node);

        //***** tree traversal */
        vector<Node<T>*> pre_order(Node<T>* node);
        size_t begin_pre_order();
        size_t end_pre_order();

        vector<Node<T>*> post_order(Node<T>* node);
        size_t begin_post_order();
        size_t end_post_order();

        vector<Node<T>*> in_order(Node<T>* node);
        size_t begin_in_order();
        size_t end_in_order();

        void begin_bfs_scan();
        void end_bfs_scan();

        //***** informetion on tree */
        bool find(Node<T>* node, T data) const;
        void print(const Node<T>& node) const;
        Node<T>& get_root() const;
        void delete_node(Node<T>* node);
};

template <typename T, int maxChildren>
Tree<T, maxChildren>::Tree() : root(nullptr) {
    cout << "Tree created with max children: " << maxChildren << endl;
    cout << "Type: " << typeid(T).name() << "\n";
}

template <typename T, int maxChildren>
Tree<T, maxChildren>::~Tree() {
    delete_node(root);
}

template <typename T, int maxChildren>
void Tree<T, maxChildren>::add_root(Node<T>& root_node) {
    if (root == nullptr) {
        root = new Node<T>(root_node.get_data());
        cout << "Root added, its value is: " << root_node.get_data() << endl;
    } else {
        cout << "Root already exists" << endl;
    }
}

template <typename T, int maxChildren>
string Tree<T, maxChildren>::add_sub_node(Node<T>& parent, Node<T>& child_node) {
    string res;
    if (parent.get_children().size() < maxChildren) {
        parent.add_child(&child_node);
        res = "Added a new child with value: " + to_string(child_node.get_data()) + " to parent with value: " + to_string(parent.get_data());
    } else {
        res = "No available child slot found for parent with value: " + to_string(parent.get_data());
    }
    //cout << res << endl;
    return res;
}

template <typename T, int maxChildren>
bool Tree<T, maxChildren>::find(Node<T>* node, T data) const{
    if (node == nullptr) {
        return false;
    }
    if (node->get_data() == data) {
        return true;
    }
    for (Node<T>* child : node->get_children()) {
        if (find(child, data)) {
            return true;
        }
    }
    return false;
}

template <typename T, int maxChildren>
void Tree<T, maxChildren>::print(const Node<T>& node) const {
    node.print_node(); // Print the node.
    for (const Node<T>* child : node.get_children()) { // Print the children.
        print(*child);
    }
}

template <typename T, int maxChildren>
Node<T>& Tree<T, maxChildren>::get_root() const{
    if (root == nullptr) {
        throw invalid_argument("Root is not set.");
    }
    return *root;
}

template <typename T, int maxChildren>
void Tree<T, maxChildren>::delete_node(Node<T>* node) {
    if (node != nullptr) {
        for (Node<T>* child : node->get_children()) {
            delete_node(child);
        }
        delete node;
    }
}

#endif // TREE_HPP
