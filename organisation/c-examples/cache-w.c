//
// The example shows how the performance of 
// a program is affected by the cache.
//
#define N 10000
int a[N][N];
int main() {
  int sum=0, i, j;
  for (j =0; j<N; j++)
    for (i=0; i<N; i++)
      sum =+ a[i][j];
}
