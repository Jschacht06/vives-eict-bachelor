# Sort your Tasks

# Base class

* Create a base class `Task` with the attributes `dueDate`, `description`, `priority` and `recurrence`.
* The constructor only takes a duedate and description.
* The priority can be set to Low, Medium or High. The default is Medium.
* The recurrence can be set to Once, Day, Week, Month and Year. The default is Once.
* If the priority is set different from Medium the description is prefixed by "LOW PRIORITY: " or "HIGH PRIORITY: ".
 
#  Sub Class

* Create a sub class `RecurringTask`.
* The constructor only takes a duedate, description and recurrence.

# UML diagram

* Create the UML diagram 

# Creating some tasks in the console application

* Create a task `Stop using ChatGPT` with a duedate = today + 7 days.
* Create a recurringtask `Make summary of this course` with a duedate = today + 2 days and a weekly recurrence
* Create a recurringtask `Pay the rent` with a duedate = today + 5 days and a montly recurrence
* Create a task `Go to Nerdland` with a duedate = today + 45 days and set the priority to high
* Add each of these tasks to a list.
* Output the ordered list by duedate, recurring tasks are filled in until the end of this year.




