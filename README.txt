Author : Arjun Khurana
Professor : Dr. Nhut Nguyen
Class : CS3377.OW1
Date : 4 March 2019

DOCUMENTATION FOR FILECNT AND FILEDISP PROGRAMS
-----------------------------------------------

Filecnt
-------
1. The program takes as argument the absolute or relative path (also supports ~ expansion, etc.) of a directory
2. The program ensures that exactly one argument was passed, then makes a call to ftw()
3. Uses ftw(), which is a gnu functon for recursively exploring a directory (implicitly supports ~ expansion, relative pathnames, etc.)
	a. References used: 
		i. https://www.gnu.org/software/libc/manual/html_node/Working-with-Directory-Trees.html
		ii. http://praxis.edoceo.com/man/3/ftw
	b. ftw() function has the form: int ftw(const char* dirpath, int (*fn) (const char *fpath, const struct stat *sb, int typeflag),  int nopenfd)
		i. const char* dirpath : this is the path of the directory where ftw() will begin
		ii. int (*fn) (const char *fpath, const struct stat *sb, int typeflag) : this is a pointer to the count function, which is detailed below
		iii. int nopenfd : unused in this program
		iv. the return value of ftw() indicates whether the function executed successfully, i.e. if it is 0, then success, else failure
	c. ftw() function recursively calls the count() function with each pathname within the original directory, and count() processes the pathname
4. Uses count(), which is a user defined function that interfaces with ftw()
	a. count() has the form count(const char* path, const struct stat* statptr, int flag)
		i. cont char* path : name of the current path being processed, passed from ftw()
		ii. const struct stat* statptr : a struct defined in ftw() which holds statistics on the file or directory described by path
		iii. int flag : variable which is passed from ftw(), which indicates to the count() function how to process the current path
	b. count() processes the flag using a switch on the flag variable
		i. if there are no statistics available on a given path, an error message is printed
		ii. if the given path is an unreadable directory (permissions denied), an error message is printed
		iii. else, if the flag is a valid directory or file, the appropriate values are incremented and the function returns
5. If ftw() executed successfully, the program prints to standard output lines of text which specify the number of files and directories, and the total number
	of bytes in all the files in the passed directory

Filedisp
--------
1. The program takes as argument a series of options in the form (-*)
2. If there is no option supplied, then the program prints an error
3. Else, the program reads three lines from standard input, a directory line, a file line, and a byte line
	a. Note that these lines are designed to synchronize with the standard output of filecnt, i.e. the stdout of filecnt should be piped to filedisp
4. Uses getopt(), which is a gnu function for processing option arguments to a C program
	a. References used:
		i. http://man7.org/linux/man-pages/man3/getopt.3.html
	b.  getopt() has the form: int getopt(int argc, char * const argv[], const char *optstring)
		i. int argc : the same argument count which is passed into main()
		ii. char * const argv[] : the same argument vector which is passed into main()
		iii. const char *optstring : an array of chars which specify the valid options which getopt() should process
		iv. the return value of getopt() indicates whether the function executed successfully : if the return is -1, then something failed
5. The program iterates over the options using getopt() while the return code is not -1, and processes the options
	a. if the option code is 'd', then print the directory line
	b. if the option code is 'f', then print the file line
	c. if the option code is 'b', then print the byte line
	d. else, print an error message 
	