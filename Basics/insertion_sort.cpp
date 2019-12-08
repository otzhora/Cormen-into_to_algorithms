#include <iostream>
using namespace std;

void insertion_sort(int *a, int n)
{
  for (size_t i = 1; i < n; i++)
  {
    int key = a[i];

    for (size_t j = i - 1; j >= 0 && key < a[j]; j--)
    {
      a[j + 1] = a[j];
      a[j] = key;
    }
  }
}

int main()
{
  srand(42);

  int n = 30;
  int *a = new int[n];
  for (size_t i = 0; i < n; i++)
  {
    a[i] = rand() % 100;
    cout << a[i] << " ";
  }
  cout << endl;

  insertion_sort(a, n);

  for (size_t i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}