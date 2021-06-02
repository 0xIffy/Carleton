/* 3000test.c */
/* v1 Oct. 1, 2017 */
/* Licenced under the GPLv3, copyright Anil Somayaji */
/* You really shouldn't be incorporating parts of this in any other code,
   it is meant for teaching, not production */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void report_error(char *error)
{
        fprintf(stderr, "Error: %s\n", error);

        exit(-1);
}

void sparsecheck(char *fn, struct stat statbuf){
	int physiS;
	size_t logiS;

	logiS = statbuf.st_size;
	physiS = statbuf.st_blocks * 512;

	if(physiS < logiS){
		printf("This file has holes\n");
	} else{	
		printf("This file does not have holes\n");
	}
}

int main(int argc, char *argv[])
{
        struct stat statbuf;
        char *fn;
        int fd;
        size_t len, i, count;
        
        char *data;

        if (argc < 2) {
                if (argc < 1) {
                        report_error("no command line");
                        fprintf(stderr, "Usage: %s <file>\n", argv[0]); 
                } else {
                        report_error("Not enough arguments");
                        fprintf(stderr, "Usage: %s <file>\n", argv[0]); 
                }
        }

        fn = argv[1];

        if (stat(fn, &statbuf)) {
                report_error(strerror(errno));
        }

        len = statbuf.st_size;
        printf("File %s: \n", fn);
        printf("   inode %ld\n", statbuf.st_ino);
        printf("  length %ld\n", len);        

        if (S_ISREG(statbuf.st_mode)) { 
		sparsecheck(fn, statbuf);

		fd = open(fn, O_RDONLY);
                if (fd == -1) {
                        report_error(strerror(errno));
                }

		data = (char *) malloc(len);
		if(read(fd, data, len) < 0){
                        report_error(strerror(errno));
		}

		printf("%s", data);
	
                count = 0;
                for (i=0; i<len; i++) {
                        if (data[i] == 'a') {
                                count++;
                        }
                }

                printf(" a count %ld\n", count);

		free(data);
                close(fd);
        }

        return 0;
}
