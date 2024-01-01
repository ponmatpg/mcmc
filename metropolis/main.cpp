#include <iostream>
#include <random>

#include "include/density.hpp"
#include "include/metropolis.hpp"

int main(int argc, char **argv) {
  std::size_t n;
  if (argc > 1)
    n = std::atoi(argv[1]);
  else
    n = 1;

  std::mt19937 gen{0};
  auto prop_dist = std::normal_distribution<double>{0.0, 1.0};

  // auto target_density = [](double x) { return mcmc::cauchypdf(x, 0.0, 0.5);
  // };
  auto target_density = [](double x) { return mcmc::normalpdf(x, 5.0, 3.0); };
  mcmc::MhAlgo mh{prop_dist, target_density};

  for (std::size_t i = 0; i < n; ++i) {
    std::cout << mh(gen) << std::endl;
  }
  return 0;
}
