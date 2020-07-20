#ifndef BASE_H
#define BASE_H

#include "vec.h"
#include <vector>

class Object
{
public:
    Primitive build_primitive();

private:
    Mat_2x2d transformer;
};
class Primitive
{
public:
private:
    std::vector<Vec_2d> points;
};
class Bitmap
{
private:
    Vec_2i pos;
    std::vector<std::vector<Vec_4d>> pixels;
};

class Scene
{
public:
    void draw(std::vector<Bitmap &>);
};

template <typename T>
class Sampler1D
{
public:
    T sample(double x);
};

template <typename T>
class Sampler2D
{
public:
    T sample(double x, double y);
};

class Manager
{
};

#endif