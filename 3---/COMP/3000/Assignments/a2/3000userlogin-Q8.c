/* 3000userlogin.c */
/* version 0.1 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <shadow.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SHELLSCRIPT1 "\
#/bin/bash \n\
stty -echo\n\
"

#define SHELLSCRIPT2 "\
#/bin/bash \n\
stty echo\n\
"

int main(int argc, char *argv[])
{
        int result, fd;
        char *shell_argv[3];
        char *username, u[32], *s, *salt, full[128], *index, computed[128], openssl_cmd[128];
        extern char **environ;
        struct spwd *sp_entry;
	struct passwd *pw_entry;
                
        if (argc < 2) {
        	printf("uid=%d, euid=%d, gid=%d, egid=%d\n",
              		 getuid(), geteuid(), getgid(), getegid());
	
		printf("Username: ");

		system(SHELLSCRIPT1);		
	
		username = fgets(u, 32, stdin);
		username[strlen(u)-1] = '\0';
	
		system(SHELLSCRIPT2);
		printf("\n");
	} else{
        	printf("uid=%d, euid=%d, gid=%d, egid=%d\n",
               		getuid(), geteuid(), getgid(), getegid());

		username = argv[1];
	}
        
        pw_entry = getpwnam(username);
	sp_entry = getspnam(username); // this retrieves the entry from /etc/shadow
        if (pw_entry == NULL || sp_entry == NULL) {
                fprintf(stderr, "Could not find user %s.\n", username);
                exit(-2);
        }
                      
	memcpy(full, sp_entry->sp_pwdp, strlen(sp_entry->sp_pwdp)+1); // save a copy of the entire line
	index = strtok(sp_entry->sp_pwdp, "$"); // get the algorithm index
	salt = strtok(NULL, "$"); 

	snprintf(openssl_cmd, 128, "openssl passwd -%s -salt %s\n", index, salt); 
	FILE *fp = popen(openssl_cmd, "r"); // this sends the command above and returns a pointer to its stdout
	if (!fp) {
		fprintf(stderr, "openssl command failed.\n");
		exit(-2);
	}
	s = fgets(computed, 128, fp); //read the computed result
	pclose(fp);
	if(strncmp(full, s, strlen(full))) {
		fprintf(stderr, "authentication failed.\n");
		exit(-2);
	}
	
        result = setgid(pw_entry->pw_gid);
        if (result != 0) {
                fprintf(stderr, "Failed to change to gid %d\n",
                        pw_entry->pw_gid);
                exit(-3);
        }

        result = setuid(pw_entry->pw_uid);
        if (result != 0) {
                fprintf(stderr, "Failed to change to uid %d\n",
                        pw_entry->pw_uid);
                exit(-4);
        }

        result = chdir(pw_entry->pw_dir);
        if (result != 0) {
                fprintf(stderr, "Failed to change to home dir %s\n",
                        pw_entry->pw_dir);
                exit(-5);
        }

        shell_argv[0] = "bash";
        shell_argv[1] = "--login";
        shell_argv[2] = NULL;

        clearenv();
        setenv("USERNAME", pw_entry->pw_name, 1);
        setenv("PATH", "/usr/bin:/bin", 1);
        setenv("SHELL", "/bin/bash", 1);
        setenv("HOME", pw_entry->pw_dir, 1);
        setenv("COMP3000", "yes", 1);
        
        execve("/bin/bash", shell_argv, environ);
     
        fprintf(stderr, "Failed to exec bash\n");
        return -6;
}
