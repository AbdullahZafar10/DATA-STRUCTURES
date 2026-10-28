#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "";
    string undo[100], redo[100];
    int u = -1, r = -1;
    int choice;
    char ch;

    do {
        cout << "\n1. Type character\n";
        cout << "2. Delete character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Show text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;

            undo[++u] = text;
            text += ch;
            r = -1;
            break;

        case 2:
            if (text.empty()) {
                cout << "Text is empty!\n";
            }
            else {
                undo[++u] = text;
                text.pop_back();
                r = -1;
            }
            break;

        case 3:
            if (u == -1) {
                cout << "Nothing to undo!\n";
            }
            else {
                redo[++r] = text;
                text = undo[u--];
            }
            break;

        case 4:
            if (r == -1) {
                cout << "Nothing to redo!\n";
            }
            else {
                undo[++u] = text;
                text = redo[r--];
            }
            break;

        case 5:
            cout << "Text: " << text << endl;
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
