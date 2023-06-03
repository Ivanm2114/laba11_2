#include <iostream>

using namespace std;

struct node {
    int info;
    node *right;
    node *left;
};

node *arr[200];
int len_arr = 0;

node *create_tree() {
    node *first = new node;
    first->left = nullptr;
    first->right = nullptr;
    int count;
    cout << "Enter info:\n";
    cin >> first->info;
    do {
        cout << "How many leafs:\n";
        cin >> count;
    } while (count >= 3 || count < 0);
    if (count == 1) {
        first->left = create_tree();
    }
    if (count == 2) {
        first->left = create_tree();
        first->right = create_tree();
    }
    return first;

}

void print_tree(node *tree) {
    if (tree) {
        cout << tree->info << '\n';
        print_tree(tree->left);
        print_tree(tree->right);
    }

}

bool in_arr(node *arr[200], node *el) {
    for (int i = 0; i < 200; i++) {
        if (arr[i] == el) return true;
    }
    return false;
}

int find_parents_with_odd_children(node *tree) {
    bool flag=false;
    if (tree) {
        if (tree->left && tree->left->info % 2) {
            flag = true;
        }
        if (tree->right && tree->right->info % 2) {
            flag = true;
        }
        if (flag && !in_arr(arr, tree)) {
            arr[len_arr++] = tree;
        }
        find_parents_with_odd_children(tree->left);
        find_parents_with_odd_children(tree->right);
    }
}


int main() {
    node *tree;
    tree = create_tree();
    cout << "\n\n";
    print_tree(tree);
    find_parents_with_odd_children(tree);
    if(len_arr){
    cout << "Parents with odd children:\n";
    for (int i = 0; i < len_arr; i++) {
        cout << arr[i]->info << " ";
    }}
    else{
        cout<<"No parents with odd children";
    }
    return 0;
}
