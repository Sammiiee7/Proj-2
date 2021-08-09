/* -----------------------------------------------------------------------
------
FILE NAME:         Matrix.h
DESCRIPTION:       Matrix Class Specification
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:
MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Samuel Ayeju      2018-04-30         1.0
Samuel Ayeju      2018-05-02         1.1 Added, Equality function and Transpose
Samuel Ayeju	  2018-05-03	     1.3 Tried to add determinant, but failed
--------------------------------------------------------------------------
--- */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
//#include <math.h>
using namespace std;
const char PROGRAMMER_NAME[] = "Samuel Ayeju"; // Global con

template <class T> 
class Matrix
{

	protected:
	  int rows;
	  int cols;
	  T **array;

       public:
	  Matrix();				//Default constructor
	  Matrix(int rows, int cols);		//Overloaded Constrcutor
	  Matrix(const Matrix<T>&);		// Copy Constructor
	  ~Matrix();				//Destructor
	  T get (int i, int j);		        // Accessor
	  void  set (int i, int j, T k);	//Mutator
	  void display();			//Accessor, for output

	template <class T1>
	friend ostream& operator << (ostream &, const Matrix<T1>&);
	template <class T1>
	friend istream& operator >> (istream &, Matrix<T1> &);
	
	Matrix<T>& operator = (const Matrix<T> &); 	//Overloaded assignment

};

template<class T>
class Matrix_ops : public Matrix<T>
{
 
 public: 
   	using Matrix<T> :: rows;
	using Matrix<T> :: cols;
	using Matrix<T> :: array;
	
	using Matrix<T> :: Matrix;
	using Matrix<T> :: operator=;

	Matrix_ops<T> operator + (const Matrix_ops<T> &); //Overloaded +
	Matrix_ops<T> operator - (const Matrix_ops<T> &); //Overloaded -
	Matrix_ops<T> operator * (const Matrix_ops<T> &); //Overloaded *
	bool operator ==(const Matrix_ops<T> &); //Overloaded Equality
	Matrix_ops<T> trans(); 
//	T Matrix_ops<T> det();
//      Matrix_ops<T> Matrix_ops<T> minor(int ro, int co);
};
#endif

