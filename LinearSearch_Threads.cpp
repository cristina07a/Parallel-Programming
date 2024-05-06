#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#define SIZE 16
#define THREAD_MAX 4

int elements[SIZE] = { 1, 2, 4, 7, 9, 12, 14, 17, 11, 17, 17, 17, 32, 35, 38, 40 };
int found = 0;

void ThreadSearch(int start, int end,int key) {
    for (int i = start; i < end; i++) {
        if (elements[i] == key)
        {
            found = 1;
            cout << "S-a gasit elementul cautat la pozitia " << i <<endl;
        }
    }
}

int main() {
    int key;
    vector<thread> threads;
    cout << "Elementul cautat: ";
    cin >> key;
    for (int i = 0; i < THREAD_MAX; i++) {
        threads.push_back(thread(ThreadSearch, i * (SIZE / 4), (i + 1) * (SIZE / 4),key));
    }

    for (auto& t : threads) {
        t.join();
    }

    if (found == 0)
        cout << "Nu s-a gasit elementul cautat" << endl;

    return 0;
}
