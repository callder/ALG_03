#include <iostream>
#include <chrono>

using namespace std;
template <class T>
class Node{
public:
    Node* parent;
    Node* child_left;
    Node* child_right;

    int data;
    int id;

    Node(){
        parent = nullptr;
        child_left = nullptr;
        child_right = nullptr;

        data = 0;
    }


};
template <class T>
class BST{
public:
    Node<T>* root;
    int size;
    int id = 0;
    int height = 0;

    BST(){
        root = nullptr;
        size = 0;
    }
    ~BST() {
        del_nodes(root);
    }

    void addNode(int s){
        if(size == 0){
            root = new Node<T>;
            root->data = s;
            root->id = id;
            root->parent = nullptr;
            size++;
            id++;
            return;
        }
        Node<T>* temp = root;

        zaloopAdd(temp, s);

    }
    void zaloopAdd(Node<T>* current, int s){
        if(current->data > s && current->child_left != nullptr){
            zaloopAdd(current->child_left,s);
        } else if(current->data > s && current->child_left == nullptr){
            current->child_left = new Node<T>;
            current->child_left->data = s;
            current->child_left->parent = current;
            current->child_left->id = id;
            size++;
            id++;
            return;
        } else if(current->data <= s && current->child_right != nullptr){
            zaloopAdd(current->child_right,s);
        }else if(current->data <= s && current->child_right == nullptr){
            current->child_right = new Node<T>;
            current->child_right->data = s;
            current->child_right->parent = current;
            current->child_right->id = id;
            size++;
            id++;
            return;
        }
    }

    Node<T>* search(int data){
        if(size == 0){
            cout << "ERROR: drzewo jest puste" << endl;
            return nullptr;
        }
        Node<T>* temp = root;

        while (temp != nullptr){
            if (temp->data == data){
               return temp;
            } else if(temp->data <= data){
                temp = temp->child_right;
            } else temp = temp->child_left;
        }
        return nullptr;
    }


    void del_node(int s){
        Node<T>* temp = search(s);
        if(temp == nullptr) return;

        if(temp->child_right == nullptr && temp->child_left == nullptr) {
            if(temp->parent != nullptr){
                if(temp->parent->child_right == temp){
                    temp->parent->child_right = nullptr;
                } else {
                    temp->parent->child_left = nullptr;
                }
            } else {
                root = nullptr;
            }
            delete temp;
        }
        else if (temp->child_left != nullptr){
            Node<T>* temp2 = temp->child_left;
            while(temp2->child_right != nullptr){
                temp2 = temp2->child_right;
            }
            temp->data = temp2->data;
            if(temp2->parent->child_right == temp2){
                temp2->parent->child_right = temp2->child_left;
            } else {
                temp2->parent->child_left = temp2->child_left;
            }
            if(temp2->child_left != nullptr){
                temp2->child_left->parent = temp2->parent;
            }
            delete temp2;

        }
        else if (temp->child_left == nullptr && temp->child_right != nullptr){
            Node<T>* temp2 = temp->child_right;
            while(temp2->child_left!= nullptr){
                temp2 = temp2->child_left;
            }
            temp->data = temp2->data;
            if (temp2->parent->child_left == temp2){
                temp2->parent->child_left = temp2->child_right;
            } else {
                temp2->parent->child_right = temp2->child_right;
            }
            if (temp2->child_right != nullptr){
                temp2->child_right->parent = temp2->parent;
            }
            delete temp2;

        }
        size--;
        height = 0;
    }

    void in_order(Node<T>* temp){
        if(temp != nullptr){
            in_order(temp->child_left);

            cout << temp->data << " ";

            in_order(temp->child_right);
        }
    }

    void pre_order(Node<T>* temp){
        if (temp != nullptr){
            cout << temp->data << " ";

            pre_order(temp->child_left);

            pre_order(temp->child_right);
        }
    }

    void calculate_hight(Node<T>* temp, int height){
        if (this->height < height){
            this->height = height;
        }
        if (temp != nullptr){
             calculate_hight(temp->child_left,height+1);
             calculate_hight(temp->child_right,height+1);
        }
    }

    void del_nodes(Node<T>* temp){

        if (temp == nullptr) return;
            del_nodes(temp->child_right);
            del_nodes(temp->child_left);
            delete temp;
            root = nullptr;
            size = 0;
            id = 0;
            height = 0;
    }

    bool check_number(string str){
        for (int i = 0; i < str.length(); ++i) {
            if(isdigit(str[i]) == false)
            {
                cout << "To nie jest liczba"<<endl;
                return false;
            }return true;
        }

    }

    void info(){
        cout << "Size: " << size << endl;
        cout << "Root: " << root << endl;
        calculate_hight(root, 0);
        cout << "Height: " << height << endl;
    }


};