#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
//This programme asks for a credit card number. The programme uses a checksum and features of
//different credit card to make the credit card or state that it is invalid
{
    // Variables
    int digits, total_odd, total_even, sum_number, extracted_number, temporary_number, total_sum;
    long long original_card_number, working_card_number;
    working_card_number = 0;
    digits = 0;
    total_odd = 0;
    total_even = 0;
    // prompt the user for the card number
    do
    {
        printf("What is your credit card number? : ");
        working_card_number = get_long_long();
    }
    while (working_card_number <= 0);
    original_card_number = working_card_number;

    // calculating the checksum
    do
        // counting the number of digits from the end and
        //extracting the final digit in the working number
    {
        digits += 1;
        extracted_number = (working_card_number % 10);
        working_card_number = (working_card_number / 10);
        // for odd digits counting from the end of the credit card number
        if (((digits) % 2) != 0)
        {
            sum_number = ((extracted_number % 10) + (extracted_number / 10));
            total_odd = (sum_number + total_odd);
        }
        // for even digits counting from the end of the credit card number
        else
        {
            temporary_number = (extracted_number * 2);
            sum_number = ((temporary_number % 10) + (temporary_number / 10));
            total_even = (sum_number + total_even);
        }
    }
    while (working_card_number != 0);
    // the total of the Luhn's checksum
    total_sum = (total_even + total_odd);

    //Validity check
    int validity;
    validity = total_sum % 10;

    //Extracting the first two digits of the credit card number
    long long first_two_digits;
    first_two_digits = (original_card_number * (1 / (pow(10, (digits - 2)))));

    // Extracting the first digit of the credit card number
    int first_digit;
    first_digit = (first_two_digits);
    first_digit = (first_digit / 10);
    // Determining the validity
    if (validity != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // testing for mastercard or visa
        if (digits == 16)

        {
            if ((first_digit) == 4)
            {
                printf("VISA\n");
            }
            else if ((first_two_digits) >= 51 &&
                     (first_two_digits) <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // testing for visa
        else if (digits == 13)
        {
            if ((first_digit) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // testing for American Express
        else if (digits == 15)
        {
            if ((first_two_digits) == 34 ||
                (first_two_digits) == 37)
            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }

    }

}
