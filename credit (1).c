#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card_number;
    int sum_total_digits;
    // keep track of digits
    int digit_counter = 0;

    // take credit card number
    credit_card_number = get_long("input credit card number ");

    // set variables that will be used later
    long x_even = credit_card_number;
    long store_double_digit = 0;
    long sum_double_digit_start = 0;
    long sum_single_digit_start = 0;
    long store_single_digit = 0;

    // start at second last digit, multiply every other number by 2, add the DIGITS of all numbers (not entire products)
    while (x_even)
    {
        long product = 2*((x_even % 100)/10);

        if ((product / 10) >= 1)
        {
            long double_digit = product;
            sum_double_digit_start = 0;
            while (double_digit)
            {
                long sum_double_digit = sum_double_digit_start + (double_digit % 10);
                double_digit /= 10;
                sum_double_digit_start = sum_double_digit;
            }
            long total_sum_double = store_double_digit + sum_double_digit_start;
            store_double_digit = total_sum_double;
        }
        else if ((product / 10) < 1)
        {
            long single_digit = product;
            sum_single_digit_start = 0;
            long total_sum_single = store_single_digit + single_digit;
            store_single_digit = total_sum_single;
        }
        x_even /= 100;
        digit_counter++;
    }

    // account for the possibility of odd numbers in which case you will have to reduce the counter by 1
    if (credit_card_number / 1000000000000000 == 0)
        {
            digit_counter--;
        }

    // add numbers obtained above
    int sum_every_other = store_single_digit + store_double_digit;

    // set new variables
    long x_odd = credit_card_number;
    store_double_digit = 0;
    sum_double_digit_start = 0;
    sum_single_digit_start = 0;
    store_single_digit = 0;

    // start at the last digit and add every other digit
    while (x_odd)
    {
        long product = x_odd % 10;

        if ((product / 10) >= 1)
        {
            long double_digit = product;
            sum_double_digit_start = 0;
            while (double_digit)
            {
                long sum_double_digit = sum_double_digit_start + (double_digit % 10);
                double_digit /= 10;
                sum_double_digit_start = sum_double_digit;
            }
            long total_sum_double = store_double_digit + sum_double_digit_start;
            store_double_digit = total_sum_double;
        }
        else if ((product / 10) < 1)
        {
            long single_digit = product;
            sum_single_digit_start = 0;
            long total_sum_single = store_single_digit + single_digit;
            store_single_digit = total_sum_single;
        }
        x_odd /= 100;
        digit_counter++;
    }
    // add numbers obtained above
    int sum_starting_from_last = store_single_digit + store_double_digit;

    // obtain sum of all numbers obtained above (through two separate processes)
    sum_total_digits = sum_starting_from_last + sum_every_other;

    // set new variables
    int last_two_digits;
    int last_digit;
    int digit_one;
    int digit_two;
    int digit;

    // determine whether the credit card is a VISA, MASTERCARD, AMERICAN EXPRESS, or INVALID
    if (sum_total_digits % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (digit_counter == 16)
        {
            last_two_digits = credit_card_number / 100000000000000;
            digit_two = last_two_digits % 10;
            digit_one = last_two_digits / 10;

            if (digit_two > 0 && digit_two < 6)
            {
                if (digit_one == 5)
                {
                    printf("MASTERCARD\n");
                }
                else if (digit_one == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (digit_one == 4)
            {
                    printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digit_counter == 15)
        {
            last_two_digits = credit_card_number / 10000000000000;
            digit_two = last_two_digits % 10;
            digit_one = last_two_digits / 10;

            if (digit_two == 4 || digit_two == 7)
            {
                if (digit_one == 3)
                {
                    printf("AMERICAN EXPRESS\n");
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
        else if (digit_counter == 13)
        {
            last_digit = credit_card_number / 1000000000000;
            digit_one = last_digit;

            if (digit_one == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}