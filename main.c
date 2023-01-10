
// #include <stdio.h>
// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str;

// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// }
