#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
// pre: none
// post: a[0..n-1] is sorted in nondecreasing order
void insertion_sort(T a[], std::size_t n)
{
    for (int i = 1; i < n; ++i)
        for (int j = i; j > 0 && a[j] < a[j-1]; --j)
            swap(a[j], a[j-1]);
}

int main(int argc, char *argv[])
{
    int a[] {7, 1, 8, 3, 5, 4, 6, 2};

    insertion_sort(a, 8);

    for (auto e: a)
        cout << e << " ";
    cout << endl;
    return 0;
}


