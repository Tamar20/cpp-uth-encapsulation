#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

/* // Box /////////// */

typedef struct Box
{
    double length;
    double width;
    double height;
}Box;


/* Box::Box(double)  default dim = 1 */
void _ZN3BoxC1Ed(Box *this, double dim);
/* Box::Box(double , double, double) */
void _ZN3BoxC1Eddd(Box *this, double l, double w, double h);
/* Box::~Box */
void _ZN3BoxD1Ev(Box *this);

/* Box* Box::operator*=(double); */
Box* _ZN3Box17multAndAssignmentBd(Box *this, double mult);

/* void Box::print() */
void _ZN3Box5printB(Box *this);



/* /// Shelf /////////// */

const char* const DEF_MSG;
const char* message;

typedef struct Shelf
{
    Box boxes[3];
}Shelf;

/* /// Shelf Defs /////////// */

/* void Shelf::setBox(int index, const Box& dims) */
void _ZN5Shelf6setBoxEiRK3Box(Shelf *this, int index, const Box* dims);

/* double Shelf::getVolume() */
double _ZNK3Box9getVolumeEv(Shelf *this);

/* void Shelf::print() */
void _ZNK5Shelf5printEv(Shelf *this);


#endif /* __CPP2C_ENCAPSULATION_DEFS_H__ */

