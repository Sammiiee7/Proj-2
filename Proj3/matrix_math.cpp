/* -----------------------------------------------------------------------
------
FILE NAME:         matrix_math.cpp
DESCRIPTION:       Matrix Class Driver
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:
MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Samuel Ayeju      2018-04-30         1.0
Samuel Ayeju      2018-05-02         1.1 Added Help and arg_count functions
--------------------------------------------------------------------------
--- */


#include "Matrix.cpp"  // Implementation file, needs to be compiled together
#include <cstdlib>
using namespace std;


int read_matrix(ifstream &infile, char *argv[], int & error);
int write_matrix(ofstream &outfile, char *agrv[], int &error);
int arg_count(int argc, int num, int & error);
void help();

/* -----------------------------------------------------------------------
------
FUNCTION:          main()
DESCRIPTION:       main function, responsible for driving the function
RETURNS:           0
NOTES:
--------------------------------------------------------------------------
----- */
int main (int argc, char *argv[])
{

 int error = 0;
 char file1[20] = "";
 ifstream fin1, fin2;
 ofstream fout;
 string cmd;
 Matrix_ops<double> mat1, mat2, mat3;
// Matrix_ops<double> mat4;
//double num;

 while (--argc)
 {
	cmd = *++argv;
 	
	if (cmd == "-h")
 {
  	help();
 }

//if statement handles files with one input
if (cmd == "-inp" ||cmd == "-T" ||cmd == "-1" ||cmd == "-det" ||cmd == "-solve")
{
  	if (arg_count (--argc, 1, error))return error;
  	read_matrix(fin1, ++argv, error);
	if (error) return error;
 	fin1 >> mat1;
}
 	if (cmd == "-out")
{
 	if (arg_count(--argc, 1, error)) return error;
 	write_matrix(fout, ++argv, error);
 	if (error)return error;
 	mat3 = mat1;
}

//if statement handles files with 2 inputs
 if (cmd == "-add" || cmd == "-sub" || cmd == "-mul" || cmd == "-eq")
 {
  	if (arg_count(--argc, 2, error)) return error;
   	read_matrix(fin1, ++argv, error);
  	read_matrix(fin2, ++argv, error);
 	--argc;
 	if (error) return error;
 	fin1 >> mat1;
 	fin2 >> mat2;
}


	if (cmd == "-add")
{
 	cout << "Addition: " << endl;
 	mat3 = mat1 + mat2;
}
	if (cmd == "-sub")
{
 	cout << "Subtraction: " << endl;
 	mat3 = mat1 - mat2;
}

	if (cmd == "-mul")
{
 	cout << "Multiplication: " << endl;
 	mat3 = mat1 + mat2;
}

	if (cmd == "-eq")
{
 	cout << "Equality: " << endl;
 	if (mat1 == mat2)
 	cout << "The Matrices are Equal" << endl;
 	else
 	cout << "The Matrices are not Equal" << endl;
}

	if (cmd == "-T")
{
	cout << "Transposing....." << endl;
	mat3 = mat1.trans();
}

}

	cout << "Input 1: mat1" << endl;
	cout << mat1;
	cout << "Input 2: mat2" << endl;
	cout << mat2;
	cout << "Results: mat3" << endl;
	cout << mat3;


	if (file1) 
{
	 fout << mat3;
	fout.close();
}

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	return 0;  
}

 
/* -----------------------------------------------------------------------
------
FUNCTION:    int read_matrix(ifstream &fin, char *argv[], int & error)
DESCRIPTION:     Read Matrix Function
RETURNS:         error
NOTES:      Ensures that file to be read from is properly opened
--------------------------------------------------------------------------
----- */
int read_matrix(ifstream &fin, char *argv[], int & error)
{

 char file1[20];
 

 strcpy(file1, argv[0]);
 strcat(file1, ".mtx");

 fin.open(file1);

	if (!fin)
{
 	cout << "\nError opening file: " << file1 << "\n\n";
 	error = 2;
}

return error;
}

/* -----------------------------------------------------------------------
------
FUNCTION:     int write_matrix(ofstream &fout, char *argv[], int &error)
DESCRIPTION:    write marix function
RETURNS:        error
NOTES:        Ensures that the file to be written to is properly opened
--------------------------------------------------------------------------
----- */
int write_matrix(ofstream &fout, char *argv[], int &error)
{
 char file1[20];
 strcpy(file1, argv[0]);
 strcat(file1, ".mtx");

 fout.open(file1);

 if (!fout)
 {
  cout << "\Error opening file: " << file1 << "\n\n";
  error = 2;
 }
return error;
}

/* -----------------------------------------------------------------------
------
FUNCTION:          int arg_count(int argc, int num, int & error)
DESCRIPTION:       Argument counter function
RETURNS:           error
NOTES:             Keeps track of the arguments
--------------------------------------------------------------------------
----- */
//argument tracker
int arg_count(int argc, int num, int & error)
{

 if (argc < num)
 {
  cout << "Not enough Arguments ?\n\n";
  error = 1;
 }
 return error;
 }

/* -----------------------------------------------------------------------
------
FUNCTION:          help()
DESCRIPTION:       Help function, Displays a help screen
RETURNS:           Nothing
NOTES:
--------------------------------------------------------------------------
----- */
void help()
{
  cout << "You need help so you came here, Please pay attention " << endl;
  cout << " -h for help\n" " -inp for reading input\n" "-out for output\n"
  " -add for addition\n" " -sub for subtraction\n" " -mul for multiplication\n"   " -eq for equality testing\n" " -T for Transposing\n" " -1 for inverse\n"
  " -solve for solving a system of equations\n";
}

