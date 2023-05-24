#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*define external var*/

#define BUFF 1024
#define TRUE 1
#define PRT "$ "

/* define errors*/

#define ERROR_MALOC "Unable to malloc space\n"
#define ERROR_FORK "Unable to fork and create child process\n"
#define ERROR_PATH "No such file or directory\n"

/*declare external variable*/
extern char **environ;


/**
 * struct link_st - list linked of var
 * @var: value of variable
 * @pt_next: next node
 *
 * Description: to generate linked list
**/
typedef struct link_st
{
	char *var;
	struct link_st *pt_next;
} link_st;

/**
 * struct link_blt - list linked of builtin
 * @blt: builtin name
 * @ptr: pointer
 *
 * Description: struct about builtin funct.
**/
typedef struct link_blt
{
	char *blt;
	int (*ptr)(void);
} link_blt;

/*function declaration for execution*/

void prmpt(int fl, struct stat buffer);
char *my_getline(FILE *input);
char **token_funct(char *string);
char *pth_src(char *cmd, char *pth_full, char *pth);
int prc_child(char *pth_full, char **parse);
void err(int vr_err);

/*declaration for utulity functions*/

void my_put(char *ptr);
int my_strlen(char *str);
int my_strcmp(char *vn, char *var, unsigned int size);
int my_strncmp(char *vn, char *var, unsigned int size);
char *my_strcpy(char *to, char *from);

/* function for builtins */

int _env(void);
int my_exit(void);
int _exec(char **parse);
int nbr_built(link_blt built[]);

/* functions for path*/

char *get_env(const char *name_pth);
char **envr_cpy(char **envr_cpy, unsigned int envr_size);
link_st *pth_link(char *var, link_st *hd);

/* function to free*/

void ts_free(char **pars, char *pth, char *line, char *pth_full, int flag);
void arr_free(char **arr, unsigned int size);

#endif /* MAIN_H */
