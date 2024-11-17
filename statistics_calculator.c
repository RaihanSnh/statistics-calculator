#include <stdio.h>

// func declarations for population & sample distributions
void population_distribution();
void sample_distribution();

// func declarations for probability distributions
void discrete_distribution();
void continuous_distribution();

// common formula funcs (these can be reused in different categories)
void calculate_mean();
void calculate_median();
void calculate_mode();
void calculate_quartile1();
void calculate_quartile3();
void calculate_range();
void calculate_interquartile_range();
void calculate_variance();
void calculate_standard_deviation();
void calculate_coefficient_variance();
void calculate_z_score();
void calculate_standard_error();

// discrete probability distribution funcs
void binomial_distribution();
void poisson_distribution();
void hypergeometric_distribution();

// continuous probability distribution funcs
void normal_distribution();
void uniform_distribution();

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

int main() {
    int main_choice;
    char repeat_main;
    int data[100], jumlah_data;
	
    do {
        // main dashboard
        printf("Advanced Statistics Calculator\n");
        printf("1. Population Distribution\n");
        printf("2. Sample Distribution\n");
        printf("3. Discrete Probability Distribution\n");
        printf("4. Continuous Probability Distribution\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        main_choice = get_choice(1, 5);

        switch (main_choice) {
            case 1:
                population_distribution();
                break;
            case 2:
                sample_distribution();
                break;
            case 3:
                discrete_distribution();
                break;
            case 4:
                continuous_distribution();
                break;
            case 5:
                printf("Exiting calculator.\n");
                return 0;
        }

        // ask user if they want to go back to the main dashboard
        printf("Do you want to go back to the main dashboard? (y/n): ");
        repeat_main = get_yes_no();

    } while (repeat_main == 'y' || repeat_main == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}

// population distribution menu
void population_distribution() {
    int formula_choice;
    char repeat_category;

    do {
        printf("\nPopulation Distribution Formulas:\n");
        printf("1. Mean\n2. Median\n3. Mode\n4. Quartile 1\n5. Quartile 3\n6. Range\n7. Interquartile Range\n");
        printf("8. Variance\n9. Standard Deviation\n10. Coefficient of Variance\n11. Z Score\n");
        printf("Choose a formula (1-11): ");
        formula_choice = get_choice(1, 11);

        switch (formula_choice) {
            case 1: calculate_mean(); break;
            case 2: calculate_median(); break;
            case 3: calculate_mode(); break;
            case 4: calculate_quartile1(); break;
            case 5: calculate_quartile3(); break;
            case 6: calculate_range(); break;
            case 7: calculate_interquartile_range(); break;
            case 8: calculate_variance(); break;
            case 9: calculate_standard_deviation(); break;
            case 10: calculate_coefficient_variance(); break;
            case 11: calculate_z_score(); break;
        }

        printf("Would you like to use another formula in Population Distribution? (y/n): ");
        repeat_category = get_yes_no();

    } while (repeat_category == 'y' || repeat_category == 'Y');
}

// sample distribution menu
void sample_distribution() {
    int formula_choice;
    char repeat_category;

    do {
        printf("\nSample Distribution Formulas:\n");
        printf("1. Mean\n2. Median\n3. Mode\n4. Quartile 1\n5. Quartile 3\n6. Range\n7. Interquartile Range\n");
        printf("8. Variance\n9. Standard Deviation\n10. Coefficient of Variance\n11. Z Score\n12. Standard Error\n");
        printf("Choose a formula (1-12): ");
        formula_choice = get_choice(1, 12);

        switch (formula_choice) {
            case 1: calculate_mean(); break;
            case 2: calculate_median(); break;
            case 3: calculate_mode(); break;
            case 4: calculate_quartile1(); break;
            case 5: calculate_quartile3(); break;
            case 6: calculate_range(); break;
            case 7: calculate_interquartile_range(); break;
            case 8: calculate_variance(); break;
            case 9: calculate_standard_deviation(); break;
            case 10: calculate_coefficient_variance(); break;
            case 11: calculate_z_score(); break;
            case 12: calculate_standard_error(); break;
        }

        printf("Would you like to use another formula in Sample Distribution? (y/n): ");
        repeat_category = get_yes_no();

    } while (repeat_category == 'y' || repeat_category == 'Y');
}

// discrete probability distribution menu
void discrete_distribution() {
    int formula_choice;
    char repeat_category;

    do {
        printf("\nDiscrete Probability Distribution:\n");
        printf("1. Binomial Distribution\n2. Poisson Distribution\n3. Hypergeometric Distribution\n");
        printf("Choose a formula (1-3): ");
        formula_choice = get_choice(1, 3);

        switch (formula_choice) {
            case 1: binomial_distribution(); break;
            case 2: poisson_distribution(); break;
            case 3: hypergeometric_distribution(); break;
        }

        printf("Would you like to use another formula in Discrete Distribution? (y/n): ");
        repeat_category = get_yes_no();

    } while (repeat_category == 'y' || repeat_category == 'Y');
}

// continuous probability distribution menu
void continuous_distribution() {
    int formula_choice;
    char repeat_category;

    do {
        printf("\nContinuous Probability Distribution:\n");
        printf("1. Normal Distribution\n2. Uniform Distribution\n");
        printf("Choose a formula (1-2): ");
        formula_choice = get_choice(1, 2);

        switch (formula_choice) {
            case 1: normal_distribution(); break;
            case 2: uniform_distribution(); break;
        }

        printf("Would you like to use another formula in Continuous Distribution? (y/n): ");
        repeat_category = get_yes_no();

    } while (repeat_category == 'y' || repeat_category == 'Y');
}

// formula funcs (implementation placeholders)
int calculate_mean(int data[], int n) { 
	int i,total=0;
	float mean;
	for(i=0;i<n;i++){
		total+=data[i];
	}
	mean=total/n;
	printf("Mean = %.2f\n",mean); 
}
int calculate_median(int data[], int n) {
	int posisi;
	float median;
	if(n%2 != 0){
		posisi=(n+1)/2;
		median=data[posisi];
	}else{
		posisi=n/2;
		median=(data[posisi]+data[posisi+1])/2;
	}
	printf("Median = %.2f\n", median); 
}
void calculate_mode() { 
	printf("Calculating Mode\n"); 
}
int calculate_quartile1() { 
	int posisi;
	float quartile1;
	if(n%2 != 0){
		posisi=(n+1)/4;
		median=data[posisi];
	}else{
		posisi=n/4;
		median=(data[posisi]+data[posisi+1])/2;
	}
	printf("Median = %.2f\n", quartile1); 
}
int calculate_quartile3(int data[], int n) {
	int posisi;
	float quartile3;
	if(n%2 != 0){
		posisi=3*(n+1)/4;
		median=data[posisi];
	}else{
		posisi=3*n/4;
		median=(data[posisi]+data[posisi+1])/2;
	}
	printf("Median = %.2f\n", quartile3);  
}
int calculate_range(int data[], int n) { 
	printf("Range = %d\n",data[n] - data[0]); 
}
void calculate_interquartile_range() { 
	printf("Calculating Interquartile Range\n"); 
}
void calculate_variance() { 
	printf("Calculating Variance\n"); 
}
void calculate_standard_deviation() { 
	printf("Calculating Standard Deviation\n"); 
}
void calculate_coefficient_variance() { 
	printf("Calculating Coefficient of Variance\n"); 
}
void calculate_z_score() { 
	printf("Calculating Z Score\n"); 
}
void calculate_standard_error() { 
	printf("Calculating Standard Error\n");
}

void binomial_distribution() { 
	printf("Calculating Binomial Distribution\n"); 
}
void poisson_distribution() { 
	printf("Calculating Poisson Distribution\n"); 
}
void hypergeometric_distribution() { 
	printf("Calculating Hypergeometric Distribution\n"); 
}
void normal_distribution() { 
	printf("Calculating Normal Distribution\n"); 
}
void uniform_distribution() { 
	printf("Calculating Uniform Distribution\n"); 
}
