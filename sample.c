#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                
#define BUFSIZE 256
                                
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
      fprintf(stderr, "Please provide the address of a file as an input.\n");
      return -1;
    }
    //get the value of the argv[1] - the second argument in the command line arguments
    char* filename = argv[1];
    //check to see if the file exists and valid and can be accessed before sending to the system command
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
      fprintf(stderr, "The file %s does not exist or cannot be accessed.\n", filename);
      return -1;
    }
    //close the file gracefully
    if (fclose(fp) != 0) {
      fprintf(stderr, "Failed to close the file %s.\n", filename);
      return -1;
    }
    //perform the system command witht eh valid system info
    char cmd[BUFSIZE] = "wc -c < ";
    strncat(cmd, filename, BUFSIZ);
    system(cmd);
    return 0;
}
