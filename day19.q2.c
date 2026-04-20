#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int total = 0;
    int curr_max = nums[0], max_sum = nums[0];
    int curr_min = nums[0], min_sum = nums[0];

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            curr_max = max_sum = nums[i];
            curr_min = min_sum = nums[i];
        } else {
            curr_max = max(nums[i], curr_max + nums[i]);
            max_sum = max(max_sum, curr_max);

            curr_min = min(nums[i], curr_min + nums[i]);
            min_sum = min(min_sum, curr_min);
        }
        total += nums[i];
    }

    if(max_sum < 0)
        printf("%d", max_sum);
    else
        printf("%d", max(max_sum, total - min_sum));

    return 0;
}