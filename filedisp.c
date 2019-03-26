//header files for getopt() function, and std io
#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[])
{
	if (argc == 1) //if there is no option passed, print an error and return 
	{	
		printf("expected an option\n");
		return 1;
	}
	
	//initializing values for 3 getline() function calls
	char* dirline = NULL;
	char* fileline = NULL;
	char* byteline = NULL;
	size_t dirline_n, fileline_n, byteline_n;
	getline(&dirline, &dirline_n, stdin);
	getline(&fileline, &fileline_n, stdin);
	getline(&byteline, &byteline_n, stdin);

	//initializing a const array of valid option characters
	const char opt[3] = {'d', 'f', 'b'};
	
	//extern char* optarg;
	//extern int  optind;

	//declaring a switch variable
	char c;

	//iterating using getopt() through the option arguments passed to the program, while the return code for getopt() is not -1 (indicating failure)
	while ((c = getopt(argc, argv, opt)) != -1)
	{
		switch(c) //switching on the option character
		{
			case 'd':
				printf("%s", dirline); //if -d is passed, print the directory line
				break;
			case 'f':
				printf("%s", fileline); //if -f is passed, print the file line
				break;
			case 'b':
				printf("%s", byteline); //if -b is passed, print the byte line
				break;
			default:
				printf("invalid option passed\n"); //if an invalid option is passed, print an error and return an unexpected value
				return 1;
				break;
		}
	}

	//program is finished
	return 0;
}