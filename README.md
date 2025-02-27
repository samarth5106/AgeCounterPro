# AgeCounterPro

## Description
PreciseAgeCalc is a C++ program that calculates a person's exact age in years, months, days, and hours based on their birth details and current time. The program also considers:
- Leap year adjustments
- Time zone differences based on the country of birth
- Age calculation at the time of death if the person is not alive

## Features
- Calculates exact age up to hours
- Handles time zone variations
- Accounts for leap years
- Works for both living and deceased individuals

## How to Use
1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/PreciseAgeCalc.git
   ```
2. Navigate to the project directory:
   ```sh
   cd PreciseAgeCalc
   ```
3. Compile the program:
   ```sh
   g++ age_calculator.cpp -o age_calculator
   ```
4. Run the executable:
   ```sh
   ./age_calculator
   ```
5. Follow the on-screen prompts to enter birth details and country.
6. If the person is deceased, enter the date and time of death.

## Example Input
```
Enter country name: India
Enter birth year: 2000
Enter birth month: 5
Enter birth day: 10
Enter birth hour (24-hour format): 14
Is the person still alive (y/n): y
```

## Example Output
```
The person is 24 years, 9 months, 12 days, and 6 hours OLD in India.
```

## Requirements
- C++ compiler (G++ recommended)
- Works on Windows, macOS, and Linux

## Contributing
Feel free to contribute by creating pull requests or opening issues for enhancements and bug fixes.

## License
This project is licensed under the MIT License.


