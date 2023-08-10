//==============================================
// Name:           Lebna Noori
// Student Number: 157672205
// Email:          lnoori1@myseneca.ca
// Section:        NAA
// I have done all the coding by myself and only copied the code that my professor provided 
// to complete my workshops and assignments.
//==============================================

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace sdds
{
    /// <summary>
    /// operator == must be defined 
    /// uses Collection.h to access the templates
    // since Collection itself uses templates that use the car/student/employee
    // classes. The int num to track the number of items does not need to be
    // a template item since that is constant throughout cases. The key value
    // is unique in each class so passing the key as a template object was also
    // nessecary
    /// </summary>
    /// <typeparam name="T1"></typeparam>
    /// <typeparam name="T2"></typeparam>
    /// <param name="item"></param>
    /// <param name="arr"></param>
    /// <param name="num"></param>
    /// <param name="key"></param>
    /// <returns></returns>

    template <typename T1, typename T2>
    bool search(Collection<T1>& item, const T1* arr, int num, T2 key) {
        int i = 0;
        bool result = false;

        for (i = 0; i < num; i++)
        {
            if (arr[i] == key)
            {
                item.add(arr[i]);
                result = true;
            }
        }
        return result;
    }

    
  
    /// <summary>
    /// operator << must be defined 
    /// The list array elements function recieves different types of arrays.
    /// Since there are multiple types of arrays to be recieved and work with
    /// our template function. Using our abstract class, we use the insert operator
    /// deifned in ReadWrite to acess our Car/Employee/Student classes since the
    /// classes we work in all inherit from ReadWrite.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="title"></param>
    /// <param name="arr"></param>
    /// <param name="num"></param>
    template <typename T>
    void listArrayElements(const char* title, const T* arr, int num) 
    {
        int i = 0;
        cout << title << endl;

        for (i = 0; i < num; i++)
        {
            cout << (i + 1) << ": ";
            cout << arr[i] << endl;
        }
    }
}

#endif // !SDDS_SEARCHNLIST_H_ 


