#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* realoc(void* maloc, int size) {
	void *reaoc;
	reaoc = (void*)malloc(size);
	memcpy(reaoc, maloc, size);

	free(maloc);
	return reaoc;
}

/*main foi tirada de um exemplo de onde o realloc pode ser util
http://www.cplusplus.com/reference/cstdlib/realloc/?kw=realloc*/

int main()
{
	int input, n;
	int count = 0;
	int* numbers = NULL;
	int* more_numbers = NULL;

	do {
		printf("Enter an integer value (0 to end): ");
		scanf("%d", &input);
		

		more_numbers = (int*)realoc(numbers, count * sizeof(int));

		if (more_numbers != NULL) {
			numbers = more_numbers;
			numbers[count - 1] = input;
		}
		else {
			free(numbers);
			puts("Error (re)allocating memory");
			exit(3);
		}
		count++;
	} while (input != 0);

	printf("Numbers entered: ");
	for (n = 0; n < count; n++) printf("%d ", numbers[n]);
	free(numbers);

	return 0;
}
