
#include <stdlib.h>
#include <stdio.h>

#include <cstring>

void* realoc(void* maloc, int size) {
	void *reaoc;
	reaoc = (void*)malloc(size);
	std::mencpy(reaoc, maloc, size);

	free(maloc);
	return reaoc;
}

int main()
{
	int input, n;
	int count = 0;
	int* numbers = NULL;
	int* more_numbers = NULL;

	do {
		printf("Enter an integer value (0 to end): ");
		scanf("%d", &input);
		count++;

		more_numbers = (int*)realoc(numbers, count * sizeof(int));

		if (more_numbers != NULL) {
			numbers = more_numbers;
			numbers[count - 1] = input;
		}
		else {
			free(numbers);
			puts("Error (re)allocating memory");
			exit(1);
		}
	} while (input != 0);

	printf("Numbers entered: ");
	for (n = 0; n < count; n++) printf("%d ", numbers[n]);
	free(numbers);

	return 0;
}
