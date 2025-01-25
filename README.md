# Elisabeth Molen 

This project contains a Makefile:
- To compile: make
- To run: make run

Files in Project:
- main.cpp: The main project file that includes the main() function.
- event.h: Interface to define the abstract Event class and its subclasses, Concert and Conference.
- event.cpp: Implementation of the Event class, as well as it subclasses, Concert and Conference.
- eventFactory.h: Interface to define the abstract EventFactory class and its subclasses, ConcertFactory and ConferenceFactory
- eventFactory.cpp: Implementation of the EventFactory class and its subclasses, ConcertFactory and ConferenceFactory
- searchingStrategy.h: Interface to define the abstract SearchingStrategy class, along with its subclasses EventNameSearch, EventLocationSearch, EventDateSearch, and TicketsAvailSearch.
- searchingStrategy.cpp: Implementation of the SearchingStrategy class, along with its subclasses EventNameSearch, EventLocationSearch, EventDateSearch, and TicketsAvailSearch.
- searchingContext.h: Interface to define the SearchingContext class
- searchingContext.cpp: Implementation of the SearchingContext class
- Makefile: A makefile that includes commands make, make run, and make clean
- README.md: Additional documentation for project.


Use of Inheritance:
- An Event class was created as an abstract class.
- Concert and Conference classes inherit publicly from the Event class.
- This allowed creation of some common features among Concert and Conference classes to be created in the Event class.
- New variables and methods specific to the subclasses could then be added to distinguish between Concert and Conference classes.
- Due to the open for extension principle, additional subclasses can easily be added in the future.
- Inheritance was also used in implementing Factory Method and Strategy Pattern (see those sections for details).

Use of Vectors of Pointers:
- Vectors of pointers help with using polymorphism.
- Pointers to Conference and Concert objects were created and stored in a vector of Event pointers. 
- Because they are all Event pointers, they could all be stored in the same vector, allowing for polymorphism.
- For example, different getDetails() functions were implemented in the Concert and Conference classes.  However, when the program iterated through the vector of Event pointers, getDetails() could be called on all pointers, and the version of getDetails() called was specific to whether it was a Concert or Conference.


Use of Design Patterns:

Factory Method 
- An EventFactory class was created to implement the Factory Method.
- EventFactory is an abstract class that establishes the general framework for a "factory" to create event objects.  
- Subclasses ConcertFactory and ConferenceFactory inherit publicly from EventFactory.
- EventFactory contains a pure virtual method createEvent() that was overridden in ConcertFactory and ConferenceFactory.
- The createEvent() method calls the constructor for the relevant class.
- The factory method encapsulates the user from the object creation process, hiding details of the implementation.
- The factory method will also ease the object creation process should new Event subclasses be added in the future.
- Note that my methods in my ConcertFactory and ConferenceFactory classes take user input via istream.  In a real world application the user input would be decoupled from these classes.  However, this was discussed with Dr. Wagner as a good solution for this project, as it simplifies my main() without requiring adding an extra class to take user input.

Strategy Pattern
- A SearchingContext class serves as an interface between the user and the searching process.  
- An abstract SearchingStrategy class was created as a general framework for a searching algorithm.  
- Different searching algorithms were then implemented in publicly inherited subclasses of SearchingStrategy.
- The design pattern fully abstracts the searching process and also encapsulates the user from the details of the searching algorithms.
- This also allows for easy switching between the algorithms based upon what type of the search the user selects to use at run-time.


Discussion of Challenges and Future Improvements:
- This assignment was very helpful for exploring inheritance, polymorphism, and design patterns.
- One of my early challenges was determining how to track dates and times. I wanted my program to be able to interact with time since epoch, so I could implement the isUpcoming() method.  Eventually, I found the ctime library, which helped me in my design.
- I also ran into some challenges implementing my Session struct within my Conference class.  However, I am very glad I attempted this feature because it helped me better understand pointers and polymorphism.
- Finally, the project is not perfectly adjusted to account for user error when making selections. I attempted to account for many situations where user error could cause major issues in the program (by having the program terminate rather than, for example, enter an infinite loop).  However, there are likely existing places where improvements could be made.
- The program does not currently have a persistent database and instead starts up each time with a few Event objects.  Future improvements could, of coures, incorporate a persistent database.  

