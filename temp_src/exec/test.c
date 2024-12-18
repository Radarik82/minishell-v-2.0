/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:22:19 by vgabovs           #+#    #+#             */
/*   Updated: 2024/02/04 15:16:05 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../minishell.h"

// int	execution()
// {

// }


// int main() {
// 	pid_t pid = fork();

// 	if (pid == 0) {
// 		int a;
// 		exit(-1);
// 	} else if (pid > 0) {
// 		int status;
// 		waitpid(pid, &status, 0);

// 		if (WIFEXITED(status)) {
// 			int exit_status = WEXITSTATUS(status);
// 			printf("Status: %d\n", status);
// 			printf("Child process exited with status: %d\n", exit_status);
// 		} else {
// 			printf("Child process did not exit normally.\n");
// 		}
// 	}

// 	return 0;
// }

