//
// The example shows how the performance of
// a program is affected by the cache.
//
#define N 10000
int a[N][N];
int main() {
  int  sum=0, i, j;
  for (i =0; i<N; i++)
    for (j=0; j<N; j++)
      sum =+ a[i][j];
}
