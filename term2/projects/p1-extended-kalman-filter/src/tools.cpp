#include "tools.h"
#include "constants.h"
#include <cmath>

Eigen::VectorXd Tools::calculateRMSE(const std::vector<Eigen::VectorXd>& estimations,
                                     const std::vector<Eigen::VectorXd>& ground_truth)
{
    Eigen::VectorXd output = Eigen::VectorXd::Zero(estimations[0].rows(),
                                                   estimations[0].cols());

    for (std::size_t i = 0U; i < estimations.size(); ++i)
    {
        Eigen::VectorXd error = ground_truth[i] - estimations[i];
        output += error.cwiseProduct(error);
    }

    output /= estimations.size();

    return output.cwiseSqrt();
}

bool Tools::isNotZero(const double x)
{
    return std::fabs(x) > kZeroThreshold;
}

double Tools::normalizeAngle(const double x)
{
    double x_mod = std::fmod(x + kPi, k2Pi);
    if (x_mod < 0.0)
    {
        x_mod += k2Pi;
    }

    return x_mod - kPi;
}
