#include "adder.h"


int main() {
    srand((unsigned) time(0));
    auto* test = new BST<int>;
    int node_amount = 0;

    int exit = 0;

    do {
        int choice;
        cout << "\tDrzewo BST" << endl;
        cout << "Choose option" << endl;
        cout << "1. Create BST" << endl;
        cout << "2. Add node" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Show node" << endl;
        cout << "5. Show BST" << endl;
        cout << "6. Delete list" << endl;
        cout << "7. Info" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                if(test->root != nullptr){
                    cout << "BST juz stworzone" << endl;
                    break;
                }

                cout << "Podaj ilosc Node" << endl;
                int amount;
                cin >> amount;
                node_amount = amount;
                auto start = chrono::steady_clock::now();

                for (int i = 0; i < node_amount; ++i) {
                    test->addNode(rand()%100000);
                }

                auto end = chrono::steady_clock::now();
                chrono::duration<double> duration = end - start;
                cout <<"Rozmiar: "<<test->size << endl;
                cout << "Czas wykonania: " << duration.count() <<" s"<< endl;
                break;
            }
            case 2: {

                string data;
                cout << "wprowadz dane (int)" << endl;
                cin >> data;
                if(test->check_number(data)==false)
                    break;
                test->addNode(stoi(data));
                cout <<"Rozmiar: "<<test->size << endl;
                break;

            }
            case 3: {
                string data;
                cout << "wprowadz dane (int)" << endl;
                cin >> data;
                if(test->check_number(data)==false)
                    break;
                test->del_node(stoi(data));
                cout <<"Rozmiar: "<<test->size << endl;
                break;

            }
            case 4: {
                string data;
                cout << "wprowadz dane (int)" << endl;
                cin >> data;
                if(test->check_number(data)==false)
                    break;

                auto start = chrono::steady_clock::now();
                test->search(stoi(data));
                auto end = chrono::steady_clock::now();
                chrono::duration<double> duration = end - start;
                cout << "Czas wykonania: " << duration.count() <<" s"<< endl;
                break;


            }
            case 5: {
                int choice;
                cout << "W jaki sposob?" << endl;
                cout << "1. Pre-order" << endl;
                cout << "2. In-order" << endl;
                cin >> choice;
                    if (choice == 1){
                        auto start = chrono::steady_clock::now();
                        test->pre_order(test->root);
                        auto end = chrono::steady_clock::now();
                        chrono::duration<double> duration = end - start;
                        cout << "Czas wykonania: " << duration.count() <<" s"<< endl;

                    }
                    if (choice == 2){
                        auto start = chrono::steady_clock::now();
                        test->in_order(test->root);
                        auto end = chrono::steady_clock::now();
                        chrono::duration<double> duration = end - start;
                        cout << "Czas wykonania: " << duration.count() <<" s"<< endl;
                    }

                    break;
            }

            case 6: {
                auto start = chrono::steady_clock::now();
                test->del_nodes(test->root);
                auto end = chrono::steady_clock::now();
                chrono::duration<double> duration = end - start;
                cout << "Czas wykonania: " << duration.count() <<" s"<< endl;
                break;
            }

            case 7: {
                test->info();
                break;
            }
            case 8: {
                test->del_nodes(test->root);
                exit++;
                break;
            }
        }

    } while (exit == 0);

    delete test;

}
