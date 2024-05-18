#include <iostream>
#include <vector>
#include <execution>
using namespace std;

int main() {
    int element, ok = 0;
    vector<int> vectorr = { 1, 2, 4, 7, 9, 12, 14, 17, 17, 17, 17, 30, 32, 35, 38, 40 };

    cout << "Scrieti termenul pe care il cautati: ";
    cin >> element;

    auto it = vectorr.begin();
    while ((it = find(execution::par, it, vectorr.end(), element)) != vectorr.end()) 
    {
        cout << "Numarul a fost gasit la pozitia: " << (it - vectorr.begin()) << endl;
        ok = 1;
        ++it;
    }

    if (ok == 0) {
        cout << "Nu s-a gasit elementul cautat." << endl;
    }

    return 0;
}
