/* 3000userlogin.c */
/* version 0.1 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <shadow.h>
#include <string.h>

int main(int argc, char *argv[])
{
        int result;
        char *shell_argv[3];
	char *cmd_argv[argc - 1];
        char *username, *s, *salt, full[128], *index, computed[128], openssl_cmd[128];
        extern char **environ;
        struct spwd *sp_entry;
	struct passwd *pw_entry;
                
        if (argc < 3) {
                fprintf(stderr, "Usage: %s <username> <command>\n", argv[0]);
                exit(-1);
        }	
	
        printf("uid=%d, euid=%d, gid=%d, egid=%d\n",
               getuid(), geteuid(), getgid(), getegid());

        username = argv[1];

	cmd_argv[0] = argv[2];
	for(int i = 3; i < argc; i++){
		cmd_argv[i-2] = argv[i];
	}
	cmd_argv[argc-2] = NULL;
        
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


        clearenv();
        setenv("USERNAME", pw_entry->pw_name, 1);
        setenv("PATH", "/usr/bin:/bin", 1);
        setenv("SHELL", "/bin/bash", 1);
        setenv("HOME", pw_entry->pw_dir, 1);
        setenv("COMP3000", "yes", 1);
        
	execvpe(cmd_argv[0], cmd_argv, environ);
        return 0;
}
