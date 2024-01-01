#include <algorithm>
#include <cstdlib>
#include <random>

#include "density.hpp"

#ifndef MCMC_METROPOLIS_HPP
#define MCMC_METROPOLIS_HPP


namespace mcmc {
template <typename ProposalDist, typename UncondDensity> class MhAlgo {
public:
  MhAlgo(ProposalDist prop_dist, UncondDensity target_density) noexcept
      : prop_dist_(prop_dist), target_density_(target_density) {}

  template <typename Engine> double operator()(Engine &gen) {
    return sample(gen);
  }

private:
  template <typename Engine> double sample(Engine &gen) {
    double x_prop = x_ + prop_dist_(gen);
    double target_density_ratio =
        target_density_(x_) > 0 ? target_density_(x_prop) / target_density_(x_)
                                : 0.0;
    double accept_prob = std::min(1.0, target_density_ratio);
    double accept_sample = unif_(gen);

    x_ = accept_sample < accept_prob ? x_prop : x_;

    return x_;
  }

  ProposalDist prop_dist_;
  UncondDensity target_density_;

  double x_{0.0};
  std::uniform_real_distribution<> unif_{0.0, 1.0};
};

} // namespace mcmc 

#endif
