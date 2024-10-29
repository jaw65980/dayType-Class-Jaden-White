
#include <iostream>
#include <iomanip>
using namespace std;

class dayType
{
public:
    void test()
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
    string daysOfweek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    int dayset = 0;
    string response;

    void nextDay()
    {
        if (dayset >= 6)
        {
            dayset = -1;
        }
        dayset++;
        cout << endl;
        test();
    }

    void previousDay()
    {
        if (dayset <= 0)
        {
            dayset = 7;
        }
        dayset--;
        cout << endl;
        test();
    }

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
        test();
    }

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
        test();
    }
};

int main()
{
    dayType Days;
    Days.test();
}
