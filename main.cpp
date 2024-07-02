#include "tree.hpp"
#include "node.hpp"
#include "Complex.hpp"

#include <iostream>
#include <string>
#include <vector>
//#include <SFML/Graphics.hpp>
// #include <functional>

using namespace std;

int main(){

    //sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization"); // create window

    // // לולאת אירועים
    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    // }

    Tree<double> tree; // Binary tree that contains doubles.
    cout << endl;
    Node<double> root_node (1.1);
    Node<double> n1 (1.2);
    Node<double> n2 (1.3);
    Node<double> n3 (1.4);
    Node<double> n4 (1.5);
    Node<double> n5 (1.6);

    tree.add_root(root_node);
    cout << tree.add_sub_node(tree.get_root(), n1) << endl;
    cout << tree.add_sub_node(tree.get_root(), n2) << endl;
    cout << tree.add_sub_node(n1, n3) << endl;
    cout << tree.add_sub_node(n1, n4) << endl;
    cout << tree.add_sub_node(n1, n5) << endl; // This should fail (print - error operation) because n1 already has 2 children.
    cout << tree.add_sub_node(n2, n5) << endl; // this create n5, after a correct operation
    cout << endl;
    tree.draw();
    
    //cout << tree;
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-order traversal:" << endl;
    //Iterate over the tree in pre-order
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node).get_data() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "In-order traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "BFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    // for (auto node : tree)
    // {
    //     cout << node.get_value() << endl;
    // } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    // cout << endl;

    Tree<double,3> three_ary_tree; // 3-ary tree.
    Node<double> root_node1 (1.12);
    Node<double> s1 (1.22);
    Node<double> s2 (1.32);
    Node<double> s3 (1.42);
    Node<double> s4 (1.52);
    Node<double> s5 (1.62);
    cout << endl;
    three_ary_tree.add_root(root_node1);
    cout << three_ary_tree.add_sub_node(three_ary_tree.get_root(), s1) << endl;
    cout << three_ary_tree.add_sub_node(three_ary_tree.get_root(), s2) << endl;
    cout << three_ary_tree.add_sub_node(three_ary_tree.get_root(), s3) << endl;
    cout << three_ary_tree.add_sub_node(s1, s4) << endl;
    cout << three_ary_tree.add_sub_node(s2, s5) << endl;
    three_ary_tree.draw();
     // The tree should look like:
    /**
     *       root = 1.12
     *     /      |     \
     *    1.22    1.32    1.42
     *   /        |
     *  1.52      1.62
     */
    cout << "****************************************************************************************************" << endl;
    cout << "Pre-order traversal: (it behave like DFS)" << endl;
    for(auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.12 1.42 1.32 1.62 1.22 1.52
    
    cout << "Post-order traversal: (it behave like DFS)" << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        cout << (*node).get_data() << endl;
    } // prints: 1.12 1.42 1.32 1.62 1.22 1.52

    cout << "In-order traversal: (it behave like DFS)" << endl;
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        cout << (*node).get_data() << endl;
    } // prints: 1.12 1.42 1.32 1.62 1.22 1.52
    cout << "****************************************************************************************************" << endl;
    // Iterate over the tree in BFS
    cout << "BFS traversal:" << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node) {
        cout << (*node).get_data() << endl;
    }
    cout << endl;

    // Iterate over the tree in DFS
    cout << "DFS traversal:" << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        cout << (*node).get_data() << endl;
    }
    cout << endl;


    Tree<string> tree2; // Binary tree that contains doubles.
    cout << endl;
    Node<string> root_node2 ("yair");
    Node<string> d1 ("noam");
    Node<string> d2 ("shir");
    Node<string> d3 ("shira");
    Node<string> d4 ("bar");
    Node<string> d5 ("dor");

    tree2.add_root(root_node2);
    cout << tree2.add_sub_node(tree2.get_root(), d1) << endl;
    cout << tree2.add_sub_node(tree2.get_root(), d2) << endl;
    cout << tree2.add_sub_node(d1, d3) << endl;
    cout << tree2.add_sub_node(d1, d4) << endl;
    cout << tree2.add_sub_node(d1, d5) << endl; // This should fail (print - error operation) because n1 already has 2 children.
    cout << tree2.add_sub_node(d2, d5) << endl; // this create n5, after a correct operation
    tree2.draw();
    cout << endl;

    // The tree should look like:
    /**
     *       root = yair
     *     /        \
     *    noam       shir
     *   /  \        /
     *  shira  bar  dor
     */

    cout << "BFS traversal:" << endl;
    for (auto node = tree2.begin_bfs_scan(); node != tree2.end_bfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: yair, noam, shir, shira, bar, dor
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto node = tree2.begin_dfs_scan(); node != tree2.end_dfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: yair, noam, shira, bar, shir, dor

    Tree<int> tree3; // Binary tree that contains doubles.
    cout << endl;
    Node<int> root_node3 (1);
    Node<int> a1 (2);
    Node<int> a2 (3);
    Node<int> a3 (4);
    Node<int> a4 (5);
    Node<int> a5 (6);

    tree3.add_root(root_node3);
    cout << tree3.add_sub_node(tree3.get_root(), a1) << endl;
    cout << tree3.add_sub_node(tree3.get_root(), a2) << endl;
    cout << tree3.add_sub_node(a1, a3) << endl;
    cout << tree3.add_sub_node(a1, a4) << endl;
    cout << tree3.add_sub_node(a1, a5) << endl; // This should fail (print - error operation) because n1 already has 2 children.
    cout << tree3.add_sub_node(a2, a5) << endl; // this create n5, after a correct operation
    tree3.draw();
    cout << endl;

    // The tree should look like:
    /**
     *       root = 1
     *     /       \
     *     2        3
     *   /  \      /
     *  4    5    6
     */

    cout << "Pre-order traversal:" << endl;
    //Iterate over the tree in pre-order
    for (auto node = tree3.begin_pre_order(); node != tree3.end_pre_order(); ++node) {
        cout << (*node).get_data() << endl;
    } // prints: 1, 2, 4, 5, 3, 6
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto node = tree3.begin_post_order(); node != tree3.end_post_order(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 4, 5, 2, 6, 3, 1
    cout << endl;

    cout << "In-order traversal:" << endl;
    for (auto node = tree3.begin_in_order(); node != tree3.end_in_order(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 4, 2, 5, 1, 6, 3
    cout << endl;

    cout << "BFS traversal:" << endl;
    for (auto node = tree3.begin_bfs_scan(); node != tree3.end_bfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1, 2, 3, 4, 5, 6
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto node = tree3.begin_dfs_scan(); node != tree3.end_dfs_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1, 2, 4, 5, 3, 6
    cout << endl;

    Tree<double> tree4; // Binary tree that contains doubles.
    cout << endl;
    Node<double> root_node4 (1.9);
    Node<double> f1 (2.1);
    Node<double> f2 (1.7);
    Node<double> f3 (1.4);
    Node<double> f4 (1.8);
    Node<double> f5 (1.6);

    tree4.add_root(root_node4);
    cout << tree4.add_sub_node(tree4.get_root(), f1) << endl;
    cout << tree4.add_sub_node(tree4.get_root(), f2) << endl;
    cout << tree4.add_sub_node(f1, f3) << endl;
    cout << tree4.add_sub_node(f1, f4) << endl;
    cout << tree4.add_sub_node(f2, f5) << endl;
    tree4.draw();
    cout << endl;

    // The tree should look like:
    /**
     *       root = 1.9
     *     /       \
     *    2.1      1.7
     *   /  \      /
     *  1.4  1.8  1.6
     */

    cout << "Heap traversal:" << endl;
    for (auto node = tree4.begin_heap_scan(); node != tree4.end_heap_scan(); ++node)
    {
        cout << (*node).get_data() << endl;
    } // prints: 1.4, 1.6, 1.7, 1.8, 1.9, 2.1


    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);
    Complex c5(9, 10);
    Complex c6(11, 12);

    Tree<Complex> tree5; // Binary tree that contains doubles.
    cout << endl;
    Node<Complex> root_node5 (c1);
    Node<Complex> z1 (c2);
    Node<Complex> z2 (c3);
    Node<Complex> z3 (c4);
    Node<Complex> z4 (c5);
    Node<Complex> z5 (c6);

    tree5.add_root(root_node5);
    cout << tree5.add_sub_node(tree5.get_root(), z1) << endl;
    cout << tree5.add_sub_node(tree5.get_root(), z2) << endl;
    cout << tree5.add_sub_node(z1, z3) << endl;
    cout << tree5.add_sub_node(z1, z4) << endl;
    cout << tree5.add_sub_node(z2, z5) << endl;
    tree5.draw();
    cout << endl;

    // The tree should look like:
    /**
     *       root = 1+2i
     *     /         \
     *    3+4i       5+6i
     *   /  \        /
     * 7+8i  9+10i  11+12i
     */

    cout << "Pre-order traversal:" << endl;
    //Iterate over the tree in pre-order
    for (auto node = tree5.begin_pre_order(); node != tree5.end_pre_order(); ++node) {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 1+2i, 3+4i, 7+8i, 9+10i, 5+6i, 11+12i
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto node = tree5.begin_post_order(); node != tree5.end_post_order(); ++node)
    {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 7+8i, 9+10i, 3+4i, 11+12i, 5+6i, 1+2i
    cout << endl;

    cout << "In-order traversal:" << endl;
    for (auto node = tree5.begin_in_order(); node != tree5.end_in_order(); ++node)
    {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 7+8i, 3+4i, 9+10i, 1+2i, 11+12i, 5+6i
    cout << endl;

    cout << "BFS traversal:" << endl;
    for (auto node = tree5.begin_bfs_scan(); node != tree5.end_bfs_scan(); ++node)
    {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 1+2i, 3+4i, 5+6i, 7+8i, 9+10i, 11+12i
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto node = tree5.begin_dfs_scan(); node != tree5.end_dfs_scan(); ++node)
    {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 1+2i, 3+4i, 7+8i, 9+10i, 5+6i, 11+12i
    cout << endl;

    cout << "Heap traversal:" << endl;
    for (auto node = tree5.begin_heap_scan(); node != tree5.end_heap_scan(); ++node)
    {
        cout << (*node).get_data().to_string() << endl;
    } // prints: 11+12i, 9+10i, 7+8i, 5+6i, 3+4i, 1+2i

    return 0;
}
