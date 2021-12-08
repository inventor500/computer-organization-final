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

void swap(int64_t* a, int64_t* b);

double average(int64_t values[], uint64_t size);

uint64_t gcd_iter(uint64_t a, uint64_t b);

uint64_t gcd_recur(uint64_t a, uint64_t b);

void sort(int64_t* array, uint64_t size);

int main(void) {
	int64_t a,b;
	/* A CPU cycle could be saved by not assigning num_integers_in_array here and using a do loop, but for style that was not done. */
	uint64_t num_integers_in_array = 0;
	int64_t* int_array;
	printf("Please enter a and b integers: ");
	scanf("%d", &a);
	scanf("%d", &b);
	int64_t array[] = {1,2,3,4};
	uint64_t length = 4;
	printf("Original a, b: %ld, %ld -> ",a,b);
	swap(&a, &b);
	printf("Swapped a, b: %ld, %ld\n", a,b);
	while (num_integers_in_array == 0) {
		printf("How many integers do you wish to average and sort? ");
		scanf("%u", &num_integers_in_array);
	}
	printf("Number of integers expected: %ld\n", num_integers_in_array);
	int_array = malloc(num_integers_in_array * sizeof(int64_t));
	printf("Enter your integers now: ");
	for (int x = 0; x < num_integers_in_array; x++) {
		scanf("%ld", &int_array[x]);
	}
	printf("Average of entered numbers: %lf\n", average(int_array,num_integers_in_array));
	printf("Greatest Common Divisor (Iterative): %ld\n", gcd_iter(a,b));
	printf("Greatest Common Divisor (Recursive): %ld\n", gcd_recur(a,b));
	sort(int_array, num_integers_in_array);
	printf("Sorted integers:");
	for (int x = 0; x < num_integers_in_array; x++) {
		printf(" %ld", int_array[x]);
	}
	printf("\n");
	free(int_array);
	return 0;
}
