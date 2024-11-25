#include <stdio.h>
#define MAX 20

int n;                    
int target;               
int set[MAX];             
int solution[MAX];        

void sumOfSubsets(int index, int current_sum, int remaining_sum) {
    if (current_sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++) {
            if (solution[i]) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return;
    }

    if (index >= n || current_sum > target || current_sum + remaining_sum < target) {
        return;
    }

    solution[index] = 1;
    sumOfSubsets(index + 1, current_sum + set[index], remaining_sum - set[index]);

    solution[index] = 0;
    sumOfSubsets(index + 1, current_sum, remaining_sum - set[index]);
}

int main() {
    n = 5;                               
    int predefined_set[] = {10, 7, 5, 3, 12}; 
    target = 15;                         

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        set[i] = predefined_set[i];
        total_sum += set[i];
    }

    printf("Set: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
    printf("\nTarget Sum: %d\n", target);
    sumOfSubsets(0, 0, total_sum);

    return 0;
}
