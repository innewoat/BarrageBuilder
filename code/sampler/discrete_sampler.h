#ifndef DISCRETE_SAMPLER_H
#define DISCRETE_SAMPLER_H

#include <vector>
#include <cmath>

#include "../base/base.h"

template <typename T>
class DiscreteSampler1D : public Sampler1D<T>
{
public:
    T sample(double x)
    {
        int index = (int)round(x * points.size());
        return points.at(index);
    }
    int get_size()
    {
        return points.size();
    }

private:
    std::vector<T> points;
};

#endif