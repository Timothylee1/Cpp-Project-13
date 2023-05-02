/*******************************************************************************
\File vct.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Vector Template Abstract Data Type
\Par Programming Assignment #7
\Date 15-03-2022

  \Brief
   The purpose of this laboratory is to understand how to build our own version
   of the most useful container in the standard library: std::vector<T>. A 
   std::vector<T> provides a sequence of elements of given type; you can refer
   to an element by its index; extend the std::vector<T> by using push_back; 
   ask a vector for the number of its elements using size, etc. Basically a 
   class template clone of the vector class template.

- vector
    Default constructor using initializer list to initialize the private 
    function members.

- vector
    Non-default constructor using initializer list to initialize the private 
    function members. Dynamically allocates memory for the data pointer.
    
- vector
    Non-default constructor using initializer list in the param (rhs) to 
    initialize the private function members. Dynamically allocates memory for 
    the data pointer and assigns the elements to contain the rhs list.
    
- vector
    Copy constructor, copies the contents and member objects from the param 
    object onto another.
    
- ~vector
    Destructor, invoked when function goes out of scope. deletes data.
    
- operator=
    Copy assignment operator, assigns this with the contents of the rhs param, 
    while incrementing the allocs member. Returns a dereferenced pointer to 
    this.
    
- operator=
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
        
- resize
    Resizes the container so that it contains newsize elements. If newsize is
    smaller than the current container size, the content is reduced to its 
    first newsize elements, removing those beyond (and destroying them). If 
    newsize is greater than the current container size, the content is expanded
    by inserting at the end as many elements as needed to reach a size of 
    newsize. If newsize is also greater than the current container capacity, 
    a reallocation of the allocated storage space takes place.

- pop_back
	Removes the last element of the container. Does nothing if the vector is 
	empty.

- swap
	Exchanges the contents of the container with those of other. Does not 
	invoke any move, copy, or swap operations on individual elements.
	
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
    Returns an iterator pointing to the first element in the vector. Note 
	that this is a overload const where the element cannot be modified.
    
- end
    Returns an iterator pointing to the past-the-end element in the vector. 
	Note that this is a overload const where the element cannot be modified.

- cbegin
    Returns a const_iterator pointing to the first element in the container.
    
- cend
    Returns a const_iterator pointing to the past-the-end element in the 
    container.
    
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#ifndef VCT_HPP
#define VCT_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int> 

namespace hlp2 {

template <typename T>
class vector {
public:
  // type definitions for value_type, size_type,
  // pointer, const_pointer, reference, const_reference
  using size_type       = size_t;
  using value_type      = T;
  using pointer         = value_type*;
  using const_pointer   = const value_type*;
  using reference       = value_type&;
  using const_reference = const value_type&;

  vector();

  vector(size_type n);

  vector(std::initializer_list<value_type> rhs);

  vector(vector const& rhs);

  ~vector();

  reference operator=(vector const& rhs);

  reference operator=(std::initializer_list<value_type> rhs);

  reference operator[](size_type index);

  const_reference operator[](size_type index) const;

  void push_back(value_type value);

  void resize(size_type newsize);

  void pop_back();

  void swap(vector& that);

  bool empty() const;

  size_type size() const;

  size_type capacity() const;

  size_type allocations() const;

  pointer begin();

  pointer end();

  const_pointer begin() const;

  const_pointer end() const;

  const_pointer cbegin() const;

  const_pointer cend() const;

private:
    size_type sz;     // the number of elements in the array
    size_type space;  // the allocated size (in terms of elements) of the array
    size_type allocs; // number of times space has been updated
    pointer   data;   // the dynamically allocated array
};

  
  /****************************************************************************/
  /*!
  \brief
    Default constructor using initializer list to initialize the private 
    function members.
  */
  /****************************************************************************/
  template <typename T> // default ctor
  vector<T>::vector() : sz{}, space{}, allocs{}, data{nullptr} {} 

  
  /****************************************************************************/
  /*!
  \brief
    Non-default constructor using initializer list to initialize the private 
    function members. Dynamically allocates memory for the data pointer.

  \param n
    The variable containing the value used in the initialization.
  */
  /****************************************************************************/
  template <typename T> // non-default ctor
  vector<T>::vector(size_type n) : sz{n}, space{n}, allocs{1} { 
      data = new value_type [space](); //() default value of 0 for each element
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
  template <typename T>
  vector<T>::vector(std::initializer_list<value_type> rhs) 
  : sz{rhs.size()}, space{rhs.size()}, allocs{1} { // non-default ctor
      data = new value_type [space]();
      size_type i{};
      for (value_type x : rhs) {
          data[i] = x; ++i;
      }
  }


  /****************************************************************************/
  /*!
  \brief
    Copy constructor, copies the contents and member objects from the param 
    object onto another.

  \param rhs
    A vector class template object containing the object to be copied.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  template <typename T>
  vector<T>::vector(vector const& rhs) // copy ctor
  : sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new value_type [space]} { 
      for(size_type i{}; i < space; ++i) {
          data[i] = rhs.data[i];
      }
  }


  /****************************************************************************/
  /*!
  \brief
    Destructor, invoked when function goes out of scope. deletes data.
  */
  /****************************************************************************/
  template <typename T>
  vector<T>::~vector() {  // deconstructor
      delete[] data;
  }


  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, assigns this with the contents of the rhs param, 
    while incrementing the allocs member. Returns a dereferenced pointer to 
    this.

  \param rhs
    A vector class template object containing the object to be copied.
	
  \param newdata
    A pointer to the vector class template object that copies the data from 
	rhs.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::reference vector<T>::operator=(vector const& rhs) {  
      pointer newdata {new value_type [rhs.space]};
      sz = rhs.sz;
      space = rhs.sz;
      ++allocs;
      for (size_type i{}; i < rhs.sz; ++i)
          newdata[i] = rhs.data[i];
      delete[] data;
      data = newdata;
      return *data; 
  }


  /****************************************************************************/
  /*!
  \brief
    Copy assignment operator, initilized this with the contents of the rhs 
    param, while incrementing the allocs member. Returns a dereferenced pointer 
    to this.

  \param rhs
    The initializer list containing int elements.

  \param newdata
    A pointer to the vector class template object that copies the data from 
	rhs.

  \param i
    Counter in the loop, to increment to the next element.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::reference 
  vector<T>::operator=(std::initializer_list<value_type> rhs) {
      pointer newdata = new value_type[rhs.size()];
      sz = rhs.size(); 
      space = rhs.size();
      ++allocs; 
      delete[] data;
      size_type i{};
      for (value_type x : rhs) {
          newdata[i] = x;
          ++i;
      }
      data = newdata;
      return *data;
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
  template <typename T>
  typename vector<T>::reference vector<T>::operator[](size_type index){
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
  template <typename T>
  typename vector<T>::const_reference 
  vector<T>::operator[](size_type index) const{
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
  template <typename T>
  void vector<T>::push_back(value_type value) {
      if (sz < space) {
          data[sz] = value;
          ++sz;
      }
      else {
          if (space == 0) {
              ++space;  ++allocs;
          } 
          else {
              space *= 2;  ++allocs;
          } 

          pointer newdata {new value_type [space]};
          for (size_type i{}; i < sz; ++i) {
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
  template <typename T>
  void vector<T>::resize(size_type newsize) {
      if (newsize <= sz || newsize <= space) {
          sz = newsize;
      }
      else {
          if (space*2 > newsize) {
              space*=2; ++allocs;
          }
          else {
              space = newsize; ++allocs;
          }
          
          pointer newdata = new value_type[space];
          for (size_type i{}; i < sz; ++i) {
              newdata[i] = data[i];
          }
          sz = newsize;
          delete[] data;
          data = newdata;
      }
  }


  /****************************************************************************/
  /*!
  \brief
    Removes the last element of the container. Does nothing if the vector is 
	empty.
  */
  /****************************************************************************/
  template <typename T>
  void vector<T>::pop_back() { if(empty()) return;  --sz; }


  /****************************************************************************/
  /*!
  \brief
    Exchanges the contents of the container with those of other. Does not 
	invoke any move, copy, or swap operations on individual elements.

  \param that
    Reference to a vector class object.

  \param tmp_data
    Pointer to a temporary vector<T> that copies data.

  \param tmp_sz
    Assigned the value of sz for swapping.

  \param tmp_space
    Assigned the value of space for swapping.

  \param tmp_allocs
    Assigned the value of allocs for swapping.
  */
  /****************************************************************************/
  template <typename T>
  void vector<T>::swap(vector& that) {
      pointer tmp_data = data;
      size_type tmp_sz = sz;
      size_type tmp_space = space;
      size_type tmp_allocs = allocs;

      //no need delete[] as it overwrites the pointer and calls ~dector
      data = that.data; 
      sz = that.sz;
      space = that.space;
      allocs = that.allocs;

      that.data = tmp_data;
      that.sz = tmp_sz;
      that.space = tmp_space;
      that.allocs = tmp_allocs;
  }


  /****************************************************************************/
  /*!
  \brief
    Returns whether the vector is empty (i.e. whether its size is 0).
  */
  /****************************************************************************/
  template <typename T>
  bool vector<T>::empty() const { return sz == 0; }


  /****************************************************************************/
  /*!
  \brief
    Returns the number of elements in the vector.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::size_type vector<T>::size() const { return sz; }


  /****************************************************************************/
  /*!
  \brief
    Returns the size of the storage space currently allocated for the vector,
    expressed in terms of elements.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::size_type vector<T>::capacity() const { return space; }


  /****************************************************************************/
  /*!
  \brief
    Returns the allocations made to obtain the vector.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::size_type 
  vector<T>::allocations() const { return allocs; }


  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::pointer vector<T>::begin() { return data; }


  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::pointer vector<T>::end() { return data+sz; }


  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the first element in the vector. Note that 
    this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::const_pointer vector<T>::begin() const { return data; }


  /****************************************************************************/
  /*!
  \brief
    Returns an iterator pointing to the past-the-end element in the vector. Note 
    that this is a overload const where the element cannot be modified.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::const_pointer vector<T>::end() const { return data+sz; }


  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the first element in the container.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::const_pointer vector<T>::cbegin() const { return data; }


  /****************************************************************************/
  /*!
  \brief
    Returns a const_iterator pointing to the past-the-end element in the 
    container.
  */
  /****************************************************************************/
  template <typename T>
  typename vector<T>::const_pointer vector<T>::cend() const { return data+sz; }

} // namespace hlp2

#endif // VCT_HPP
