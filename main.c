// Program to calculate the electricity bill

/*
An electricity board charges the following rates: for the first 200 units - 80 paise per unit, for the next 100 units - 90 paise per unit, beyond 300 units - Rs. 1.00 per unit. All users are charged a minimum of Rs. 100 as meter charge. If the total amount is more than Rs. 400, then an additional surcharge of 15% of total amount is charged. Write a program to read the name of the user, number of units consumed and print out the charges.
*/

#include<stdio.h>

int main() {
    char name[40];
    int units, meterCharge = 100;
    float totalAmount;
    float surcharge;

    printf("\n** ELECTRICITY BILL MANAGEMENT **\n");
    printf("Name of the consumer: ");
    scanf(" %[^\n]", name);
    printf("Units consumed: ");
    scanf("%d", &units);

    if (units <= 200) {
        totalAmount = (units * 0.80);
    } else if (units <= 300) {
        totalAmount = (200 * 0.80) + ((units-200) * 0.90);
    } else {
        totalAmount = (200 * 0.80) + (100 * 0.90) + ((units - 300) * 1.00);
    }

    printf("\n** SUMMARY **\n");
    printf("Consumer name: %s\n", name);
    printf("Units consumed: %d\n", units);
    printf("Base charge: Rs. %.2f\n", totalAmount);
    printf("Meter charge: Rs. %d\n", meterCharge);
    
    totalAmount += meterCharge;

    if (totalAmount > 400) {
        surcharge = totalAmount * 0.15;
        printf("[Since BaseCharge + MeterCharge is more than 400]\n");
        printf("Surcharge: Rs. %.2f\n", surcharge);
        totalAmount += surcharge;
    }

    printf("Total charges: Rs. %.2f\n\n", totalAmount);
}