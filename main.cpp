#include "tinysplinecxx.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

int main(int, char **) {
  std::cout << "Hello, world!\n";

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "failed to init SDL" << std::endl;
  }

  tinyspline::BSpline spline(7);
  std::vector<tinyspline::real> ctrlp = spline.controlPoints();
  ctrlp[0] = -1.75; // x0
  ctrlp[1] = -1.0;  // y0

  ctrlp[2] = -1.5; // x1
  ctrlp[3] = -0.5; // y1

  ctrlp[4] = -1.5; // x2
  ctrlp[5] = 0.0;  // y2

  ctrlp[6] = -1.25; // x3
  ctrlp[7] = 0.5;   // y3

  ctrlp[8] = -0.75; // x4
  ctrlp[9] = 0.75;  // y4

  ctrlp[10] = 0.0; // x5
  ctrlp[11] = 0.5; // y5

  ctrlp[12] = 0.5; // x6
  ctrlp[13] = 0.0; // y6
  spline.setControlPoints(ctrlp);

  std::vector<tinyspline::real> result = spline.eval(0.4).result();
  std::cout << "x = " << result[0] << ", y = " << result[1] << std::endl;

  tinyspline::BSpline beziers = spline.derive().toBeziers();
  result = beziers(0.3).result();

  std::cout << "x = " << result[0] << ", y = " << result[1] << std::endl;
  return 0;
}
