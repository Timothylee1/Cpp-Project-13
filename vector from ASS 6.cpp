/******************************************************************************
\File vector.cpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: vector Abstract Data Type
\Par Programming Assignment #6
\Date 03-03-2022

  \Brief
   The purpose of this laboratory is to understand how to build our own version
   of the most useful container in the standard library: std::vector. A 
   std::vector provides a sequence of elements of a given type; you can refer 
   to an element by its index; extend the std::vector by using push_back; ask a
   vector for the number of its elements using size; and have access to the 
   std::vector checked against attempts to access out-of-range element. 
   std::vector is a convenient, flexible, and an efficient [in both time and 
   space] container of elements. Basically a simple vector class 
   implementation.


- vector()
    Default constructor using initializer list to initialize the private 
    function members.

- vector(size_t)
    Non-default constructor using initializer list to initialize the private 
    function members. Dynamically allocates memory for the data pointer.
    
- vector(initilizer_list)
    Non-default constructor using initializer list in the param (rhs) to 
    initialize the private function members. Dynamically allocates memory for 
    the data pointer and assigns the elements to contain the rhs list.
    
- vector(vector)
    Copy constructor, copies the contents and member objects from the param 
    object onto another.
    
- ~vector()
    Destructor, invoked when function goes out of scope. deletes data.
    
- operator=(vector)
    Copy assignment operator, assigns this with the contents of the rhs param, 
    while incrementing the allocs member. Returns a dereferenced pointer to 
    this.
    
- operator=(initilizer_list)
    Copy assignment operator, initilized this with the contents of the rhs 
    param, while incrementing the allocs member. Returns a dereferenced pointer 
    to this.
    
- operator[]
    Subscript operator that returns a dereferenced pointer to the element 
    in the index param.
    
- operator[]
    Subscript operator that returns a dereferenced pointer to the element 
    in the index param. Note that this is a overload const where the element
    cannot be modified.
        
- push_back
    Adds a new element at the end of the vector, after its current last 
    element. The content of value is moved to the new element. If the vector's
    capacity is not enough, the new vector will be allocated and the old will 
    be deleted.
        
- reserve
    Requests that the vector capacity be at least enough to contain newsize 
    elements. If newsize is greater than the current vector capacity, the 
    function causes the container to reallocate its storage increasing its 
    capacity to newsize (or greater). In all other cases, the function call 
    does not cause a reallocation and the vector capacity is not affected.
        
- resize
    Resizes the container so that it contains newsize elements. If newsize is
    smaller than the current container size, the content is reduced to its 
    first newsize elements, removing those beyond (and destroying them). If 
    newsize is greater than the current container size, the content is expanded
    by inserting at the end as many elements as needed to reach a size of 
    newsize. If newsize is also greater than the current container capacity, 
    a reallocation of the allocated storage space takes place.

- empty
    Returns whether the vector is empty (i.e. whether its size is 0).

- size
    Returns the number of elements in the vector.

- capacity
    Returns the size of the storage space currently allocated for the vector,
    expressed in terms of elements.
    
- allocations
    Returns the allocations made to obtain the vector.

- begin
    Returns an iterator pointing to the first element in the vector.

- end
    Returns an iterator pointing to the past-the-end element in the vector.

- begin
    Returns an iterator pointing to the first element in the vector. Note that 
    this is a overload const where the element cannot be modified.
    
- end
    Returns an iterator pointing to the past-the-end element in the vector. Note 
    that this is a overload const where the element cannot be modified.

- cbegin
    Returns a const_iterator pointing to the first element in the container.
    
- cend
    Returns a const_iterator pointing to the past-the-end element in the 
    container.
    
******************************************************************************/

#include "vector.hpp"

namespace hlp2 {
  
  /****************************************************************************/
  /*!
  \brief
    Default constructor using initializer list to initialize the private 
    function members.
  */
  /****************************************************************************/
  vector::vector() : sz{}, space{}, allocs{}, data{nullptr} {} // default ctor

  
  /****************************************************************************/
  /*!
  \brief
    Non-default constructor using initializer list to initialize the private 
    function members. Dynamically allocates memory for the data pointer.

  \param n
    The variable containing the value used in the initialization.
  */
  /****************************************************************************/
  vector::vector(size_t n) : sz{n}, space{n}, allocs{1} { // non-default ctor
    data = new int [space](); // () default value of 0 for each element
  }
  

