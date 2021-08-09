/* -----------------------------------------------------------------------
------
FILE NAME:         Matrix.cpp
DESCRIPTION:       Matrix Class Implementation
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:
MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Samuel Ayeju      2018-04-30         1.0
Samuel Ayeju      2018-05-02         1.0 Added, Equality and Transpose functions
--------------------------------------------------------------------------
--- */

#include "Matrix.h"

/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix<T>::Matrix()
DESCRIPTION:       Default Constructor Function
RETURNS:           Nothing
NOTES:
--------------------------------------------------------------------------
----- */
//Default Constructor
template<class T>
Matrix<T>::Matrix()
{
 	 rows = 0;
  	 cols = 0;
 
 	array = NULL;

	//cout<< "Default constructor: "<<rows << " X " << cols << endl;
}


/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix<T>::Matrix(int n_rows, int n_cols)
DESCRIPTION:       Overloaded Constructor Function
RETURNS: 	   Nothing
NOTES:
--------------------------------------------------------------------------
----- */

//Constructor
template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

  	array = new T*[rows];
  for (int i = 0; i < rows; i++)
 {
  	array[i] = new T[cols];
  for (int j = 0; j < cols; j++)
  array[i][j] = 0;
}


	//cout << "Matrix Constructor: ";
	cout << rows << " X " << cols << endl;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          T Matrix<T>::get(int i, int j)
DESCRIPTION:       Get Member  Function
RETURNS:	   array
NOTES:		   serves as an accessor 
--------------------------------------------------------------------------
----- */

//Accessor
template <class T>
T Matrix<T>::get(int i, int j)
{
	return array [i][j];
}

/* -----------------------------------------------------------------------
------
FUNCTION:          T Matrix<T>::set(int i, int j, T k)
DESCRIPTION:       Set Member  Function
RETURNS:           array
NOTES:             sets the array
--------------------------------------------------------------------------
----- */
// set
template <class T>
void Matrix<T>::set(int i, int j, T k)
{
	array[i][j] = k;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          ostream& operator << (ostream &out, const Matrix<T> &mat)
DESCRIPTION:       Overloaded output operator
RETURNS:	   out
NOTES:		   overloads the << operator to perform output.
--------------------------------------------------------------------------
----- */

// output operator
template <class T>
ostream& operator << (ostream &out, const Matrix<T> &mat)
{
	out << setw(6) << mat.rows << " X " << mat.cols << endl; 
	for (int i = 0; i < mat.rows; i++)
	{
	  for (int j = 0; j < mat.cols; j++)
	   {
//		out << setw(4) << mat.get (i, j);
		out << setw(4)<< mat.array[i][j];
	   }
	   out << endl;
	}
	out << endl;
	return out;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix<T>::~Matrix()
DESCRIPTION:       Destructor Function
RETURNS:	   Nothing
NOTES:		   Deletes the array
--------------------------------------------------------------------------
----- */

//destructor
template <class T>
Matrix<T>::~Matrix()
{
  for (int i=0; i < rows; i++)
  	delete [] array[i];

	delete array;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          istream& operator >> (istream& in, Matrix<T> &m1)
DESCRIPTION:       Overloaded input operator
RETURNS:	   in
NOTES:		   overloads the >> operator to do input
--------------------------------------------------------------------------
----- */

//Input operator
template <class T>
istream& operator >> (istream& in, Matrix<T> &m1) 
{
 	char let_x;
 	int m, n;

 	in >> m >> let_x >> n;
	Matrix<T>   mat(m, n);
 
 	//cout << "operator >> :" << endl;

   for (int i = 0; i < mat.rows; i++)
{
        for (int j = 0; j < mat.cols; j++)
     {
	in >> mat.array[i][j];
     }
}
  m1 = mat;
 return in;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix<T>::Matrix(const Matrix<T> &m)
DESCRIPTION:       Copy Constructor
RETURNS:	   Nothing
NOTES:		  Copies to the new matrix
--------------------------------------------------------------------------
----- */

// Copy constructor
template <class T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
  	rows = m.rows;
  	cols = m.cols;

 	array = new T * [rows];

	//cout << "Copy constructor: " << rows << " X " << cols << endl;

for (int i =0; i < rows; i++)
{
 	array[i] = new T [cols];
	 for (int j = 0; j < cols; j++)
 {
  	array[i][j] =m.array[i][j];
 }
}
}

/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m)
DESCRIPTION:       Overloaded Assignment Operator
RETURNS:	   *this
NOTES:		   overloads the = operator to perform assignment
--------------------------------------------------------------------------
----- */

// assignment 
template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m)
{
 	for (int i = 0; i < rows; i++)
	delete [] array[i];
	delete [] array;

 	rows = m.rows;
 	cols = m.cols;
 
 	array = new T * [rows];

 //cout << "Assignment op = : " << rows << " X " << cols << endl;
   
 	for (int i =0; i < rows; i++)
{
 	array [i] = new T [cols];
 	for (int j =0; j < cols; j++)
 {
    	array[i][j] = m.array[i][j];
}
}
 return *this;
}

/* -----------------------------------------------------------------------
------
FUNCTION:    Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> & mat)
DESCRIPTION:   Overloaded Addition Operator
RETURNS:       Result
NOTES:	      Overloads the + operator to Perform Addition
--------------------------------------------------------------------------
----- */

//Addition
template<class T>
Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> & mat)
{
  	if (rows != mat.rows || cols != mat.cols)
 {
   	cout << "Adition: Dimensions are Invalid" << endl;
   	Matrix_ops<T> result;
   	return result;
 }

  	Matrix_ops<T> result(rows, cols);
  	for (int i =0; i < rows; i++)
  	for (int j = 0; j < cols; j++)
  	result.array[i][j] = array[i][j] + mat.array[i][j];

  	return result; 
}

