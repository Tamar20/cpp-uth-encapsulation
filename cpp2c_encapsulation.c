
/* Created by tamar on 6/14/20. */

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

extern const char* const DEF_MSG;
extern const char* message;

static Box largeBox;

/* box99 */
static Box _ZZ8thisFuncvE5box99;
/* box88 */
static Box _ZZ8thatFuncvE5box88;
/* thisFuncIsInitialized */
static int _Zs21thisFuncIsInitialized = 0;
/* thatFuncIsInitialized */
static int _Zs21thatFuncIsInitialized = 0;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");

    if(!_Zs21thisFuncIsInitialized){
        _Zs21thisFuncIsInitialized = 1;
        _ZN3BoxC1Eddd(&_ZZ8thisFuncvE5box99, 99, 99, 99);
    }

    _ZZ8thisFuncvE5box99.length = 10;
    _ZZ8thisFuncvE5box99.height = 10;
    _ZZ8thisFuncvE5box99.width = 10;
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");

    if(!_Zs21thatFuncIsInitialized){
        _Zs21thatFuncIsInitialized = 1;
        /* Box::Box(double, double, double) */
        _ZN3BoxC1Eddd(&_ZZ8thisFuncvE5box99, 88, 88, 88);
    }
    /* Box::operator*=(double) */
    _ZN3Box17multAndAssignmentBd(&_ZZ8thatFuncvE5box88, 10);

}

void doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;

    printf("\n--- Start doBoxes() ---\n\n");

    /* Box::Box(double) */
    _ZN3BoxC1Ed(&b1, 3);

    /* Box::Box(double, double, double) */
    _ZN3BoxC1Eddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    /* Box::operator*=(double) */
    _ZN3Box17multAndAssignmentBd(&b1, 1.5);
    _ZN3Box17multAndAssignmentBd(&b2, 0.5);


    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    b3 = b2;
    b4 = b2;

    /* Box::operator*=(double) */
    _ZN3Box17multAndAssignmentBd(&b4, 3);

    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");


    /* Box::operator*=(double) */
    _ZN3Box17multAndAssignmentBd(&b3, 1.5);
    _ZN3Box17multAndAssignmentBd(&b4, 0.5);

    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    /* Box::~Box */
    _ZN3BoxD1Ev(&b4);
    _ZN3BoxD1Ev(&b3);
    _ZN3BoxD1Ev(&b2);
    _ZN3BoxD1Ev(&b1);
}


void doShelves()
{
    Box aBox;
    Shelf aShelf;
    Box tempBox1;
    Box tempBox2;

    printf("\n--- start doShelves() ---\n\n");

    /* Box::Box(double) */
    _ZN3BoxC1Ed(&aBox, 5);
    _ZN3BoxC1Ed(&aShelf.boxes[0], 1);
    _ZN3BoxC1Ed(&aShelf.boxes[1], 1);
    _ZN3BoxC1Ed(&aShelf.boxes[2], 1);

    /* Shelf::print() */
    _ZNK5Shelf5printEv(&aShelf);

    /* Shelf::setBox(int index, const Box& dims) */
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &largeBox);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    /* Shelf::print() */
    _ZNK5Shelf5printEv(&aShelf);

    message = "This is the total volume on the shelf:";

    /* Shelf::print() */
    _ZNK5Shelf5printEv(&aShelf);

    message = "Shelf's volume:";

    /* Shelf::print() */
    _ZNK5Shelf5printEv(&aShelf);

    /* Box::Box(double, double, double) */
    _ZN3BoxC1Eddd(&tempBox1, 2, 4, 6);
    _ZN3BoxD1Ev(&tempBox1);

    /* Box::Box(double) */
    _ZN3BoxC1Ed(&tempBox2, 2);
    _ZN3BoxD1Ev(&tempBox2);

    /* Shelf::setBox(int, const Box&) */
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &tempBox1);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &tempBox2);

    /* Shelf::print() */
    _ZNK5Shelf5printEv(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    /* Box::~Box */
    _ZN3BoxD1Ev(&aShelf.boxes[2]);
    _ZN3BoxD1Ev(&aShelf.boxes[1]);
    _ZN3BoxD1Ev(&aShelf.boxes[0]);
    _ZN3BoxD1Ev(&aBox);
}

int main()
{
    /* Box::Box(double , double, double) */
    _ZN3BoxC1Eddd(&largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    /* Box::~Box */
   if(_Zs21thisFuncIsInitialized)
   {
       _ZN3BoxD1Ev(&_ZZ8thisFuncvE5box99);
   }

   if(_Zs21thatFuncIsInitialized)
   {
       _ZN3BoxD1Ev(&_ZZ8thatFuncvE5box88);
   }

    _ZN3BoxD1Ev(&largeBox);

    return 0;
}

/* gcc  cpp2c_encapsulation.c cpp cpp2c_encapsulation_defs.c -g -Wall -Werror -pedantic -ansi -Wconversion */