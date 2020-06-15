//
// Created by tamar on 6/14/20.
//

#include <cstdio>
#include "cpp2c_encapsulation_defs.h"

//// Box ////////////

Box::Box(double dim)
:   length(dim)
,   width(dim)
,   height(dim)
{
    print();
}

Box::Box(double l, double w, double h)
:   length(l)
,   width(w)
,   height(h)
{
    print();
}

Box::~Box()
{
    std::printf("Box destructor, %f x %f x %f\n", width, height, length);
}

Box& Box::operator*=(double mult)
{
width *= mult;
height *= mult;
length *= mult;

return *this;
}

void Box::print() const
{
printf("Box: %f x %f x %f\n", length, width, height);
}


//// Shelf ////////////

const char* const Shelf::DEF_MSG = "The total volume held on the shelf is";
const char* Shelf::message = Shelf::DEF_MSG;

void Shelf::setBox(int index, const Box& dims)
{
boxes[index] = dims;
}

double Shelf::getVolume() const
{
double vol = 0;
for (size_t i = 0; i < NUM_BOXES; ++i)
vol += boxes[i].width * boxes[i].length * boxes[i].height;

return vol;
}

void Shelf::print() const
{
std::printf("%s %f\n", message, getVolume());
}


