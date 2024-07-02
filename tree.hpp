#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
#include <queue>
#include <type_traits>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

template <typename T, int maxChildren = 2>
class Tree {
    private:
        Node<T>* root;

    public:

        class IteratorPreOrder;
        class IteratorPostOrder;
        class IteratorInOrder;
        class IteratorBFS;
        class IteratorDFS;
        class IteratorHeap;

    Tree() : root(nullptr) {
        cout << "Tree created with max children: " << maxChildren << endl;
        cout << "Type: " << typeid(T).name() << "\n";
    }
    // In fact, you don't need to do new at all, but if I did anyway (in this assignment I only did it for the root) then we will have to destruct it
    ~Tree() {
        //delete_node(root);
        delete root;
    }

    void add_root(Node<T>& root_node) {
        if (root == nullptr) {
            root = new Node<T>(root_node.get_data());
        //     cout << "Root added, its value is: " << root_node.get_data() << endl;
        // } else {
        //     cout << "Root already exists" << endl;
        }
    }

    string add_root(Node<T>& root_node, size_t n) {
        if (root == nullptr) {
            root = new Node<T>(root_node.get_data());
            string res = " Root added";
            return res;
        } else {
            string res = " There is already a root";
            return res;
        }
    }

    string add_sub_node(Node<T>& parent, Node<T>& child_node) {
        if (root == nullptr) {
            throw invalid_argument("Root is not set");
        }
        string res = " you can't add node";
        
        // auto childData = child_node.get_data();
        // auto parentData = parent.get_data();

        if (parent.get_children().size() < maxChildren) {
            parent.add_child(&child_node);
            res = " you add node";
            }
        // if constexpr (is_same_v<T,string>) { // if T is string
        //     if (parent.get_children().size() < maxChildren) {
        //         parent.add_child(&child_node);
        //         res = "Added a new child with value: " + childData + " to parent with value: " + parentData;
        //     } else {
        //         res = "No available child slot found for parent with value: " + parentData;
        //     }
        // } else { // if T is not string
        //     if (parent.get_children().size() < maxChildren) {
        //         parent.add_child(&child_node);
        //         res = "Added a new child with value: " + to_string(childData) + " to parent with value: " + to_string(parentData);
        //     } else {
        //         res = "No available child slot found for parent with value: " + to_string(parentData);
        //     }
        // }
        return res;
    }

    Node<T>& get_root() const{
        if (root == nullptr) {
            throw invalid_argument("Root is not set.");
        }
        return *root;
    }

    // void delete_node(Node<T>* node) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     for(auto child : node->get_children()) {
    //         delete_node(child);
    //     }
    //     delete node;
    // }

    IteratorPreOrder begin_pre_order(){return IteratorPreOrder(root);}
    IteratorPreOrder end_pre_order() {return IteratorPreOrder(nullptr);}

    IteratorPostOrder begin_post_order(){return IteratorPostOrder(root);}
    IteratorPostOrder end_post_order() {return IteratorPostOrder(nullptr);}

    IteratorInOrder begin_in_order(){return IteratorInOrder(root);}
    IteratorInOrder end_in_order() {return IteratorInOrder(nullptr);}

    IteratorBFS begin_bfs_scan(){return IteratorBFS(root);}
    IteratorBFS end_bfs_scan() {return IteratorBFS(nullptr);}

    IteratorDFS begin_dfs_scan(){return IteratorDFS(root);}
    IteratorDFS end_dfs_scan() {return IteratorDFS(nullptr);}

    IteratorHeap begin_heap_scan() {return IteratorHeap(root, this);}
    IteratorHeap end_heap_scan() {return IteratorHeap(nullptr, nullptr);}
    
//*******************************************************************  pre - order iterator *************************************************************/
class IteratorPreOrder {
private:
    stack<Node<T>*> nodesStack;
    Node<T>* current;

public:
    IteratorPreOrder(Node<T> *root) : current(root) {
        if(root != nullptr) {
            nodesStack.push(root);
            //++(*this);
        }
    }

