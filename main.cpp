#include <iostream>
#include <string>

class Stack {
public:
    std::string pageTitle;
    std::string pageDescription;
    std::string pageURL;
    std::string dateAccessed;
    int i;

    //pointer to the array on the heap, created dynamically at runtime
    std::string *stringArrayPointer;
    int size;
    int topPointer = -1;
    int currentPage;

    //Stack(){
    //    topPointer = -1;
    //    for(int i = 0, i < size-1; i++){

    //    }
    //}

    //void setPageTitle(std::string pagetitle){
    //    pageTitle = pagetitle;
    //}
    //std::string getPageTitle(){
    //    return pageTitle;
    //}

    //void setPageDescription(std::string pagedescription){
    //    pageDescription = pagedescription;
    //}
    //std::string getPageDescription(){
    //    return pageDescription;
    //}

    //void setPageURL(std::string pageurl){
    //    pageURL = pageurl;
    //}
    //std::string getPageURL(){
    //    return pageURL;
    //}

    //void setDateAccessed(std::string dateaccessed){
    //    dateAccessed = dateaccessed;
    //}
    //std::string getDateAccessed(){
    //    return DateAccessed;
    //}

    void display(Stack browser){
        std::cout << "All values in the stack are " << std::endl;
        for(int i = browser.size; i >=0; i--){
            std::cout << browser.stringArrayPointer[browser.i] << std::endl;
        }
    }

    std::string pop(Stack *browser){
        // variable to setup to show that there is nothing to delete
        std::string noVal = "";
        // checks if toppointer is at -1
        if(browser->topPointer == -1){
            std::cout << "The stack is empty" << std::endl;
        } else {
            noVal = browser->stringArrayPointer[browser->topPointer];
            browser->topPointer--;
        }
        // if nothing is deleted, it will return -1 to show that there is nothing to delete
        return noVal;
    }

    // no pointer to browser because I am not modifying the browser. If I were to modify it, then I would need *.
    int peek(Stack browser, int position){
        int x = -1;
        //top - position + 1
        if(browser.topPointer-position + 1 < 0){
            std::cout << "Invalid position" << std::endl;
        } else {
            x = browser.stringArrayPointer[browser.topPointer - position + 1];
        }
        // returns -1 if there is nothing to peek at at position given by user
        return x;
    }

    void isEmpty(Stack *browser){
        if(browser->topPointer == -1){
            std::cout << "The Stack is empty." << std::endl;
        }
        else {
            std::cout << "The stack is not empty. " << std::endl;
        }
    }

    void isFull(Stack *browser){
        if(browser->topPointer == browser->size-1){
            std::cout << "The Stack is full." << std::endl;
        }
        else {
            std::cout << "The stack is empty. " << std::endl;
        }
    }

    // I need to be able to create website information. Perhaps constructor or can I pass in ... the class with the attributes only??
    std::string push(Stack *browser, std::string pagetitle, std::string pagedescription, std::string pageurl, std::string dateaccessed){
        if(browser->topPointer == browser->size-1){
            std::cout << "Stack overflow" << std::endl;
        } else {
            browser->topPointer++;
            browser->stringArrayPointer[browser->topPointer] = pagetitle;
            browser->stringArrayPointer[browser->topPointer] = pagedescription;
            browser->stringArrayPointer[browser->topPointer] = pageurl;
            browser->stringArrayPointer[browser->topPointer] = dateaccessed;
        }
    }

    std::string goBackPage(Stack *browser){
        if(browser->currentPage == -1){
            std::cout << "You cannot go back any further" << std::endl;
        } else {
            currentPage--;
        }
    }

    std::string goForwardPage(Stack *browser){
        if(browser->currentPage == stringArrayPointer->size-1){
            std::cout << "You cannot go forward any further" << std::endl;
        } else {
            currentPage++;
        }
    }

};


int main(){
    Stack browser;
    int option, value;
    std::string pageT, pageD, pageU, dateA;
    std::cout << "How many web pages do you want to insert in the stack?" << "\n";
    std::cin >> browser.size;
    browser.stringArrayPointer = new int[browser.size];


    do {
        std::cout << "1. Go back" << std::endl;
        std::cout << "2. Go forward" << std::endl;
        std::cout << "3. List all pages" << std::endl;
        std::cout << "4. Add page" << std::endl;
        std::cout << "5. Delete page" << std::endl;
        std::cout << "0. Exit the program" << std::endl;

        std::cin >> option;
        switch(option){
        case 1:
            browser.goBackPage(&browser);
            break;
        case 2:
            browser.goForwardPage(&browser);
            break;
        case 3:
            browser.display(browser);
            break;
        case 4:
            std::cout << "Enter a page title, page description, page URL, and date accessed: " << std::endl;
            std::getline(std::cin, pageT);
            std::getline(std::cin, pageD);
            std::cin >> pageU;
            std::getline(std::cin, dateA);

            browser.push(&value, pageT, pageD, pageU, dateA);
        case 5:
            std::cout << "You have deleted " << browser.pop(&browser) << std::endl;
            break;
        case 0:
            std::cout << "Exiting the program. Goodbye." << std::endl;
            return 0;
        default:
            std::cout << "Please enter 1- 5 or 0." << std::endl;
        }

    } while(option != 0);

    return 0;
}
