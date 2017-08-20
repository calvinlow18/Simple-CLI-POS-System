#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 12

const char item[SIZE][15] = { " ", "Char Kway Teow", "Fried Rice", "Asam Laksa", "Curry Mee", "Roti Canai", "Indian Rice", "Nasi Lemak", "Otak-otak", "Chinese Tea", "Teh Tarik", "Air Bandung" };
const double price[SIZE] = { 0.0, 5.5, 6.6, 5.8, 5, 1.2, 6.0, 4.5, 3.8, 1, 1.8, 1.2 };

int allQtt(int quantity[]) {

	int countQtt, totalQtt = 0;

	for (countQtt = 0; countQtt < SIZE; countQtt++) {
		totalQtt += quantity[countQtt];
	}
	return totalQtt;
} //Count the total quantity to gain access to option2 and print the total quantity in option1.

void option1(int quantity[]) {

	int counter1, code = 0, qtt = 0, confirm = 0;;

	printf("\n%21s\n\n", "Menu");
	printf("%6s%11s%17s\n\n", "Code", "Items", "Price");

	for (counter1 = 1; counter1 < SIZE; counter1++) {
		printf("%5d   %-20sRM%5.2f\n", counter1, item[counter1], price[counter1]);
	} //Print the menu.

	printf("\n  Place your order !!!\n\n  Note : Enter negative quantity to reduce ordered quantity.\n\n");

	while (confirm != 1) {
		printf("\n  Enter item's code (1-11) (-1 to double confirm): ");
		scanf("%d", &code);//Enter code.
		printf("\n");

		if (code == -1) {

			printf("\n -------------------------------\n");
			printf("%7s%24s", "Items", "Quantity");
			printf("\n -------------------------------\n");

			for (counter1 = 1; counter1 < SIZE; counter1++) {
				if (quantity[counter1] > 0) {
					printf("  %-24s%d\n", item[counter1], quantity[counter1]);
				}
			} //Print ordered items and quantity.

			printf("\n  You ordered %d items. Confirm ( 1 = Yes , Other keys = No ) ? ", allQtt(quantity));
			scanf("%d", &confirm); //Confirmation: 1 - Quit and back to option menu ; Other keys - continue ordering.

		}
		else if (code > 11 || code < 1) {
			printf("\a\n  Please enter code that is in the menu.\n\n\a");
			continue;// Code not valid. Continue ordering.
		}
		else{

			printf("  How many %s do you want ? ", item[code]);
			scanf("%d", &qtt);// Prompt for quantity for the item.

			if (quantity[code] + qtt < 0) { // Test whether the quantity after adding is lesser than zero
				printf("\a\n\n  The quantity of %s cannot be lesser than 0! It is now %d!\n\n\a", item[code], quantity[code]);
			}
			else {
				quantity[code] += qtt;// Add qtt into item code's quantity array element
			}
		}
	}
	system("cls");// Clear screen.
}

void option2(int quantity[]) {

	int counter2, member = 0, round = 0;
	double subtotal = 0, discount = 0, gst = 0, tax = 0, total = 0, pay = 0, change = 0, roundTotal = 0;
		
	printf("\n ----------------------------------------------------\n");
	printf("%7s%30s%15s\n", "Items", "Quantity", "Subtotal");
	printf(" ----------------------------------------------------\n");

	for (counter2 = 1; counter2 < SIZE; counter2++) {
		if (quantity[counter2] > 0) {
			printf("  %-24s%7d%13s%6.2f\n", item[counter2], quantity[counter2], "RM", quantity[counter2] * price[counter2]);
			subtotal += quantity[counter2] * price[counter2];
		}
	} // Print all the ordered items' name, quantity and subtotal for each item.

	printf("\n  Are you a member of Sunshine Restaurant ( 1 = Yes , Other keys = No) ? ");
	scanf("%d", &member);// Ask whether is a member.

	if (member == 1) {
		discount = subtotal * 0.05; // discount for member.
	}

	gst = 0.06*(subtotal - discount);// Calculate GST.
	tax = 0.1*(subtotal - discount); // Calculate service tax.
	total = subtotal - discount + gst + tax;// Calculate total.
	round = (int)ceil(total * 100); // Get the round up of total * 100 and then make it an integer.

	while (round % 5 != 0) {
		++round; //Add the integer round with 1 until it is divisible by 5.
	}

	roundTotal = round / 100.0; //Convert the integer back to double.

	printf("\n  %-26sRM%6.2f\n", "Subtotal:", subtotal);
	printf("  %-26sRM%6.2f\n", "Discount:", discount);
	printf("  %-26sRM%6.2f\n", "GST:", gst);
	printf("  %-26sRM%6.2f\n", "Service Tax:", tax);
	printf("  %-26sRM%6.2f\n", "Total:", total);
	printf("  %-26sRM%6.2f\n", "Total (round off):", roundTotal);

	printf("\n\n ======================================\n");
	printf("\n  Enter amount to pay:%8s ", "RM");
	scanf("%lf", &pay);
	printf("\n ======================================\n\n");

	change = pay - roundTotal; // Calculate the change

	if (change > 0.0) {
		printf("  Your change is:%13s%6.2f\n\n", "RM", change);
		printf("  Thank you!\n\n  ");
	}
	else if (change < 0.0) {
		printf("  Please pay another %9s %.2f\n\n  ", "RM", -1 * change);
	}
	else {
		printf("\n  Thank you!\n  ");
	}

	printf("\n  Press ENTER to return to Option Menu. ");
	getchar();// Enable first ENTER above to store.
	getchar();// Enable the function press Enter to return to option menu.

	system("cls");
}

int main(void) {

	int quantity[SIZE] = { 0 }, option = 0;

	while (option != 3) {

		printf("\n Welcome to SUNSHINE Restaurant. Please choose one of the options:\n\n\n");
		printf("%9s%14s\n\n", "OPTIONS", "FUNCTIONS");
		printf("%6d%19s\n", 1, "Place order");
		printf("%6d%36s\n", 2, "Calculate and print the bill");
		printf("%6d%12s\n\n", 3, "Exit");

		printf("  Enter option: ");
		scanf("%d", &option); //Prompt for option.

		switch (option) {
		case 1:
			system("cls"); //Clear screen.
			option1(quantity); //Go to option1 function.
			break; //Break to return to option page after option 1. 
		case 2:
			system("cls"); //Clear screen.
			option2(quantity); //Go to option2 function.
			break; //Break to return to option page after option 2. 
		case 3:
			printf("\n  Please Come Again. Bye~~~\n");
			break; //Break to return to option page and quit.
		default:
			printf("\a");
			system("cls"); //Clear screen.
			break; //Break and repeat until 1, 2 or 3 is entered.
		}
	}
	return 0;
}

