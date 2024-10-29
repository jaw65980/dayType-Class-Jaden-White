
#include <iostream>
#include <iomanip>
using namespace std;

//All the functions and variables are held in the dayType class.
class dayType
{
public:
    //This function both prints the day of the week and allows users to make an input that will call another function depending on what they type. 
    // Do note these responses are case sensitive.
    void inputprompt()
    {
        cout << "The day is " << daysOfweek[dayset] << ". What would you like to do?" << endl;
        cout << "Type Next to go to the next day." << endl;
        cout << "Type Previous to go to the previous day." << endl;
        cout << "Type Set to set a new day." << endl;
        cout << "Type Add to add days to the current day." << endl;

        cin >> response;
        if (response == "Next")
        {
            nextDay();
        }

        if (response == "Previous")
        {
            previousDay();
        }

        if (response == "Set")
        {
            setDay();
        }

        if (response == "Add")
        {
            addDays();
        }
    }
private:
    //These are the main variables the program uses in its functions.
    string daysOfweek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    int dayset = 0;
    string response;

    //This function will add an index to the table which allows it to display the next day.
    //If the index goes to 6, the index will drop to -1 so the next index can be 0. This turns the day from Saturday to Sunday.
    void nextDay()
    {
        if (dayset >= 6)
        {
            dayset = -1;
        }
        dayset++;
        cout << endl;
        inputprompt();
    }

    //This function will subtract an index from the table which allows it to display the previous day.
    //Like the nextDay function, if the index goes under 0, the index will rise to 7. This will turn Sunday to Saturday.
    void previousDay()
    {
        if (dayset <= 0)
        {
            dayset = 7;
        }
        dayset--;
        cout << endl;
        inputprompt();
    }

    //This function asks the user what day of the week they'd like to set. 
    //Depending on the answer, the index will change to a specific number which correlates with the desired day of the week.
    void setDay()
    {
        cout << endl << "What would you like to set the day to?" << endl;
        string userday;
        cin >> userday;

        if (userday == "Sunday")
        {
            dayset = 0;
        }

        if (userday == "Monday")
        {
            dayset = 1;
        }

        if (userday == "Tuesday")
        {
            dayset = 2;
        }

        if (userday == "Wednesday")
        {
            dayset = 3;
        }

        if (userday == "Thursday")
        {
            dayset = 4;
        }

        if (userday == "Friday")
        {
            dayset = 5;
        }

        if (userday == "Saturday")
        {
            dayset = 6;
        }
        cout << endl;
        inputprompt();
    }

    //This function allows you to add any given number of days and find what day of the week it will land on.
    //The program will add to the dayset index depending on the input the user gives.
    //If the dayset index is greater than or equal to 7, the index will go back down to 0 to create a loop.
    //This continues until the number of days the user input has been reached.
    void addDays()
    {
        int addeddays = 0;
        int maxaddeddays;
        cout << endl << "How many days would you like to add to the current day?" << endl;
        cin >> maxaddeddays;
        for (addeddays; addeddays < maxaddeddays; addeddays++)
        {
            dayset++;
            if (dayset >= 7)
            {
                dayset = 0;
            }
        }
        cout << endl;
        inputprompt();
    }
};

//This function calls the class.
int main()
{
    dayType Days;
    Days.inputprompt();
}
