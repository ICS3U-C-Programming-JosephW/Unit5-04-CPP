// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: May 15, 2025
/* This program is a calculator that allows the user
to enter a sign, a first number, and a second number
to perform a variety of operations (+, -, *, /, %). */

/* Include the cmath library
for the floor function. */
#include <cmath>
/* Include the iostream library for
input and output functionalities. */
#include <iostream>
/* Include the string library to
adhere to style guidelines. */
#include <string>

/* Define a function to calculate the mathematical
operation performed on two numbers. */
float calculate(char sign, float firstNumber, float secondNumber) {
    // Initialize the calculator result as a float  to be used later.
    float calculatorResult;
    // Check if the user wanted to perform addition.
    if (sign == '+') {
        /* Set the calculator result
        to the sum of the two numbers. */
        calculatorResult = firstNumber + secondNumber;
    } else if (sign == '-') {
        /* Otherwise, check if the user
        wanted to perform subtraction. */
        /* Set the calculator result to the
        difference of the two numbers. */
        calculatorResult = firstNumber - secondNumber;
    } else if (sign == '*') {
        /* Otherwise, check if the user
        wanted to perform multiplication. */
        /* Set the calculator result to
        the product of the two numbers. */
        calculatorResult = firstNumber * secondNumber;
    } else if (sign == '/') {
        /* Otherwise, check if the user
        wanted to perform division. */
        /* Set the calculator result to
        the quotient of the two numbers. */
        calculatorResult = firstNumber / secondNumber;
    } else {
        /* Otherwise, the only other
        option is to perform modulo. */
        /* Set the calculator result to
        the remainder of the two numbers.
        Use an alternate equation since
        % is not allowed for floats. */
        calculatorResult = firstNumber - std::floor(
        firstNumber / secondNumber) * secondNumber;
    }

    /* Return the result of the calculator
    after performing the desired operation. */
    return calculatorResult;
}

// Runs the main function.
int main() {
    /* Declare the user sign variable as a string
    because characters are harder to work with. */
    std::string userSign;
    // Declare the user's first number as a string.
    std::string userFirstNumberStr;
    // Declare the user's second number as a string.
    std::string userSecondNumberStr;

    // Display the introduction to the program.
    std::cout << "\nThis program will perform "
    << "calculations between two numbers.\n";
    // Ask the user to enter their mathematical operation.
    std::cout << "\nEnter the operation you want to perform (+, -, *, /, %): ";
    /* Store the mathematical operation in the
    user sign variable. */
    std::cin >> userSign;

    // Before proceeding, check if the entered sign was +, -, *, /, or %.
    if ((userSign == "+")
    || (userSign == "-")
    || (userSign == "*")
    || (userSign == "/")
    || (userSign == "%")) {
        // Continue and ask for the user's first number.
        std::cout << "\nEnter the first number: ";
        /* Store the user's first number in
        the corresponding string variable. */
        std::cin >> userFirstNumberStr;
        // Try to validate the user's first number.
        try {
            // Attempt to convert the user's first number into a float.
            float userFirstNumberFloat = std::stof(userFirstNumberStr);
            // Ask for the user's second number as a string.
            std::cout << "\nEnter the second number: ";
            /* Store the user's second number in the
            corresponding string variable. */
            std::cin >> userSecondNumberStr;
            // Try to validate the user's first number.
            try {
                // Attempt to convert the user's second number into a float.
                float userSecondNumberFloat = std::stof(userSecondNumberStr);
                /* Check if the user entered / or % for the
                sign and their second number equals zero. */
                if (((userSign == "/") || (userSign == "%"))
                && (userSecondNumberFloat == 0)) {
                    /* Display to the user that the result is
                    undefined since the divisor cannot be zero. */
                    std::cout << "\nThe result of " << userFirstNumberFloat
                    << " " << userSign << " " << userSecondNumberFloat
                    << " is undefined.\n";
                } else {
                    // Otherwise, the answer will be valid and not undefined.
                    /* Assign the calculator function with the sign and
                    numbers to the user result variable. Index the sign
                    string at zero to make it a character. */
                    float userResult = calculate(userSign[0],
                    userFirstNumberFloat, userSecondNumberFloat);
                    // Display the result to the user.
                    std::cout << "\nThe result of " << userFirstNumberFloat
                    << " " << userSign << " " << userSecondNumberFloat
                    << " is " << userResult << ".\n";
                }
            }
            /* Runs if std::stof() could not convert
            the user's second number into a float. */
            catch (std::invalid_argument) {
                /* Display to the user that their
                second number is not a valid number. */
                std::cout << "\n" << userSecondNumberStr
                << " is not a valid number.\n";
            }
        }
        /* Runs if std::stof() could not convert
        the user's first number into a float. */
        catch (std::invalid_argument) {
            /* Display to the user that their
            first number is not a valid number. */
            std::cout << "\n" << userFirstNumberStr
            << " is not a valid number.\n";
        }
    } else {
        // Otherwise, the user entered an unknown operation.
        /* Display to the user that their
        entered operation is unrecognized. */
        std::cout << "\n" << userSign
        << " is not a recognized operation.\n";
    }
}
