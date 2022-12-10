#include "../shell.h"

int main(void)
{
	int n;
	char *dest, *src, *copy, *new;

	dest = malloc(sizeof(char) * 23);
	my_strcpy(dest, "This is my destination");
	printf("my_strlen___________\t");
	n = my_strlen(dest);
	printf("%d\n", n);
	printf("my_strcpy___________\t");
	printf("%s\n", dest);

	
	src = malloc(sizeof(char) * 10);
	my_strcpy(src, "I am here");
	printf("my_strlen___________\t");
	n = my_strlen(src);
	printf("%d\n", n);
	printf("my_strcpy___________\t");
	printf("src:\t%s\n", src);
	
	copy = malloc(sizeof(char) * (n + 1));
	my_strcpy(copy, src);
	printf("my_strcpy___________\t");
	printf("copy:\t%s\n", copy);
	
	printf("my_strcat___________\t");
	printf("dest:\t%s\n", dest);
	printf("src:\t%s\n", src);
	dest = realloc(dest, 32);
	my_strcat(dest, src);
	printf("dest:\t%s\n", dest);

	n = my_strcmp(src, copy);
	printf("my_strcmp returned: %d\n", n);
	n = my_isdigit("1234");
	printf("my_isdigit returned: %d\n", n);

	printf("reverse_str___________\t");
	printf("%s\n", copy);
	reverse_str(copy);
	printf("%s\n", copy);

	new = my_strdup(dest);
	printf("my_strdup___________\t%s\n", new);

	free(dest);
	free(src);
	free(copy);
	free(new);
	return (0);
}
