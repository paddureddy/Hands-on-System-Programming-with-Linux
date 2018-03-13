/*
 * ch8:execl_eg.c
 * 
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Hands-on System Programming with Linux"
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *
 * From:
 *  Ch 8 : Process Execution and Creation
 ****************************************************************
 * Brief Description:
 * A simple demo of using the execl(3) API; we execute the
 * 'uname -[r|a]' here.
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "../common.h"

/*---------------- Globals, Macros ----------------------------*/


/*---------------- Typedef's, constants, etc ------------------*/


/*---------------- Functions ----------------------------------*/


int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s {-a|-r}\n"
			" -a : display all uname info\n"
			" -r : display only kernel version\n"
			, argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* Have us, the predecessor, exec the successor! */
	if (execl("/bin/uname", "uname", argv[1], (char *)0) == -1)
		FATAL("execl failed\n");
	
	printf("This should never get executed if all's well!\n");
	exit (EXIT_SUCCESS);
}

/* vi: ts=8 */
