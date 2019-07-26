#include <iostream>

using namespace std;

template <class T>
void shell_sort(T a[], std::size_t n)
{
    int h;

    for (h = 1; h < n/3; h = h * 3 + 1)
        ;

    for (; h >=1; h /= 3)
    {
        for (int i = h; i < n; ++i)
            for (int j = i; j >= h && a[j] < a[j-h]; j -= h)
                swap(a[j-h], a[j]);
    }
}

int main(int argc, char *argv[])
{
    int a[] {3, 1, 4, 5, 2};
    shell_sort(a, 5);
    for (auto e: a)
        cout << e << " ";
    cout << endl;
    return 0;
}

