#include <algorithm>
#include <cmat>
#include <cstdio>


int i, n, order[8];
double a[8], b[8], L;

double AtterisageDangereux() {
  double dernierAtte = a[order[0]];     
  for (i = 1; i < n; i++) {                      
    double cibleAtteTemps = dernierAtte + L;
    if (cibleAtteTemps <= b[order[i]])
      dernierAtte = max(a[order[i]], cibleAtteTemps);
    else
      return 1;
  }
  return dernierAtte - b[order[n - 1]];
}

