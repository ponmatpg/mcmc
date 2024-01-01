#include <cstdlib>

#include "utility.hpp"

#ifndef MCMC_DENSITY_HPP
#define MCMC_DENSITY_HPP

namespace mcmc {

double normalpdf(double x, double mu = 0.0, double sigma = 1.0) {
  return std::exp(-0.5 * (x - mu) * (x - mu) / (sigma * sigma)) /
         (sigma * std::sqrt(2 * mcmc::pi()));
}

double cauchypdf(double x, double x0, double gamma) {
  return 1.0 / (mcmc::pi() * gamma * (1 + ((x - x0) / gamma) * ((x - x0) / gamma)));
}

} // namespace mcmc 
#endif 
