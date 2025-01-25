/*
* File: searchingContext.h
* -------------
* This interface defines the SearchingContext class
*/

#ifndef _searchingContext_h
#define _searchingContext_h

#include "event.h"
#include <string>
#include <vector>
#include "searchingStrategy.h"

/*
 * Class: SearchingContext
 * -----------------------
 * Class to provide a searching context to further encapsulates the SearchingStrategy subclasses from the user.
 */
class SearchingContext {

    private:
        // SearchingStrategy pointers allow objects pointers of any of SearchingStrategy's subclasses to be used.
        SearchingStrategy* searchingStrategy;


    public:
        // Constructor for SearchingContext class
        SearchingContext(SearchingStrategy* csearchingStrategy);

        SearchingStrategy* getSearchingStrategy();

        // Sets the SearchingStrategy for the SearchingContext.
        // Object pointers of any of SearchingStrategy's subclasses can be used.
        void setSearchingStrategy(SearchingStrategy* csearchingStrategy);

        // Method that performs the searching process (i.e., carries out the searching algorithm).
        std::vector<Event*> performSearch(std::vector<Event*> events);

        // Destructor for SearchingContext class.
        ~SearchingContext(){}

};


#endif