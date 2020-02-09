// MemTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <chrono>

struct PerformanceTestStruct
{
    double myDouble[20000];
    int justASmallInt = 5;

    double GetADouble(int idx)
    {
        return myDouble[idx];
    }

    void AddToAll(double numbertoadd)
    {
        for (int i = 0; i < 20000; i++) // ...initialize it
        {
            myDouble[i] += numbertoadd;
        }
    }

    void init()
    {
        for (int i = 0; i < 20000; i++) // ...initialize it
        {
            myDouble[i] = 0.0;
        }
    }

};

int main()
{
    int int_test = 4;
    int *int_ptr = &int_test;

    size_t size_of_int = sizeof(int_test);
    size_t size_of_int_ptr = sizeof(int_ptr);

    std::cout << "adress of int_ptr: " << int_ptr << std::endl;
    std::cout << "sizeof(int_test): " << size_of_int << std::endl;
    std::cout << "sizeof(int_ptr): " << size_of_int_ptr << std::endl;

    void* null_ptr = nullptr;
    std::cout << "null ptr value: " << null_ptr << std::endl;

    std::cout << std::endl;
    std::cout << "Memory allocation test" << std::endl;

    int test1 = 4;
    int test2 = 5;

    int* ptr_test1 = &test1;
    int* ptr_test2 = &test2;

    std::cout << "ptr_test1 adress (integer): " << ptr_test1 << std::endl;
    std::cout << "ptr_test2 adress (integer): " << ptr_test2 << std::endl;
    std::cout << "difference: "  << ptr_test2 - ptr_test1 << " int type can fit between them" << std::endl;
    std::cout << "which is : " << (ptr_test2 - ptr_test1)*sizeof(test2) << " bytes" << std::endl;
    std::cout << std::endl;


    //trying to read padding:

    std::cout << "Trying to read padding between ptr_test1 and ptr_Test2 :" << *(ptr_test1+sizeof(test1)) <<std::endl;

    std::cout << std::endl;

    std::cout << "Operator ++ test for int:" << std::endl;
    int operator_test = 5;
    int *p_operator_test = &operator_test;

    std::cout << "int value:    " << operator_test << std::endl;
    std::cout << "int value ++: " << ++operator_test << std::endl;
     
    std::cout << "int ptr value:    " << p_operator_test << std::endl;

    int* second_test = p_operator_test + 1;

    std::cout << "int  ptrvalue ++: " << second_test << std::endl;
    int memdiff = second_test - p_operator_test;
    std::cout << "difference of int type ptr (ptr2 -ptr1 )of : " << memdiff << std::endl;
    std::cout <<"int value and the size of the data type is " << sizeof(operator_test) << " bytes" << std::endl;
    
    





    {
        std::cout << std::endl << "Lets redo the test for uint8" << std::endl;
        std::cout << "Operator ++ test for uint8_t:" << std::endl;
        uint8_t operator_test = 5;
        uint8_t* p_operator_test = &operator_test;

        std::cout << "uint8_t value:    " << operator_test << std::endl;
        std::cout << "uint8_t value ++: " << ++operator_test << std::endl;

        std::cout << "uint8_t ptr value:    " << p_operator_test << std::endl;

        uint8_t* second_test = p_operator_test + 1;

        std::cout << "int  ptrvalue ++: " << second_test << std::endl;
        int memdiff = second_test - p_operator_test;
        std::cout << "difference of int type ptr (ptr2 -ptr1 )of : " << memdiff << std::endl;
        std::cout << "uint8_t value and the size of the data type is " << sizeof(operator_test) << " bytes" << std::endl;
        std::cout << "note that in order for the adress to be properly displayed, it needs to be casted" << std::endl << std::endl;
    }



    char* char_ptr_first = (char*)p_operator_test;
    char* char_ptr_second = (char*)second_test;
    std::cout << "casting int ptr to char ptr... " << std::endl;
    
    //std::cout << "first ptr: " << char_ptr_first << std::endl;
    //std::cout << "second ptr: " << char_ptr_second << std::endl;
    std::cout << "casting the difference in bytes (char type ptr (ptr2 -ptr1 )) :" << char_ptr_second - char_ptr_first << std::endl;
    std::cout << "char with 1 byte per char " << std::endl;

    std::cout <<std::endl;

    std::cout << "Operator ++ test for double:" << std::endl;
    double operator_test_double = 5.5;
    double* p_operator_test_double = &operator_test_double;

    std::cout << "double value: " << operator_test_double << std::endl;
    std::cout <<"double value ++" << ++operator_test_double << std::endl;

    std::cout << "double ptr value:    " << p_operator_test_double << std::endl;

    double* second_test_double = p_operator_test_double + 1;

    std::cout << "double  ptrvalue ++: " << second_test_double << std::endl;
    std::cout << "difference of : " << second_test_double - p_operator_test_double << " double and the size of the data type is " << sizeof(operator_test_double) << " bytes" << std::endl;

    std::cout << std::endl << "Void ptr example. A void pointer can point to any data type, but cannot be dereferenced" << std::endl;
    float float_test = 5.6;
    void* void_ptr = &float_test;

    std::cout << "The void pointer is set to the float adress" << std::endl;
    std::cout << "The void pointer has adress of: " << void_ptr << std::endl;

    std::cout << std::endl;
    std::cout << "constant and ptr" << std::endl;

    std::cout << "int* const const_ptr" << std::endl << "const int* ptr_to_const_value" << std::endl << "const int* const const_ptr_to_const_value" << std::endl;
    std::cout << "if the ptr is constant (adress cant be changed), the const keyword is after the type" << std::endl;
    int* const const_ptr = nullptr;
    const int* ptr_to_const_value;
    const int* const const_ptr_to_const_value = nullptr;

    std::cout << std::endl;
    std::cout << "memcpy test" << std::endl;
    std::cout << "memcpy takes 3 argument (src void ptr, dest void ptr, num)" << std::endl;
    std::cout << "num is the number of bytes to copy. It is good to use sizeof" << std::endl;
    std::cout << "memcpy can take a pointer to any kind of data" << std::endl;

    uint16_t dest;
    uint16_t src  = 100;

    uint16_t* const src_const_prt = &src;

    std::cout << "desti is uint16_t dest which is not a pointer" << std::endl << "src is uint16_t* const src_const_prt" << std::endl;
    std::cout << "so now we get the adresse of src_const_prt using &src_const_prt" << std::endl;
    std::cout << "And the current adress of src is " << src_const_prt << "with it value being " << *src_const_prt <<std::endl;

    std::cout << "Processing the memcpy..." << std::endl;
        
    memcpy(&dest, src_const_prt, sizeof(uint16_t));

    std::cout << "The value at the src ptr is: " << src << std::endl;
    std::cout << "The new value at the adress of destination ptr is :" << dest << std::endl;
    std::cout << "It appears that the destination must passe using the adressof operator (&) of a non pointer type" << std::endl;

    std::cout << std::endl << "memset test, the function is the following, which is similar to memcpy" <<std::endl;
    std::cout << "void * memset ( void * ptr, int value, size_t num );" << std::endl;
    std::cout << "ptr is the Pointer to the block of memory to fill., value is the data and num is the number or bytes" << std::endl;

    char memset_ptr[]= "this will be erased after the memset";
    std::cout << "lets create a char ptr and a put a char in it" << std::endl;

    std::cout << "adress before memset: " << &memset_ptr << std::endl << "and value: " << memset_ptr << std::endl;
    std::cout << "Doing : memset(memset_ptr, 'x', 3);" << std::endl;
   
    memset(memset_ptr, 'x', 3);
    std::cout << "adress after memset: " << &memset_ptr << std::endl << "and value: " << memset_ptr << std::endl;
    std::cout << "we can see that since we used 3 in the memset, the first 3 bytes are overwritted" << std::endl;


    std::cout << std::endl;
    std::cout << "Now is the time to test some perfomance" << std::endl;
    std::cout << "First lets allocation a uint32_t on stack, heap and heap via shared ptr . The all get the value 123456 or null" << std::endl;
 
    {
        auto start = std::chrono::high_resolution_clock::now();

        uint64_t stack = 123456;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        std::cout << "Stack allocation timefor uint64_t: " << duration << " nanoseconds" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();

        uint64_t* ptr = nullptr;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        std::cout << "Stack allocation timefor uint64_t pointer: " << duration << " nanoseconds" << std::endl;
    }
    
    {
        auto start = std::chrono::high_resolution_clock::now();

        uint64_t* stack = new uint64_t(123456);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        std::cout << "Heap allocation timefor uint64_t: " << duration << " nanoseconds" << std::endl;

        delete stack;
    }

    {

        auto start = std::chrono::high_resolution_clock::now();

        std::shared_ptr<uint64_t> uint64_shared = std::make_shared<uint64_t>(12345123456);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Heap allocation timefor uint64_t on shared_ptr: " << duration << " nanoseconds" << std::endl;
    }

    {   

        auto start = std::chrono::high_resolution_clock::now();

        std::unique_ptr<uint64_t> uint64_unique = std::make_unique<uint64_t>(123456);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Heap allocation timefor uint64_t on unique_ptr: " << duration << " nanoseconds" << std::endl << std::endl;
    }

    std::cout << "Let compare ++ operator of pointer" << std::endl;
    int k = 5;
    int* x_ptr = &k;
    int* second_x_ptr = x_ptr + 1 ;

    std::cout << "current k value is " << k << std::endl;
    std::cout << "x_ptr values is" << x_ptr << std::endl;
    std::cout << "x_ptr ++ is" << second_x_ptr << std::endl;
    std::cout << "and the value of k, the int, with deferencing and ++ is " << ++(*x_ptr) << std::endl;

    std::cout << "Lets compare heap and stack memory location" << std::endl;

    int xStack = 3; //stack
    int xStack2 = 4;

    int* xHeap = new int(5);
    int* xHeap2 = new int(5);

    std::cout << "The value of XHeap is:   " << xHeap << std::endl << "and the adress of it is: " << &xHeap << std::endl;

    std::cout << "The adress of x stack is " << &xStack << std::endl;
    std::cout << "The adress of x heap is  " << xHeap << std::endl;
    std::cout << "The difference in bytes between theirs address is:" << std::endl << (xHeap - &xStack) * sizeof(xStack) << std::endl;

    std::cout << "In stack allocation, conting goes upward, for instance we have allocated 2 variable" << std::endl;
    std::cout << "xStack then xStack2 and their adress are"  << std::endl;
    std::cout << "Xstack: " << &xStack << std::endl << "xStack2: " << &xStack2 << std::endl;
    std::cout << "Address of Xstack2  - address of Xstack is (in bytes): " << (&xStack2 - &xStack) * sizeof(xStack) << std::endl;
    std::cout << "Should be positive so allocated updward" << std::endl;

    std::cout << "In heap allocation, conting goes upward, for instance we have allocated 2 variable" << std::endl;
    std::cout << "xHeap then xHeap2 and their adress are" << std::endl;
    std::cout << "xHeap: " << xHeap << std::endl << "xHeap2: " << xHeap2 << std::endl;
    std::cout << "Address of xheap2  - address of xheap is (in bytes): " << (xHeap2 - xHeap) * sizeof(xStack) << std::endl;
    std::cout << "Should be positive so allocated updward" << std::endl;
    delete xHeap;
    delete xHeap2;



    std::cout << std::endl  << "Lets do a speed test for reading with heap vs stack" << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();

    PerformanceTestStruct notptrStruc;
    
    notptrStruc.init();
    notptrStruc.AddToAll(5.5);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Not pointer time : " << duration << " microseconds" << std::endl;
    

    {
        auto start = std::chrono::high_resolution_clock::now();

        std::shared_ptr<PerformanceTestStruct> ptr_perfostruct = std::make_shared<PerformanceTestStruct>();
        ptr_perfostruct->init();
        ptr_perfostruct->AddToAll(5.5);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "For shared ptr :" << duration << " microseconds" << std::endl;
    }


    std::cout << std::endl << "Lets do a speed test for reading with reference vs value" << std::endl;

    {
        auto start = std::chrono::high_resolution_clock::now();
        
        int x_ptr = notptrStruc.justASmallInt;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "For not reference :" << duration << " nanoseconds" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        int &x_ptr = notptrStruc.justASmallInt;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "For reference :" << duration << " nanoseconds" << std::endl;
    }

    std::cout << "Lets try to load the whole object vs just pointing to it" << std::endl;


    {
        auto start = std::chrono::high_resolution_clock::now();

        PerformanceTestStruct new_struct = notptrStruc;
        int test = notptrStruc.justASmallInt;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "For value :" << duration << " nanoseconds" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();

        PerformanceTestStruct &new_struct = notptrStruc;
        int test = notptrStruc.justASmallInt;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "For reference :" << duration << " nanoseconds" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        PerformanceTestStruct* New_struct_ptr = &notptrStruc;
        int x_test = New_struct_ptr->justASmallInt;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "For ptr :" << duration << " nanoseconds" << std::endl;
    }
    
    // TO DO:
    // struct et class
    // perfomance : pointer vs non-pointer et heap vs stack
    // reference
    int in;
    std::cin >> in;
}
 /*
 NOTES:
 incrementation: quand faire ptr++,  augmente ladresse du selon le nb de byte du type
 ex. int *prt = x0003, fait ++ donne x0007 car 4 bytes dans int
 differentiation de pointer donne la


 The difference between two pointers means the number of elements of the type that would
 fit between the targets of the two pointers.
 */

