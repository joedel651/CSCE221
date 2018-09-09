#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H
using namespace std;
#include <iostream>
template <class Type>
class AbstractStack
{
private:
    //data goes here
   
    
public:
    //constructor with void in the () means unspecified parameters 
    AbstractStack(void) {}
    
    ~AbstractStack(void) {}
    
    bool isEmpty(void) {}
    
    int size(void) {}
    
    Type top() throw(exception) {}
    
    Type pop() throw(exception) {}
    
    void push ( Type e ) {}
};

#endif
