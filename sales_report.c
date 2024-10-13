#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void monthly_sales_report(const char *months[], double sales[]);
void sales_summary_report(double sales[]);
void six_month_moving_average_report(double sales[], const char *months[]);
void sales_report_highest_to_lowest(double sales[], const char *months[]);

int main() {
    const char *months[MONTHS] = {"January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"};

    double sales[MONTHS];

    printf("Enter the sales for all 12 months:\n");
    for (int i = 0; i < MONTHS; i++) {
        scanf("%lf", &sales[i]);
    }

    printf("\nMonthly Sales Report\n");
    printf("-----------------------\n");
    monthly_sales_report(months, sales);

    printf("\nSales Summary Report\n");
    printf("-----------------------\n");
    sales_summary_report(sales);

    printf("\nSix-Month Moving Average Report\n");
    printf("-------------------------------\n");
    six_month_moving_average_report(sales, months);

    printf("\nSales Report (Highest to Lowest)\n");
    printf("--------------------------------\n");
    sales_report_highest_to_lowest(sales, months);

    return 0;
}

void monthly_sales_report(const char *months[], double sales[]) {
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s : $%.2f\n", months[i], sales[i]);
    }
}

void sales_summary_report(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        total += sales[i];
    }

    double average = total / MONTHS;

    printf("Minimum Sales: $%.2f\n", min);
    printf("Maximum Sales: $%.2f\n", max);
    printf("Average Sales: $%.2f\n", average);
}

void six_month_moving_average_report(double sales[], const char *months[]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        double total = 0.0;
        for (int j = i; j < i + 6; j++) {
            total += sales[j];
        }
        double moving_average = total / 6.0;
        printf("%s - %s: $%.2f\n", months[i], months[i+5], moving_average);
    }
}

void sales_report_highest_to_lowest(double sales[], const char *months[]) {
    double sorted_sales[MONTHS];
    const char *sorted_months[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = months[i];
    }

    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                double temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;

                const char *temp_month = sorted_months[i];
                sorted_months[i] = sorted_months[j];
                sorted_months[j] = temp_month;
            }
        }
    }

    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s : $%.2f\n", sorted_months[i], sorted_sales[i]);
    }
}