/* -----------------------------------------------------------------------
------
FUNCTION:   Matrix_ops<T> Matrix_ops<T>::operator -(const Matrix_ops<T> & mat)
DESCRIPTION:   Overloaded Subtraction Operator
RETURNS:       result
NOTES:       Overloads the - operator to do subtraction
--------------------------------------------------------------------------
----- */

//Subtraction
template<class T>
Matrix_ops<T> Matrix_ops<T>::operator -(const Matrix_ops<T> & mat)
{
  	if (rows != mat.rows || cols != mat.cols)
 {
   	cout << "Subtraction: Dimensions are Invalid" << endl;
   	Matrix_ops<T> result;
   	return result;
 }

  	Matrix_ops<T> result(rows, cols);
  	for (int i =0; i < rows; i++)
  	for (int j = 0; j < cols; j++)
  	result.array[i][j] = array[i][j] - mat.array[i][j];

return result;
}

/* -----------------------------------------------------------------------
------
FUNCTION:  Matrix_ops<T> Matrix_ops<T>::operator *(const Matrix_ops<T> & mat)
DESCRIPTION:  Overloaded Multiplication Operator
RETURNS:      result
NOTES:      Overloads the * operator to perform Multiplication
--------------------------------------------------------------------------
----- */

//Multiplication
template<class T>
Matrix_ops<T> Matrix_ops<T>::operator *(const Matrix_ops<T> & mat)
{
 int M, N, R;

 	if (rows != mat.rows || cols != mat.cols)
 {
  	cout << "Multiplication: Dimensions are Invalid" << endl;
  	Matrix_ops<T> r1;
  	return r1;
 }
  
 	M = rows;
 	N = cols;
 	R = mat.cols;

 	Matrix_ops<T> result(M, R);
 	for (int i =0; i < M; i++)
 	for (int j = 0; j < R; j++)
 	for (int k = 0; k < N; k++)
{
  	result.array[i][j] += array[i][k] * mat.array[k][j];
}
return result;
}

/* -----------------------------------------------------------------------
------
FUNCTION: bool Matrix_ops<T>::operator ==(const Matrix_ops<T> &mat)
DESCRIPTION:   Overloaded Equality Operator
RETURNS:       test
NOTES:        Overloads the == operator to do equality testing
--------------------------------------------------------------------------
----- */

//Equality
template<class T>
bool Matrix_ops<T>::operator ==(const Matrix_ops<T> &mat)
{
 int A , B;
 bool test = true;
 
 	if (rows != mat.rows || cols != mat.cols)
 {
  	cout << "Equality: Dimensions are invalid" << endl;
  	Matrix_ops<T> r1;
  	return false;
 }
 
 	A = rows;
 	B = cols;

 	for (int i = 0; i < A; i++)
 {
   	for (int j = 0; j < B; j++)
  {
    	if (mat.array[i][j] != array[i][j]) test = false;
  }
}
 return test;
}


/* -----------------------------------------------------------------------
------
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::trans()
DESCRIPTION:       Transpose Function
RETURNS:	   mat
NOTES:		Takes a Matrix and Transposes it.
--------------------------------------------------------------------------
----- */

//Transpose
template<class T>
Matrix_ops<T> Matrix_ops<T>::trans()
{
 	int M , N;
  	if (rows == 0 || cols == 0)
 {
  	cout << "Transposing: Dimensions are invalid" << endl;
  	Matrix_ops<T> r1;
  	return r1;
 }

 	M = rows;
 	N = cols;

 	Matrix_ops<T> mat(N,M);
 	for (int i = 0; i < rows; i++)
 {
    	for(int j = 0; j < cols; j++)
     	mat.array[j][i] = array[i][j];
 }
return mat;
}
/*
//determinant
template<class T>
T Matrix_ops<T>::det()
{
 	int p,N;
	T result = 0;
	if (rows != cols)
{
	cout << "Determinant: Dimensions are invalid" << endl;
	return result;
}
	N = cols;
	Matrix_ops<T> m1;

	if (N == 1)
	result = array[0][0];

	else if (N >= 2)
 {
	int i = 0;
	for (int j = 0; j < N; j++)
	{
	  if ((i+j)%2) p = -1;
	   else p = +1;
	 //m1 = this->minor(i,j);
	 result += p*array[i][j]*m1.det();
	}
 }
	else 
 	cout << "Cannot Perform Operation" << endl;
  return result;
}
*/

/*
//minor 
template<class T>
Matrix_ops<T> Matrix_ops<T>::minor(int ro, int co)
{
  int g, h;
  int N;

	if (rows != cols)
	{
	  cout << "Minor: Invalid Dimensions" << endl;
	  Matrix_ops<T> r1;
	  return r1;
	}

	N = cols -1;
	
	Matrix_ops<T> m1(N, N);
	
	for (int i = 0; i < N; i++)
	{
	  if (i < ro) g = i;
		else g = i+1;
	 for (int j = 0 ; j < N; j++)
	  {
	     if (j < co) h = j;
		else h = j+1;
	     m1.array[i][j] = array[g][h];
	  }
	}
   return m1;
}
*/




