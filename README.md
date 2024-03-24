Requirement (a) 
Sort the list of cars as follows: if the year of manufacture differs, then display in descending order of the years, otherwise, if the number of kilometers differs, then sort ascending by the number of kilometers. In case of the same number of kilometers, sort in descending order by average consumption. Then display in the format:

The car <brand> with the registration number <number> has traveled <nr_km>km and consumed <average_consumption> liters.
Requirement (b) 
Calculate the total amount paid by the dealership for the number of kilometers traveled by each car and display it with exactly two decimal places.

Requirement (c) 
After reading the character 'c' representing the requirement, read cars again until EOF, in the same format as above, and add them to the existing collection. Then display the total number of kilometers traveled by cars, as well as the average consumption per hundred kilometers, with exactly three decimal places, in the format:

<total_distance> km
<average_consumption> L/100km
Requirement (d) 
Create a statistic of the number of cars of each type (petrol, diesel, electric, hybrid), namely how many cars of that type exist and display it in the format:

petrol -> <nr_petrol_cars>
diesel -> <nr_diesel_cars>
electric -> <nr_electric_cars>
hybrid -> <nr_hybrid_cars>
Requirement (e) 
Analyze the database and determine which registration numbers are NOT correct. A correct registration number consists of one or two letters, followed by two or three digits, followed by exactly three letters. All letters must be uppercase. If a number is not correct, display:

<registration_number>: invalid registration number

Input
The first line contains an integer n, representing the number of cars to be read. The following n lines contain information about the car, in the format:

<brand> <fuel_type> <registration_number> <manufacture_year> <average_consumption> <number_km>
The last line contains a character from the range [a-e] representing the requirement to be addressed.
