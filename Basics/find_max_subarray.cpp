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

class result {
  public:
    int l;
    int r;
    int sum;

    result(int l_, int r_, int sum_) {
      l = l_;
      r = r_;
      sum = sum_;
    }
};

result find_max_crossing_subarray(int *A, int l, int mid, int r) {
  int left_sum = -1, left = mid, sum = 0;
  for (int i = mid; i >= l; i--) {
    sum += A[i];
    if(sum > left_sum) {
      left = i;
      left_sum = sum;
    }
  }

  int rigth_sum = -1, rigth = mid + 1;
  sum = 0;
  for (int i = mid + 1; i <= r; i++) {
    sum += A[i];
    if(sum > rigth_sum) {
      rigth = i;
      rigth_sum = sum;
    }
  }

  return result(left, rigth, left_sum + rigth_sum);
}

result find_max_subarray(int *A, int l, int r) {
  if(l == r) return result(l, r, A[l]);
  
  int mid = (l + r) / 2;
  result left = find_max_subarray(A, l, mid);
  result rigth = find_max_subarray(A, mid + 1, r);
  result cross = find_max_crossing_subarray(A, l, mid, r);

  if(left.sum >= rigth.sum && left.sum >= cross.sum) return left;
  if(rigth.sum >= left.sum && rigth.sum >= cross.sum) return rigth;
  return cross;
}

int main()
{
  srand(42); // for seed=42 answer is 7 14 169

  int n = 20;
  int *A = random_int_array(n, 100, true);
  print_array(A, n);
  result r = find_max_subarray(A, 0, n-1);
  cout << r.l << " " << r.r << " " << r.sum << endl;
  return 0;
}