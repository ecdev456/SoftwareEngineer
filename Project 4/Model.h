#pragma once

using namespace std;

// All of this is hypothetical, not sure what Veronica and Tristan will be using but having flexibility for them is better
//How to deal with Time:  TREAT TIME AS A STRING, just do a string to string to check if time has arrived

class Library {


private:
    // Book Title [0][0] followed by the Book Author [0][1]
    string BookInfo[5][2] = { { "Philosophy Debate", "George Kay" } ,{ "Intro to Logic", "Jordan McNeil" },
        { "CS 1001", "David Yang" },{ "Database Architecture", "Greg Barish" },
        { "Human Biology", "Barbara Goche" } };
    int BookInstance[5] = { 1, 1, 1, 1, 1 }; // this will be an array of 1 or 0.   1: Book is Checked-In   0: Book is Checked-Out
    // will hold the Student NetID as a string (just default data here)
    string Student[5] = { "Name Here" , "Name Here" , "Name Here" , "Name Here" , "Name Here" };

    string TimeDue[5]; // Time is compared string to string in the format 'hh:mm'. Each [0], [1], [2] ,[3], [4] coresponds to the BookInfo, so treat them as together. i.e BookInfo[0] uses the TimeDue[0]
    int numStep = 0;


public:

    Library(){
        // set each field to be blank
        for (int i=0; i < 5; i++){
            Student[i] = {};
            TimeDue[i] = {};

        }
    }

    /*Notes: You may ask yourself why is there an "setBookInstance" fucntion when the "CheckOut" function can update that value for you?
     Answer: Well we are giving Veronica and Tristan the flexibility to use what they'd like.

     Commented functions need work, TEST your code prior to saying "Done".  All Getter functions are done and have been checked. Create you own main.cpp to test your things.
     If you think of more things to add, by all means add them.
     */

    //void CheckOut() // Input from user and things udpated are: Book they want, their NetID, TimeDue[i] is updated to a time due for that book, BookInstance updated
    void CheckOut(string bookStats, int bookInst, string time){ // input Book, instance, and time
        if(BookInfo[numStep][0] == bookStats){
        BookInstance[numStep] = bookInst;
        TimeDue[numStep] = time;
            numStep++;
        }


    }

    //void CheckIn()	//Result: Appropriate info has been reset to as they need to be
    // Note for checkin.. Not sure if I did this right. Please fix if incorrect
    void Checkin(int x){

            BookInfo[x][0] = {};
            BookInstance[x] = 0;
            TimeDue[x] = {};
            numStep--;
        }

    //void SetStudentInfo()	//Update Student info
    void SetStudentInfo(string name){ // Assuming Student info is only their name
        Student[numStep] = name;

    }
    //void SetTimeDue()	//update time due
    void SetTimeDue(string time) {
        TimeDue[numStep] = time;

    }
    //void setBookInstance() //update book isntance
    void setBookInstance(int bookInst){
        BookInstance[numStep] = bookInst;

    }
    //bool CheckTimeDue() //String to string comparison will return true or false
    bool CheckTimeDue(string time){
        if(TimeDue[numStep] == time)
        return true;
        else
            return false;
    }

    string GetBookInfo(int x) //Simply Returns: "BookName, Author" as a string
    {
        return (BookInfo[x][0] + ", " + BookInfo[x][1]);
    }
    string GetBook(int x) { return BookInfo[x][0]; }	//User gets the Book Name they want
    string GetAuthor(int x) { return BookInfo[x][1]; }	//User gets the Author name for the book they want
    int GetBookInstance(int x) { return BookInstance[x]; } //See if book is In or Out
    string GetStudentInfo(int x){ return Student[x];} //Return information on a particular student
    string GetTimeDue(int x){ return TimeDue[x]; } //Simply returns the string of the particular TimeDue[i] for comparisons

};
