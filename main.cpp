#include <iostream>
#include <string>

//class called Stack
class Stack {
    // making everything public
public:
    std::string pageTitle;
    std::string pageDescription;
    std::string pageURL;
    std::string dateAccessed;
    int i;

    //pointer to the array on the heap, created dynamically at runtime
    std::string *stringArrayPointer;
    // size for dynamic memory allocation at runtime
    int size;
    // top pointer is default to -1 because there would be nothing in the stack
    int topPointer = -1;
    // annotates the current page the browser is looking at
    int currentPage;

    // display method to view everything in stack. After sometime, I decided that overloading the << operator to display the object browser directly would suffice. I don't think I would need to loop through the object attributes if I can overload and display the whole object directly??
    void display(Stack browser){
        std::cout << "All values in the stack are " << std::endl;
        for(int i = browser.size; i >=0; i--){
            std::cout << browser.stringArrayPointer[browser.i] << std::endl;
        }
    }

    // pop function modifies the stack, so we are taking a pointer to reference it when we call it in main
    std::string pop(Stack *browser){
        // variable to setup to show that there is nothing to delete
        std::string noVal = "";
        // checks if toppointer is at -1
        if(browser->topPointer == -1){
            std::cout << "The stack is empty" << std::endl;
        } else {
            // sets noVal to the value of what is in browsers toppointer
            noVal = browser->stringArrayPointer[browser->topPointer];
            // decrements top pointer in stack
            browser->topPointer--;
        }
        // if nothing is deleted, it will return -1 to show that there is nothing to delete
        return noVal;
    }

    // no pointer to browser because I am not modifying the browser. If I were to modify it, then I would need *.
    std::string peek(Stack browser, int position){
        std::string x = "";
        //top - position + 1
        if(browser.topPointer-position + 1 < 0){
            std::cout << "Invalid position" << std::endl;
        } else {
            x = browser.stringArrayPointer[browser.topPointer - position + 1];
        }
        // returns -1 if there is nothing to peek at at position given by user
        return x;
    }

    // simple method to check if the stack is empty or not. Pass by value because no modification to browser is being made.
    void isEmpty(Stack browser){
        if(browser->topPointer == -1){
            std::cout << "The Stack is empty." << std::endl;
        }
        else {
            std::cout << "The stack is not empty. " << std::endl;
        }
    }

    // simple method to check if the stack if fill or not. Pass by value because no modification to browser is being made.
    void isFull(Stack browser){
        if(browser->topPointer == browser->size-1){
            std::cout << "The Stack is full." << std::endl;
        }
        else {
            std::cout << "The stack is empty. " << std::endl;
        }
    }

    // I need to be able to create website information. Perhaps constructor or can I pass in ... the class with the attributes only??
    void push(Stack *browser, std::string pagetitle, std::string pagedescription, std::string pageurl, std::string dateaccessed){
        if(browser->topPointer == browser->size-1){
            std::cout << "Stack overflow" << std::endl;
        } else {
            // here is where I had a hard time. I wasn't sure if I could pass all the values here directly, or if I needed a constructor to do so??
            browser->topPointer++;
            browser->stringArrayPointer[browser->topPointer] = pagetitle;
            browser->stringArrayPointer[browser->topPointer] = pagedescription;
            browser->stringArrayPointer[browser->topPointer] = pageurl;
            browser->stringArrayPointer[browser->topPointer] = dateaccessed;
        }
    }

    // method I created to move the current pointer down in the stack if user selected "go back" in main menu.
    void goBackPage(Stack *browser){
        if(browser->currentPage == -1){
            std::cout << "You cannot go back any further" << std::endl;
        } else {
            currentPage--;
        }
    }

    // method I created to move the current pointer up in the stack if user selected "go forward" in main menu.
    void goForwardPage(Stack *browser){
        if(browser->currentPage == browser->size-1){
            std::cout << "You cannot go forward any further" << std::endl;
        } else {
            currentPage++;
        }
    }

    //overloading << operator to directly display information in browser object with std::cout stream
    std::ostream &operator<<(std::string &stream, const Stack &browse){
        // displays each attribute of Stack class
        stream << browse.pageTitle << " " << browse.pageDescription << " " << browse.pageURL << " " << browse.dateAccessed << std::endl;
        // return the overloaded << stream
        return stream;
    }

};


int main(){
    Stack browser;
    int option, value, size;
    std::string pageT, pageD, pageU, dateA;
    std::cout << "How many web pages do you want to insert in the stack?" << "\n";
    std::cin >> size;
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
            std::cout << &browser;
            break;
        case 4:
            std::cout << "Enter a page title, page description, page URL, and date accessed: " << std::endl;
            std::getline(std::cin, pageT);
            std::getline(std::cin, pageD);
            std::getline(std::cin, pageU);
            std::getline(std::cin, dateA);

            browser.push(&browser, pageT, pageD, pageU, dateA);
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