    IteratorPreOrder& operator++() {
        if(maxChildren > 2){
            if (!nodesStack.empty()) {
            current = nodesStack.top();
            nodesStack.pop();
            const auto& children = current->get_children();
            for (const auto& child : children) {
                if (child != nullptr) {
                    nodesStack.push(child);
                }
            }
        } else {
            current = nullptr;
        }
        return *this;
        }
        else if(!nodesStack.empty()) {
            current = nodesStack.top();
            nodesStack.pop();
            const auto& children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                if (*it != nullptr) {
                    nodesStack.push(*it);
                }
            }
            if (!nodesStack.empty()) {
                current = nodesStack.top();
            } else {
                current = nullptr;
            }
        } else {
            current = nullptr;
        }
        return *this;
    }

    bool operator!=(const IteratorPreOrder& other) const {
        return current != other.current;
    }

    bool operator==(const IteratorPreOrder& other) const {
        return current == other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }
};
//*******************************************************************  post - order iterator *************************************************************/
class IteratorPostOrder {
private:
    stack<pair<Node<T>*, bool>> nodesStack;
    Node<T>* current;

public:
    IteratorPostOrder(Node<T> *root) : current(nullptr) {
        if(root != nullptr) {
            nodesStack.push({root, false});
            ++(*this);
        }
    }

    IteratorPostOrder& operator++() {
    if (maxChildren > 2) {
        if (!nodesStack.empty()) {
            current = nodesStack.top().first;
            nodesStack.pop();
            const auto& children = current->get_children();
            for (const auto& child : children) {
                if (child != nullptr) {
                    nodesStack.push({child, false}); // Pushing {child, visited=false}
                }
            }
        } else {
            current = nullptr;
        }
        return *this;
    } else {
        // Case for up to 2 children per node
        while (!nodesStack.empty()) {
            auto [node, visited] = nodesStack.top();
            nodesStack.pop();

            if (visited) {
                current = node;
                return *this;
            }

            nodesStack.push({node, true}); // Mark node as visited
            const auto& children = node->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                if (*it != nullptr) {
                    nodesStack.push({*it, false}); // Push children with visited=false
                }
            }
        }
        current = nullptr; // No more nodes to process
        return *this;
    }
}


    bool operator!=(const IteratorPostOrder& other) const {
        return current != other.current;
    }

    bool operator==(const IteratorPostOrder& other) const {
        return current == other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }
};
//******************************************************************* in - order iterator *************************************************************/
class IteratorInOrder {
private:
    stack<Node<T>*> nodesStack;
    Node<T>* current;
public:
IteratorInOrder(Node<T> *root) : current(root) {
        if(maxChildren > 2){
            if(root != nullptr){
                nodesStack.push(root);
                ++(*this);
            }
        }
        else{
            while (current != nullptr) {
                nodesStack.push(current);
                current = current->get_children().empty() ? nullptr : current->get_children()[0];
            }
            if (!nodesStack.empty()) {
                current = nodesStack.top();
            }
        }
    }

    IteratorInOrder& operator++() {
        if(maxChildren > 2){
            if (!nodesStack.empty()) {
            current = nodesStack.top();
            nodesStack.pop();
            const auto& children = current->get_children();
            for (const auto& child : children) {
                if (child != nullptr) {
                    nodesStack.push(child);
                }
            }
        } else {
            current = nullptr;
        }
        return *this;
        }
        else{
        if (!nodesStack.empty()) {
            Node<T>* node = nodesStack.top();
            nodesStack.pop();
            current = node;

            if (!node->get_children().empty() && node->get_children().size() > 1) {
                node = node->get_children()[1];
                while (node != nullptr) {
                    nodesStack.push(node);
                    node = node->get_children().empty() ? nullptr : node->get_children()[0];
                }
            }

            if (!nodesStack.empty()) {
                current = nodesStack.top();
            } else {
                current = nullptr;
            }
        } else {
            current = nullptr;
        }
        return *this;
        }
    }

    bool operator!=(const IteratorInOrder& other) const {
        return current != other.current;
    }

    bool operator==(const IteratorInOrder& other) const {
        return current == other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }
};
//******************************************************************* bfs iterator *************************************************************/
class IteratorBFS {
private:
    queue<Node<T>*> nodesQueue;
    Node<T>* current;

public:
    IteratorBFS(Node<T> *root) : current(nullptr) {
        if (root != nullptr) {
            nodesQueue.push(root);
            this->operator++();  // Move to the first node
        }
    }

