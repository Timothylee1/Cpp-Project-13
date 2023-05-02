/******************************************************************************
\File vector.hpp
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

////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int> 

namespace hlp2 {
	
class vector {
public:
  // type definitions for value_type, size_type,
  // pointer, const_pointer, reference, const_reference
  using size_type       = size_t;
  using value_type      = int;
  using pointer         = value_type*;
  using const_pointer   = const value_type*;
  using reference       = value_type&;
  using const_reference = const value_type&;

public:
  
  /****************************************************************************/
  /*!
  \brief
    Default constructor using initializer list to initialize the private 
    function members.
  */
  /****************************************************************************/
  vector(); // default ctor

  
  /****************************************************************************/
  /*!
  \brief
    Non-default constructor using initializer list to initialize the private 
    function members. Dynamically allocates memory for the data pointer.

  \param n
    The variable containing the value used in the initialization.
  */
  /****************************************************************************/
  explicit vector(size_type n); // non-default ctor
  

  /****************************************************************************/
  /*!
  \brief
    Non-default constructor using initializer list in the param (rhs) to 
    initialize the private function members. Dynamically allocates memory for 
    the data pointer and assigns the elements to contain the rhs list.

  \param rhs
    The initializer list containing int elements. 
  */
  /****************************************************************************/
  vector(std::initializer_list<int> rhs); // non-default ctor
  

  /****************************************************************************/
  /*!
  \brief
    Copy constructor, copies the contents and member objects from the param 
    object onto another.

  \param rhs
    A vector class object containing the object to be copied. 
  */
  /****************************************************************************/
  vector(vector const& rhs); // copy ctor
  

  /****************************************************************************/
  /*!
  \brief
    Destructor, invoked when function goes out of scope. deletes data.
  */
  /****************************************************************************/
  ~vector();  // deconstructor

  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, assigns this with the contents of the rhs param, 
    while incrementing the allocs member. Returns a dereferenced pointer to 
    this.

  \param rhs
    A vector class object containing the object to be copied. 
  */
  /****************************************************************************/
  vector& operator=(vector const&);
  

  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, initilized this with the contents of the rhs 
    param, while incrementing the allocs member. Returns a dereferenced pointer 
    to this.

  \param rhs
    The initializer list containing int elements. 
  */
  /****************************************************************************/
  vector& operator=(std::initializer_list<int> rhs);
  

  /****************************************************************************/
  /*!
  \brief
    Subscript operator that returns a dereferenced pointer to the element 
    in the index param.

  \param index
    Refers to the index of the subscript operator; the element.
  */
  /****************************************************************************/
  reference operator[](size_type index);
  

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
  const_reference operator[](size_type index) const;
 

  /****************************************************************************/
  /*!
  \brief
    Adds a new element at the end of the vector, after its current last 
    element. The content of value is moved to the new element. If the vector's
    capacity is not enough, the new vector will be allocated and the old will 
    be deleted.

  \param value
    The content of the new element. 
  */
  /****************************************************************************/
  void push_back(value_type value);
  

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
  */
  /****************************************************************************/
  void reserve(size_type newsize);
  

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
  */
  /****************************************************************************/
  void resize(size_type newsize);
   

  /****************************************************************************/
  /*!
  \brief
    Returns whether the vector is empty (i.e. whether its size is 0).
  */
  /****************************************************************************/
  bool empty() const; // is container empty?
  

  /****************************************************************************/
  /*!
  \brief
    Returns the number of elements in the vector.
  */
  /****************************************************************************/
  size_type size() const; // what is sz?
  

  /****************************************************************************/
  /*!
  \brief
    Returns the size of the storage space currently allocated for the vector,
    expressed in terms of elements.
  */
  /****************************************************************************/
  size_type capacity() const; // what is space?
  

  /****************************************************************************/
  /*!
  \brief
    Returns the allocations made to obtain the vector.
  */
  /****************************************************************************/
  size_type allocations() const; // how many allocations or "growths"?
	 

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector.
  */
  /****************************************************************************/
  pointer begin(); // pointer to first element
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector.
  */
  /****************************************************************************/
  pointer end(); // pointer to one past last element
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector. Note that 
    this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  const_pointer begin() const;
  

  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector. Note 
    that this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  const_pointer end() const;
  

  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the first element in the container.
  */
  /****************************************************************************/
  const_pointer cbegin() const;
  

  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the past-the-end element in the 
    container.
  */
  /****************************************************************************/
  const_pointer cend() const;

private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array
};

} // namespace hlp2

#endif // VECTOR_HPP
