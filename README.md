# **Project-Luna**

Philip Ramirez and Isabella Flynn

# Intro:
We created a lunar calendar that tells the user the moon phase of whatever date they input after the year 2000.

# Technical Description:
The pastYearstoDaysCalc int function calculates how many days have passed between the base date (01/01/2000) and the user inputted date minus one. We use the input year minus one because whatever the inputted date is does not necessarily count as a full year yet. We do this by using an incrementer in a for loop. The loop begins at 2000 and will increment through the years until it reaches the year that is before the user input. However, as it loops through these years, it will check whether or not the year meets the criteria for a leap year (which basically means it is both divisible by 4 and not divisible by 100 OR if it is divisible by 400). We are able to test the years using the modulus operator, which will tell us if it is divisible by the number we ask, as well as several relational operators like the not equal (!=) and the logical operators AND(&&) and OR (||). If the year the function is studying matches the criteria of the logic, it will increment the variable leapcount by one. Otherwise it will increment the variable nonleapcount by 1. After it completes every year in the for loop condition, it will multiply the variable leapcount by 366 and the variable nonleapcount by 365. Then add these two products. The function will return this value.

The isitaLeapYear function will take the user inputted year and checks if it fits the criteria of a leap year as described before. If it fits the criteria, the function will return the value 1. If not, it will return the value 0.

The monthstoDays function is a switch case that takes in the pointer to the struct lunaDate. Using pointer dereferences, the switch case takes in the argument of the month portion of theDate pointer to the struct that consists of the user input. Based on whatever the month is, the switch case will cycle through and add days accordingly for the months. Then, it will add the user inputted day from the pointer to the struct to whatever month to day value. The function will return the sum of whatever the switch case assigned the value to. This function is called if the function isitaLeapYear returns 0.
The monthstoDaysleap does the exact same thing, but takes into account the extra day for the leap year. This function is called if the function isitaLeapYear returns 1.

The totaldaysYAY function takes in the pointer to the struct as an argument. It checks if the isitaLeapYear function returned 0 or 1, and returns the sum of months and days accordingly. It adds the values from the pastYearstoDaysCalc function and the monthstoDays function (either leap or regular based on what isitaLeapYear returned).

The moonphase function takes in the variable lunastage as an argument. Lunastage basically utilizes the modulus operator to determine how many 28 day cycles have passed since 2000. Using the value of lunastage, we relate it to a 10 cycle period for different phases of the moon. 
NOTE: This means we used averages, which isn't necessarily reflective of the lunar cycle. 

Finally, our runprogram function basically sets up a pointer to the struct lunaDate. This pointer is consistently called upon and deferenced throughout the code. The function prompts the user to input values to be stored in the pointer to the struct. The location of each input of the struct is stored using the & and each individual aspect of the struct is referenced using theDate->the respective aspect. Using the user’s input, the program runs the pastDaystoYearsCalc function, then the moonphase function and will print a phrase accordingly.


# Example

![image](https://user-images.githubusercontent.com/90297435/146576955-c30fd72f-11eb-40cf-a070-0c2edb1ae47c.png))

![image](https://user-images.githubusercontent.com/91158069/146097800-10e0f994-eac8-430c-bde9-f3335b25bc61.png)

If you check an offical lunar calendar, you will see that the moon phase on December 18, 2021 is in fact a full moon.

# Link to Youtube Video
https://www.youtube.com/watch?v=ILF7BQgfUss
