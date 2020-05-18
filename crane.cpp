#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define EPS 1e-9

main() {
  int N;
  while (cin >> N) {
    vector<int> vx(N), vy(N);
    int mnx = 1000000000, mxx = -1000000000;
    for (int i = 0; i < N; i++) {
      cin >> vx[i] >> vy[i];
      if (vy[i] == 0) {mnx = min(mnx, vx[i]); mxx = max(mxx, vx[i]);}
    }
    vx.push_back(vx[0]); vy.push_back(vy[0]);

    double tcx = 0, tar = 0;
    for (int i = 0; i < N; i++) {
      double ar = (vx[i]*vy[i+1] - vy[i]*vx[i+1]) / 2.0;
      double cx = (vx[i] + vx[i+1]) / 3.0;
      double cy = (vy[i] + vy[i+1]) / 3.0;
      tcx += cx * ar;
      tar += ar;
    }
    if (tar < 0.0) {tar = -tar; tcx = -tcx;}
    double cx = tcx / tar;
  }
}