    IteratorBFS& operator++() {
        if (!nodesQueue.empty()) {
            current = nodesQueue.front();
            nodesQueue.pop();
            const auto& children = current->get_children();
            for (const auto& child : children) {
                if (child != nullptr) {
                    nodesQueue.push(child);
                }
            }
        } else {
            current = nullptr;
        }
        return *this;
    }

    bool operator!=(const IteratorBFS& other) const {
        return current != other.current;
    }

    bool operator==(const IteratorBFS& other) const {
        return current == other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }
};
//******************************************************************* dfs iterator *************************************************************/
class IteratorDFS {
private:
    stack<Node<T>*> nodesStack;
    Node<T>* current;
public:
    IteratorDFS(Node<T> *root) : current(root) {
        if (root != nullptr) {
            nodesStack.push(root);
            this->operator++();  // Move to the first node
        }
    }

    IteratorDFS& operator++() {
        if (!nodesStack.empty()) {
            current = nodesStack.top();
            nodesStack.pop();
            const auto& children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                if (*it != nullptr) {
                    nodesStack.push(*it);
                }
            }
        } else {
            current = nullptr;
        }
        return *this;
    }

    bool operator!=(const IteratorDFS& other) const {
        return current != other.current;
    }

    bool operator==(const IteratorDFS& other) const {
        return current == other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }
};
//******************************************************************* Heap iterator *************************************************************/
class IteratorHeap {
    private:
        vector<Node<T>*> nodesHeap;
        Node<T>* current;
        bool hasStarted = false;
    public:
        IteratorHeap(Node<T> *root, Tree<T>* tree) : current(nullptr) {
            if (root != nullptr) {
                for (auto node = tree->begin_bfs_scan(); node != tree->end_bfs_scan(); ++node) {
                    nodesHeap.push_back(&(*node));
                }
                make_heap(nodesHeap.begin(), nodesHeap.end(), [](Node<T>* a, Node<T>* b) { return a->get_data() > b->get_data(); }); // if we change the sign to < we will have a max heap (and at line 438)
                this->operator++();  // Move to the first node
            }
        }

    IteratorHeap& operator++() {
        if (!nodesHeap.empty()) {
            pop_heap(nodesHeap.begin(), nodesHeap.end(), [](Node<T>* a, Node<T>* b) { return a->get_data() > b->get_data(); });// Pop the minimum element (root of the heap)
            current = nodesHeap.back(); // Set current to the minimum element
            nodesHeap.pop_back(); // Remove the minimum element from the heap
        } else {
            current = nullptr;
        }
        return *this;
    }


        bool operator!=(const IteratorHeap& other) const {
            return current != other.current;
        }

        bool operator==(const IteratorHeap& other) const {
            return current == other.current;
        }

        Node<T>* operator->() const {
            return current;
        }

        Node<T>& operator*() const {
            return *current;
        }
    };
//*******************************************************************  GUI *************************************************************/
    void drawNode(sf::RenderWindow& window, Node<T>* node, sf::Vector2f position, float xOffset, float yOffset, const sf::Font& font) {
        if (node == nullptr) return;

        // Defining the circle
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(position);
        window.draw(circle);

        // Defining the text
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Red);

        if constexpr (is_same_v<T, string>) { // if T is string
            text.setString(node->get_data());
        } else {
            ostringstream oss;
            oss << node->get_data();
            text.setString(oss.str()); // if T is not string
        }

        // Center the text within the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());

        window.draw(text);

        float childXOffset = xOffset / max(1, static_cast<int>(node->get_children().size()));
        float childYOffset = yOffset;

        for (size_t i = 0; i < node->get_children().size(); ++i) {
            sf::Vector2f childPosition(position.x + (i - (node->get_children().size() - 1) / 2.0f) * childXOffset, position.y + childYOffset);

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(position.x + 20, position.y + 20)),
                sf::Vertex(sf::Vector2f(childPosition.x + 20, childPosition.y + 20))
            };
            window.draw(line, 2, sf::Lines);

            drawNode(window, node->get_children()[i], childPosition, childXOffset, childYOffset, font);
        }
    }

    void draw() {
        sf::RenderWindow window(sf::VideoMode(700, 500), "Tree Visualization");

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            cerr << "Failed to load font!" << endl;
            return;
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            drawNode(window, root, sf::Vector2f(330, 100), 200, 100, font);
            window.display();
        }
    }

};
#endif // TREE_HPP