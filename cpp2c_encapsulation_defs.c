
/* Created by tamar on 6/14/20. */


#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/* /// Box /////////// */


/* Box::Box(double)  difault dim = 1 */
void _ZN3BoxC1Ed(Box *this, double dim)
{
    this->length = dim;
    this->width = dim;
    this->height = dim;
    _ZN3Box5printB(this);
}

/* Box::Box(double , double, double) */
void _ZN3BoxC1Eddd(Box *this, double l, double w, double h)
{
    this->length = l;
    this->width = w;
    this->height = h;
    _ZN3Box5printB(this);
}

/* Box::~Box */
void _ZN3BoxD1Ev(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

/* Box::Box* operator*=(double); */
Box* _ZN3Box17multAndAssignmentBd(Box *this, double mult)
{
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

/* void Box::print() */
void _ZN3Box5printB(Box *this)
{
printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}


/* /// Shelf /////////// */

const char* const DEF_MSG = "The total volume held on the shelf is";
const char* message = DEF_MSG;

/* void Shelf::setBox(int index, const Box& dims) */
void _ZN5Shelf6setBoxEiRK3Box(Shelf *this, int index, const Box* dims)
{
    this->boxes[index] = *dims;
}

/* double Shelf::getVolume() */
double _ZNK3Box9getVolumeEv(Shelf *this)
{
    size_t i = 0;
    double vol = 0;
    for (i = 0; i < 3; ++i)
    vol += this->boxes[i].width * this->boxes[i].length * this->boxes[i].height;

    return vol;
}

/* void Shelf::print() */
void _ZNK5Shelf5printEv(Shelf *this)
{                                      /* getVolume() */
    printf("%s %f\n", message, _ZNK3Box9getVolumeEv(this));
}


