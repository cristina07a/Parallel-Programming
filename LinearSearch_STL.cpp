#include <iostream>
#include <vector>

using namespace std;

int main() {
    int element;
    vector<int> vectorr = { 1, 2, 4, 7, 9, 12, 14, 17, 17, 17, 17, 30, 32, 35, 38, 40 };

    cout << "Scrieti termenul pe care il cautati: ";
    cin >> element;

    auto it = vectorr.begin();
    while ((it = find(it, vectorr.end(), element)) != vectorr.end()) {
        cout << "Numarul a fost gasit la pozitia: " << (it - vectorr.begin()) << endl;
        ++it;
    }

    if (it == vectorr.begin()) {
        cout << "Nu s-a gasit elementul cautat." << endl;
    }

    return 0;
}