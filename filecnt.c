//header files for glibc functions ftw(), and std io
#include <ftw.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>

//global variables to hold the values to be outputted, accessed both from main() and count()
uintmax_t filecount = 0;
uintmax_t dircount = 0;
uintmax_t bytecount = 0;

//function header for count(), follows the format specified by ftw()
int count(const char* path, const struct stat* statptr, int flag);

int main(int argc, char *argv[])
{
	//if the number of arguments passed is 0 (just the name of the executable is passed, no additional arguments)
	if (argc == 1)
	{
		//print an error and return error value
		printf("One argument expected\n"); 
		return 1;
	}
	//else if there is more than one argument passed
	else if (argc > 2)
	{
		printf("Too many arguments\n"); //print an error and return error value
		return 1;
	}

	//initializing const variable for the path name
	const char* path = argv[1];

	if(!ftw(path, count, 1024)) //recursively calls ftw() function with each path, while the return code is 0 from count()
	{
		//prints the correct information
		printf("The total number of directories in directory %s is: %ld\n", path, dircount);
		printf("The total number of files in directory %s is: %ld\n", path, filecount);
		printf("The total number of bytes occupied by all files in directory %s is: %ld\n", path, bytecount);
	}
	else //if the return code from count() is nonzero, return an unexpected value
	{
		return 1;
	}

	//program is finished
	return 0;	
}


//count function header is specified by the ftw() function, it incremements the appropriate values given the flag and stats for each element
//in the directory which is passed to the program
int count(const char* path, const struct stat* statptr, int flag)
{
	switch(flag) //switch on the flag value
	{
		case FTW_NS: //error case for no stats on a file
			printf("No stats for %s\n", path);
			return 1;
			break;
		case FTW_DNR: //error case for unreadable directory
			printf("%s is not a readable directory\n", path);
			return 1;
			break;
		case FTW_F: //case for file, increment file count, increment bytes
			filecount++;
			bytecount += statptr->st_size;
			break;
		case FTW_D: //case for directory, increment directory count
			dircount++;
			break;
		default:
			break;
	}
	return 0;
}