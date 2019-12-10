#define INT_MAX 2147483647

#include <iostream>
using namespace std;

template <typename T>
void print_array(T *a, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int *random_int_array(size_t n, int bound = 100, bool negative_numbers=false)
{
  int *a = new int[n];
  for (size_t i = 0; i < n; i++)
  {
    a[i] = !negative_numbers ? rand() % bound : (rand() % (2*bound)) - bound;
  }
  return a;
}

int main()
{
  srand(42);

  return 0;
}