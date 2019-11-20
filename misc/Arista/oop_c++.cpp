#include <stdlib.h>
#include <stdio.h>

class C {
    public:
        void func() {
            printf("func called\n");
        }
        virtual void virtualFunc() {
            printf("virtual func called\n");
        }
};

int main (int argc, char ** argv) {
    C * obj = NULL;
    /* What does the following print? */
    obj->func();
    /* What does the following print? */
    obj->virtualFunc();
    /* What's the difference? */
}

/* What's polymorphism?  */










/* What's abstraction?  */












/* What's a virtual function table?  */












/* What's a smart pointer?  */










/* What's a copy constructor?  */








/* Tell me what this expression does:  */
/*    cout << 3;  */







/* What could it do?  */










/* Have you ever seen OOP inside a Unix kernel?  */









/* What's C++0X?  */









/* What is const?  */









/* What is name mangling?  */










/* What's std::map?  */









/* What does "extern C" do?  */
