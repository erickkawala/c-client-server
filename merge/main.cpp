#include <iostream>
#include <stack>

using namespace std;

struct frame
{
    int type, lo, hi;
    frame(int it, int il, int ih)
    {
        type = it;
        lo = il;
        hi = ih;
    }
};

template <class T>
void merge(T x[], int lo, int mid, int hi)
{
      T *aux = new T[hi - lo + 1];
      std::copy(x+lo, x+hi+1, aux);
      int i(0); // index of smallest element of A
      int j(mid+1-lo); // index of smallest element of B
      for (int k = lo; k <= hi; ++k)
      {
          if (i > mid-lo)
              x[k] = aux[j++]; // list A exhausted
          else if (j > hi-lo)     // list B exhausted
              x[k] = aux[i++];

          else if (aux[j] < aux[i])
              x[k] = aux[j++];
          else
              x[k] = aux[i++];

      }
      delete [] aux;

}

// iterative merge sort
template <class T>
void ims(T a[], int n)
{
    stack<frame> s;
    s.push(frame(0, 0, n-1));

    while (!s.empty())
    {
        frame f = s.top();
        s.pop();

        if (f.type == 0 && f.lo < f.hi)
        {
            int mid = (f.lo + f.hi)/2;
            s.push(frame(1, f.lo, f.hi));
            s.push(frame(0, mid+1, f.hi));
            s.push(frame(0, f.lo, mid));
        }
        else
            merge(a, f.lo, (f.lo+f.hi)/2, f.hi);

    }

}

template <class T>
void merge_sort(T a[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo+hi)/2;
        merge_sort(a, lo, mid);
        merge_sort(a, mid+1, hi);
        merge(a, lo, mid, hi);
    }
}

int main(int argc, char *argv[])
{
    int x[] {3, 1, 4, 5, 2};
    ims(x, 5);

    for (auto e: x)
        cout << e << " ";
    cout << endl;
    return 0;
}
