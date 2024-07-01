#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;

TEST_CASE("INORDER")
{
    Tree<int> tree;
    Node<int> c1 (1);
    Node<int> c2 (2);
    Node<int> c3 (3);
    Node<int> c4 (4);
    Node<int> c5 (5);
    Node<int> c6 (6);
    Node<int> c7 (7);
    Node<int> c8 (8);
    Node<int> c9 (9);
    Node<int> c10 (10);

    tree.add_root(c1);
    // Test adding root when there's already a root
    CHECK(tree.add_root(c2,1) == " There is already a root");

    tree.add_sub_node(tree.get_root(), c2);
    tree.add_sub_node(tree.get_root(), c3);
    // Test adding more than the definated number of children to a node
    CHECK(tree.add_sub_node(tree.get_root(), c4) == " you can't add node");

    tree.add_sub_node(c2, c4);
    tree.add_sub_node(c2, c5);
    tree.add_sub_node(c3, c6);
    tree.add_sub_node(c3, c7);
    tree.add_sub_node(c4, c8);
    tree.add_sub_node(c5, c9);
    tree.add_sub_node(c5, c10);
    // Test inorder traversal
    vector<int> expected_in_order = {8, 4, 2, 9, 5, 10, 1, 6, 3, 7};
    auto it = tree.begin_in_order();
    for (int val : expected_in_order) {
        CHECK((*it).get_data() == val);
        ++it;
    }
}

TEST_CASE("POSTORDER") {
    Tree<int> tree;
    Node<int> c1 (1);
    Node<int> c2 (2);
    Node<int> c3 (3);
    Node<int> c4 (4);
    Node<int> c5 (5);
    Node<int> c6 (6);
    Node<int> c7 (7);
    Node<int> c8 (8);
    Node<int> c9 (9);
    Node<int> c10 (10);

    tree.add_root(c1);
    tree.add_sub_node(tree.get_root(), c2);
    tree.add_sub_node(tree.get_root(), c3);
    tree.add_sub_node(c2, c4);
    tree.add_sub_node(c2, c5);
    tree.add_sub_node(c3, c6);
    tree.add_sub_node(c3, c7);
    tree.add_sub_node(c4, c8);
    tree.add_sub_node(c5, c9);
    tree.add_sub_node(c5, c10);
    // Test postorder traversal
    vector<int> expected_post_order = {8, 4, 9, 10, 5, 2, 6, 7, 3, 1};
    auto it = tree.begin_post_order();
    for (int val : expected_post_order) {
        CHECK((*it).get_data() == val);
        ++it;
    }
}

TEST_CASE("PREORDER") {
    Tree<int> tree;
    Node<int> c1 (1);
    Node<int> c2 (2);
    Node<int> c3 (3);
    Node<int> c4 (4);
    Node<int> c5 (5);
    Node<int> c6 (6);
    Node<int> c7 (7);
    Node<int> c8 (8);
    Node<int> c9 (9);
    Node<int> c10 (10);

    tree.add_root(c1);
    tree.add_sub_node(tree.get_root(), c2);
    tree.add_sub_node(tree.get_root(), c3);
    tree.add_sub_node(c2, c4);
    tree.add_sub_node(c2, c5);
    tree.add_sub_node(c3, c6);
    tree.add_sub_node(c3, c7);
    tree.add_sub_node(c4, c8);
    tree.add_sub_node(c5, c9);
    tree.add_sub_node(c5, c10);
    // Test preorder traversal
    vector<int> expected_pre_order = {1, 2, 4, 8, 5, 9, 10, 3, 6, 7};
    auto it = tree.begin_pre_order();
    for (int val : expected_pre_order) {
        CHECK((*it).get_data() == val);
        ++it;
    }
}

TEST_CASE("EDGE_CASES") {
    Tree<int> tree;
    Node<int> c1 (1);
    Node<int> c2 (2);

    // Test adding root to node ,when there's already a root for the tree
    tree.add_root(c1);
    CHECK(tree.add_root(c2, 1) == " There is already a root");

    // Test adding more than two children to a node
    Node<int> c3 (3);
    Node<int> c4 (4);
    Node<int> c5 (5);
    tree.add_sub_node(c1, c3);
    tree.add_sub_node(c1, c4);
    CHECK(tree.add_sub_node(c1, c5) == " you can't add node");

    // Test traversal on empty tree
    Tree<int> empty_tree;
    CHECK(empty_tree.begin_in_order() == empty_tree.end_in_order());
    CHECK(empty_tree.begin_post_order() == empty_tree.end_post_order());
    CHECK(empty_tree.begin_pre_order() == empty_tree.end_pre_order());
}

TEST_CASE("COMPLEX_NUMBERS") {
    Tree<Complex> tree;
    Node<Complex> c1 (Complex(1, 2));
    Node<Complex> c2 (Complex(3, 4));
    Node<Complex> c3 (Complex(5, 6));
    Node<Complex> c4 (Complex(7, 8));
    Node<Complex> c5 (Complex(9, 10));
    Node<Complex> c6 (Complex(11, 12));

    tree.add_root(c1);
    tree.add_sub_node(tree.get_root(), c2);
    tree.add_sub_node(tree.get_root(), c3);
    tree.add_sub_node(c2, c4);
    tree.add_sub_node(c2, c5);
    tree.add_sub_node(c3, c6);
    // Test preorder traversal
    vector<Complex> expected_pre_order = {Complex(1, 2), Complex(3, 4), Complex(7, 8), Complex(9, 10), Complex(5, 6), Complex(11, 12)};
    auto it = tree.begin_pre_order();
    for (const Complex& val : expected_pre_order) {
        CHECK((*it).get_data() == val);
        ++it;
    }

}