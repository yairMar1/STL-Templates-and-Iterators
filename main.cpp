#include "tree.hpp"
#include "node.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Tree<double,3> three_ary_tree; // 3-ary tree.
    Tree<double> tree; // Binary tree that contains doubles.
    cout << endl;
    Node<double> root_node (1.1);
    Node<double> n1 (1.2);
    Node<double> n2 (1.3);
    Node<double> n3 (1.4);
    Node<double> n4 (1.5);
    Node<double> n5 (1.6);
    cout << endl;

    tree.add_root(root_node);
    cout << tree.add_sub_node(root_node, n1) << endl;
    cout << tree.add_sub_node(root_node, n2) << endl;
    cout << tree.add_sub_node(n1, n3) << endl;
    cout << tree.add_sub_node(n1, n4) << endl;
    cout << tree.add_sub_node(n1, n5) << endl; // This should fail (print - error operation) because n1 already has 2 children.
    cout << tree.add_sub_node(n2, n5) << endl; // this create n5, after a correct operation

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    // three_ary_tree.add_root(root_node);
    // three_ary_tree.add_sub_node(root_node, n1);
    // three_ary_tree.add_sub_node(root_node, n2);
    // three_ary_tree.add_sub_node(root_node, n3);
    // three_ary_tree.add_sub_node(n1, n4);
    // three_ary_tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << endl;
    
    cout << "The tree is: \n";
    //three_ary_tree.print(root_node);
    tree.print(root_node);
    cout << endl;

    return 0;
}