/*
     |\  ,   _,   _,   _      () | _,         _               _,
   _ |/ / \_/ |  / |  /       /\/|/ |  /|/|  / \_|  |  /|/|  / |
   \_/\/ \/ \/|_/\/|_/\__/   /(_/ \/|_/ | |_/\_/  \/|_/ | |_/\/|/
   Computer Organization Final Project                        (|
   2021-12-10
*/
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void swap(uint64_t* a, uint64_t* b);

double average(int64_t values[], uint64_t size);

uint64_t gcd_iter(uint64_t a, uint64_t b);

uint64_t gcd_recur(uint64_t a, uint64_t b);

void sort(int64_t* array, uint64_t size);

int main(void) {
	uint64_t a,b;
	int64_t num_integers_in_array = 0;
	int64_t* int_array;
	printf("Please enter a and b positive integers: ");
	scanf("%lu", &a);
	scanf("%lu", &b);
	printf("Original a, b: %lu, %lu -> ",a,b);
	swap(&a, &b);
	printf("Swapped a, b: %lu, %lu\n", a,b);
	while (num_integers_in_array < 1) {
		printf("How many integers do you wish to average and sort? ");
		scanf("%lu", &num_integers_in_array);
	}
	printf("Number of integers expected: %ld\n", num_integers_in_array);
	int_array = malloc(num_integers_in_array * sizeof(int64_t));
	printf("Enter your integers now: ");
	for (int x = 0; x < num_integers_in_array; x++) {
		scanf("%ld", &int_array[x]);
	}
	printf("Average of entered numbers: %lf\n", average(int_array,num_integers_in_array));
	printf("Greatest Common Divisor of a and b (Iterative): %lu\n", gcd_iter(a,b));
	printf("Greatest Common Divisor of a and b (Recursive): %lu\n", gcd_recur(a,b));
	sort(int_array, num_integers_in_array);
	printf("Sorted integers:");
	for (int x = 0; x < num_integers_in_array; x++) {
		printf(" %ld", int_array[x]);
	}
	printf("\n");
	free(int_array);
	return 0;
}
