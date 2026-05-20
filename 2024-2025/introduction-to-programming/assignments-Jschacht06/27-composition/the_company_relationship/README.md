# The Company Relationship

## Association Relationship

The manager of a company `has a` swipe card by which he enters the company premises.

* Create a class `Manager` and a class `SwipeCard`

The manager object and the swipe card object use each other but they have their own object life time.
In other words, they can exist without each other.
The most important point in this relationship is that there is no single owner.

## Aggregation Relationship

The manager `has many` workers who work under him.

* Create the class `Worker` and update the class `Manager` with a list of workers.

The next relationship denotes the same type of relationship like association but with a difference that one of them is an owner.
So as per the requirement, the Manager object will own Worker objects.
The child Worker objects can not belong to any other object. For instance, a Worker object cannot belong to a SwipeCard object.

But… the Worker object can have its own life time which is completely disconnected from the Manager object. Looking from a different perspective, it means that if the Manager object is deleted, the Worker object does not die.

## Composition Relationship

Manager `has the responsibility` of ensuring that the project is successful.
Manager's salary will be judged based on project success.

This means that:

* Manager and the project objects are dependent on each other.
* The lifetimes of both the objects are the same. In other words, the project will not be successful if the manager is not good, and the manager will not get good increments if the project has issues.

* Create the class `Project`.

In this relationship, both objects are heavily dependent on each other. In other words, if one goes for garbage collection the other also has to be garbage collected, or putting from a different perspective, the lifetime of the objects are the same.

## Code completion

Now complete your classes and test them with a console application.