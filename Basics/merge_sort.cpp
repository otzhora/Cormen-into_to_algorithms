#define INF 2147483647

#include <iostream>

using namespace std;

void merge(int *A, int l, int q, int r)
{
  int n1 = q - l + 1, n2 = r - q;
  int *L = new int[n1 + 1];
  int *R = new int[n2 + 1];

  for (size_t i = 0; i < n1; i++)
  {
    L[i] = A[l + i];
  }
  L[n1] = INF;

  for (size_t i = 0; i < n2; i++)
  {
    R[i] = A[q + i + 1];
  }
  R[n2] = INF;

  int i = 0, j = 0, k = l;
  for (size_t _ = 0; _ < n1 + n2; _++)
  {
    if (L[i] < R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }
}

void merge_sort(int *A, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int q = (l + r) / 2;
  merge_sort(A, l, q);
  merge_sort(A, q + 1, r);
  merge(A, l, q, r);
}

int main()
{
  srand(50);

  int n = 11;
  int *a = new int[n];

  for (size_t i = 0; i < n; i++)
  {
    a[i] = rand() % 100;
  }

  for (size_t i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  merge_sort(a, 0, n - 1);

  for (size_t i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}