#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv)
  {
  mat A = randu<mat>(4000,5000);
  mat B = randu<mat>(4000,5000);

  cout << A*B.t() << endl;

  return 0;
  }
