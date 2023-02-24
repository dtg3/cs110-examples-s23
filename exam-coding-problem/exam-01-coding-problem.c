#include <stdio.h>

// Function Prototypes
void read_array_input(int array[], size_t size);
double calculate_average(const int array[], size_t size);
double calculate_difference(int value, double avg);

int main() {
    printf("How many values will you enter? ");
    size_t array_size;
    scanf("%zu", &array_size);
    
    int number_array[array_size];
    printf("Enter the values: ");
    read_array_input(number_array, array_size);
    
    double array_average = calculate_average(number_array, array_size);
    printf("The average is %lf\n", array_average);

    printf("Difference from the average:\n");
    for (size_t i = 0; i < array_size; ++i) {
        printf("%lf ", calculate_difference(number_array[i], array_average));
    }
    printf("\n");

    return 0;
}

void read_array_input(int array[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        scanf("%i", &array[i]);
    }
}

double calculate_average(const int array[], size_t size) {
    int total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += array[i];
    }
    return total / (double) size;
}

double calculate_difference(int value, double avg) {
    return value - avg;
}