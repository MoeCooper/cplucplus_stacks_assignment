#include <iostream>

class Stack {
private:
    std::string pageTitle;
    std::string pageDescription;
    std::string pageURL;
    std::string dateAccessed;

public:
    //pointer to the array on the heap, created dynamically at runtime
    std::string *stringArrayPointer;
    int size;
    int topPointer;
    int currentPage;

    Stack(){
        topPointer = -1;
        for(int i = 0, i < size-1; i++){

        }
    }

    void setPageTitle(std::string pagetitle){
        pageTitle = pagetitle;
    }
    std::string getPageTitle(){
        return pageTitle;
    }

    void setPageDescription(std::string pagedescription){
        pageDescription = pagedescription;
    }
    std::string getPageDescription(){
        return pageDescription;
    }

    void setPageURL(std::string pageurl){
        pageURL = pageurl;
    }
    std::string getPageURL(){
        return pageURL;
    }

    void setDateAccessed(std::string dateaccessed){
        dateAccessed = dateaccessed;
    }
    std::string getDateAccessed(){
        return DateAccessed;
    }


    //int size(Stack browser){
    //    for(int i = browser.top; i>=0; i--){
    //        std::cout << browser.S[i];
    //    }
    //}

    int pop(Stack *browser){
        // variable to setup to show that there is nothing to delete
        int noVal = -1;
        // checks if toppointer is at -1
        if(browser->topPointer == -1){
            std::cout << "The stack is empty" << std::endl;
        } else {
            x = browser->stringArrayPointer[browser->topPointer];
            browser->topPointer--;
        }
        // if nothing is deleted, it will return -1 to show that there is nothing to delete
        return noVal;
    }

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
        if(topPointer == -1){
            std::cout << "The Stack is empty." << std::endl;
        }
        else {
            std::cout << "The stack is not empty. "
        }
    }

    void isFull(Stack *browser){
        if(browser->topPointer == browser->size-1){
            std::cout << "The Stack is full." << std::endl;
        }
        else {
            std::cout << "The stack is empty. "
        }
    }

    // I need to be able to create website information. Perhaps constructor or can I pass in ... the class with the attributes only??
    std::string push(Stack *browser, std::string pagetitle, std::string pagedescription, std::string pageurl, std::string dateaccessed){
        if(browser->topPointer == browser->size-1){
            std::cout << "Stack overflow" << std::endl;
        } else {
            browser.top++;
            browser.stringArrayPointer[browser.topPointer] = pagetitle;
            browser.stringArrayPointer[browser.topPointer] = pagedescription;
            browser.stringArrayPointer[browser.topPointer] = pageurl;
            browser.stringArrayPointer[browser.topPointer] = dateaccessed;
        }
    }

    std::string goBackPage(Stack *browser){
        if(browser.currentPage == -1){
            std::cout << "You cannot go back any further" << std::endl;
        } else {
            currentPage--;
        }
    }

    std::string goForwardPage(Stack *browser){
        if(browser.currentPage == stringArrayPointer.size-1){
            std::cout << "You cannot go forward any further" << std::endl;
        } else {
            currentPage++;
        }
    }

};


int main(){
    Stack browser;
    int option, vlaue;
    std::cout << "How many web pages do you want to insert in the stack?" << "\n";
    std::cin >> browser.size;
    browser.stringArrayPointer = new int[browser.size];
    topPointer = -1;

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
            std::cout<< "Enter a site to push into the stack" << std::endl;
            std::cin >> value;
            browser.push(value);
            break;
        case 2:

        }





    } while(option != 0);

    return 0;
}