  /****************************************************************************/
  /*!
  \brief
    Non-default constructor using initializer list in the param (rhs) to 
    initialize the private function members. Dynamically allocates memory for 
    the data pointer and assigns the elements to contain the rhs list.

  \param rhs
    The initializer list containing int elements.

  \param i
    Counter in the loop, to increment to the next element.
    
  \param x
    For the range-based loop using the initializer list where x is assigned the 
    int object in the list.
  */
  /****************************************************************************/
  vector::vector(std::initializer_list<int> rhs) 
  : sz{rhs.size()}, space{rhs.size()}, allocs{1} { // non-default ctor
    data = new int [space]();
    int i{};
    for (int x : rhs) {
        data[i] = x; i++;
    }
  }
  

  /****************************************************************************/
  /*!
  \brief
    Copy constructor, copies the contents and member objects from the param 
    object onto another.

  \param rhs
    A vector class object containing the object to be copied.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  vector::vector(vector const& rhs) 
  : sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new int [space]} { // copy ctor
    for(size_type i{}; i < space; i++) {
        data[i] = rhs.data[i];
    }
  }
  

  /****************************************************************************/
  /*!
  \brief
    Destructor, invoked when function goes out of scope. deletes data.
  */
  /****************************************************************************/
  vector::~vector() {  // deconstructor
    delete[] data;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, assigns this with the contents of the rhs param, 
    while incrementing the allocs member. Returns a dereferenced pointer to 
    this.

  \param rhs
    A vector class object containing the object to be copied.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  vector& vector::operator=(vector const& rhs) {
/*       this->sz = rhs.sz;
      this->space = rhs.sz;
      this->allocs++;
      for (size_type i{}; i < rhs.sz; i++)
        this->data[i] = rhs.data[i];
      return *this;  */

      int *newdata {new int [rhs.sz]};
      sz = rhs.sz;
      space = rhs.sz;
      allocs++;
      for (size_type i{}; i < rhs.sz; i++)
        newdata[i] = rhs.data[i];
      delete[] data;
      data = newdata;
      return *this; 
  }
  

  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, initilized this with the contents of the rhs 
    param, while incrementing the allocs member. Returns a dereferenced pointer 
    to this.

  \param rhs
    The initializer list containing int elements.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  vector& vector::operator=(std::initializer_list<int> rhs) {
      this->sz = rhs.size(); 
      this->space = rhs.size();
      (this->allocs)++; 
      delete[] this->data;
      this->data = new int [this->space];
      size_type i{};
      for (int x : rhs) {
          this->data[i] = x;
          i++;
      }
      return *this;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Subscript operator that returns a dereferenced pointer to the element 
    in the index param.

  \param index
    Refers to the index of the subscript operator; the element.
  */
  /****************************************************************************/
  vector::reference vector::operator[](size_type index){
    return *(data+index);
  }
  

  /****************************************************************************/
  /*!
  \brief
    Subscript operator that returns a dereferenced pointer to the element 
    in the index param. Note that this is a overload const where the element
    cannot be modified.

  \param index
    Refers to the index of the subscript operator; the element.
  */
  /****************************************************************************/
  vector::const_reference vector::operator[](size_type index) const{
    return *(data+index);
  }
  

  /****************************************************************************/
  /*!
  \brief
    Adds a new element at the end of the vector, after its current last 
    element. The content of value is moved to the new element. If the vector's
    capacity is not enough, the new vector will be allocated and the old will 
    be deleted.

  \param value
    The content of the new element.

  \param i
    Counter in the loop, to increment to the next element.

  \param newdata
    Pointer to the newdata vector.
  */
  /****************************************************************************/
  void vector::push_back(value_type value) {
    if (sz < space) {
      data[sz] = value;
      ++sz;
    }
    else {
      if (space == 0) {
        space++;  ++allocs;
      } 
      else {
        space *= 2;  ++allocs;
      } 

      pointer newdata {new int [space]};
      for (size_t i{}; i < sz; ++i) {
        newdata[i] = data[i];
      }
      newdata[sz] = value;
      ++sz; 
      delete[] data;
      data = newdata;
    }
  }
  

  /****************************************************************************/
  /*!
  \brief
    Requests that the vector capacity be at least enough to contain newsize 
    elements. If newsize is greater than the current vector capacity, the 
    function causes the container to reallocate its storage increasing its 
    capacity to newsize (or greater). In all other cases, the function call 
    does not cause a reallocation and the vector capacity is not affected.

  \param newsize
    The new capacity of the vector.

  \param i
    Counter in the loop, to increment to the next element.

  \param newdata
    Pointer to the newdata vector.
  */
  /****************************************************************************/
  void vector::reserve(size_type newsize) {
    if (newsize < space) {
      //nothing by design as capacity is larger
      //than newsize reserve
    }
    else {
      pointer newdata {new int [newsize]};
      size_t i{};
      for (; i < space; ++i) {
          newdata[i] = data[i];
      }
      sz = i;
      space = newsize;
      delete[] data;
      data = newdata;
      ++allocs;
    }
  }
  

  /****************************************************************************/
  /*!
  \brief
    Resizes the container so that it contains newsize elements. If newsize is
    smaller than the current container size, the content is reduced to its 
    first newsize elements, removing those beyond (and destroying them). If 
    newsize is greater than the current container size, the content is expanded
    by inserting at the end as many elements as needed to reach a size of 
    newsize. If newsize is also greater than the current container capacity, 
    a reallocation of the allocated storage space takes place.

  \param newsize
    The new size of the vector, not the capacity, unless it happens to be.

  \param i
    Counter in the loop, to increment to the next element.

  \param newdata
    Pointer to the newdata vector.
  */
  /****************************************************************************/
  void vector::resize(size_type newsize) {
    if (newsize < sz) {
      sz = newsize;
      pointer newdata {new int [space]};
      for (size_t i{}; i < sz; ++i) {
          newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
    }
    else if (newsize > sz) {
      if (newsize > space) {
        pointer newdata {new int [newsize]};
        for (size_type i{}; i <= newsize; i++) {
          i > sz ? newdata[i] = 0 : newdata[i] = data[i];
        }
        sz = newsize;
        space = newsize; //hmm
        delete[] data;
        data = newdata;
      } 
      else { //newsize < space
        for (size_type i{sz+1}; i <= newsize; i++) {
          data[i] = 0;
        }
        sz = newsize;
      }
    }
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns whether the vector is empty (i.e. whether its size is 0).
  */
  /****************************************************************************/
  bool vector::empty() const { // is container empty?
    return sz == 0;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns the number of elements in the vector.
  */
  /****************************************************************************/
  vector::size_type vector::size() const { // what is sz?
    return sz;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns the size of the storage space currently allocated for the vector,
    expressed in terms of elements.
  */
  /****************************************************************************/
  vector::size_type vector::capacity() const { // what is space?
    return space;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns the allocations made to obtain the vector.
  */
  /****************************************************************************/
  vector::size_type vector::allocations() const { // how many allocations or "growths"?
    return allocs;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector.
  */
  /****************************************************************************/
  vector::pointer vector::begin() { // pointer to first element
    return data;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector.
  */
  /****************************************************************************/
  vector::pointer vector::end() { // pointer to one past last element
    return data+sz;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector. Note that 
    this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  vector::const_pointer vector::begin() const { 
    return data;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector. Note 
    that this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  vector::const_pointer vector::end() const { 
    return data+sz;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the first element in the container.
  */
  /****************************************************************************/
  vector::const_pointer vector::cbegin() const{ 
    return data;
  }
  

  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the past-the-end element in the 
    container.
  */
  /****************************************************************************/
  vector::const_pointer vector::cend() const { 
    return data+sz;
  }
}
