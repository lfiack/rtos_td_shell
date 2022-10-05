/*
 * shell.h
 *
 *  Created on: 7 juin 2019
 *      Author: laurent
 */

#ifndef INC_LIB_SHELL_SHELL_H_
#define INC_LIB_SHELL_SHELL_H_

#include <stdint.h>

#define UART_DEVICE huart1

#define ARGC_MAX 8
#define BUFFER_SIZE 40
#define SHELL_FUNC_LIST_MAX_SIZE 64

void shell_init();
int shell_add(char c, int (* pfunc)(int argc, char ** argv), char * description);
int shell_run();

#endif /* INC_LIB_SHELL_SHELL_H_ */
