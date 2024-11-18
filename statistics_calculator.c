#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk kalkulasi statistik umum
void calculate_mean(int data[], int n);
void calculate_median(int data[], int n);
void calculate_mode(int data[], int n);
void calculate_quartile1(int data[], int n);
void calculate_quartile3(int data[], int n);
void calculate_range(int data[], int n);
void calculate_interquartile_range(int data[], int n);
// void calculate_variance(int data[], int n);
// void calculate_standard_deviation(int data[], int n);
// void calculate_coefficient_variance(int data[], int n);
// void calculate_z_score(int data[], int n);
void all(int data[], int n);

int get_choice(int min, int max) {
    int choice;
    while (1) {
        scanf("%d", &choice); getchar();
        if (choice >= min && choice <= max) {
            return choice;
        } else {
            printf("Invalid choice. Please enter a number between %d and %d: ", min, max);
        }
    }
}

char get_yes_no() {
    char response;
    while (1) {
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') {
            return response;
        } else {
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
    }
}

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int main_choice;
    char repeat_main;
    int data[100], jumlah_data, i;

    printf("Welcome to Statistics Calculator\n");
    printf("Masukan jumlah data: ");
    scanf("%d", &jumlah_data);
    printf("Masukan data:\n");
    for(i = 0; i < jumlah_data; i++) {
        scanf("%d", &data[i]);
    }

    do {
        printf("Menu\n");
        printf("1.  Mean\n2.  Median\n3.  Mode\n4.  Quartile 1\n5.  Quartile 3\n6.  Range\n7.  Interquartile Range\n");
        printf("8.  Variance\n9.  Standard Deviation\n10. Coefficient of Variance\n11. Z Score\n12. All\n");
        printf("0.  Exit\n");
        printf("Enter your choice (0-12): ");
        main_choice = get_choice(0, 12);

        switch (main_choice) {
            case 1: calculate_mean(data, jumlah_data); break;
            case 2: calculate_median(data, jumlah_data); break;
            case 3: calculate_mode(data, jumlah_data); break;
            case 4: calculate_quartile1(data, jumlah_data); break;
            case 5: calculate_quartile3(data, jumlah_data); break;
            case 6: calculate_range(data, jumlah_data); break;
            case 7: calculate_interquartile_range(data, jumlah_data); break;
            // case 8: calculate_variance(data, jumlah_data); break;
            // case 9: calculate_standard_deviation(data, jumlah_data); break;
            // case 10: calculate_coefficient_variance(data, jumlah_data); break;
            // case 11: calculate_z_score(data, jumlah_data); break;
            case 12: all(data, jumlah_data); break;
            case 0:
                printf("Exit from Menu!\n");
        }

        printf("Do you want to go back to the Menu? (y/n): ");
        repeat_main = get_yes_no();

    } while (repeat_main == 'y' || repeat_main == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}

void calculate_mean(int data[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    float mean = (float)total / n;
    printf("Mean = %.2f\n", mean);
}

void calculate_median(int data[], int n) {
    sort(data, n);
    float median;
    if (n % 2 != 0) {
        median = data[n / 2];
    } else {
        median = (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }
    printf("Median = %.2f\n", median);
}

void calculate_mode(int data[], int n) {
    int besar = 0, modus = data[0];
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (data[j] == data[i])
                ++count;
        }
        if (count >= besar) {
            besar = count;
            modus = data[i];
        }
    }
    printf("Mode = %d\n", modus);
}

void calculate_quartile1(int data[], int n) {
    sort(data, n);
    float Q1;
    int letak = (n + 1) / 4;
    Q1 = (n % 2 != 0) ? data[letak] : (data[letak - 1] + data[letak]) / 2.0;
    printf("Quartile 1 = %.2f\n", Q1);
}

void calculate_quartile3(int data[], int n) {
    sort(data, n);
    float Q3;
    int letak = 3 * (n + 1) / 4;
    Q3 = (n % 2 != 0) ? data[letak] : (data[letak - 1] + data[letak]) / 2.0;
    printf("Quartile 3 = %.2f\n", Q3);
}

void calculate_range(int data[], int n) {
    sort(data, n);
    int range = data[n - 1] - data[0];
    printf("Range = %d\n", range);
}

void calculate_interquartile_range(int data[], int n) {
    sort(data, n);
    float Q1,Q3;
    int letak = (n + 1) / 4;
    Q1 = (n % 2 != 0) ? data[letak] : (data[letak - 1] + data[letak]) / 2.0;
    letak = 3 * (n + 1) / 4;
    Q3 = (n % 2 != 0) ? data[letak] : (data[letak - 1] + data[letak]) / 2.0;
    float interq = Q3 - Q1;
    printf("Interquartile Range = %.2f\n", interq);
}

// Implementasi placeholder untuk fungsi lainnya
// void calculate_variance(int data[], int n) { printf("Calculating Variance\n"); }
// void calculate_standard_deviation(int data[], int n) { printf("Calculating Standard Deviation\n"); }
// void calculate_coefficient_variance(int data[], int n) { printf("Calculating Coefficient of Variance\n"); }
// void calculate_z_score(int data[], int n) { printf("Calculating Z Score\n"); }
// void calculate_standard_error(int data[], int n) { printf("Calculating Standard Error\n"); }

void all(int data[], int n) {
    calculate_mean(data, n);
    calculate_median(data, n);
    calculate_mode(data, n);
    calculate_quartile1(data, n);
    calculate_quartile3(data, n);
    calculate_range(data, n);
    calculate_interquartile_range(data, n);
    // calculate_variance(data, n);
    // calculate_standard_deviation(data, n);
    // calculate_coefficient_variance(data, n);
    // calculate_z_score(data, n);
    // calculate_standard_error(data, n);
}
