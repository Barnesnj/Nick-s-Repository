/* Grocery Program
*  Nicholas Barnes
*  6/17/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string word;
    map<string, int> frequency;
    ifstream file("CS210_Project_Three_Input_File.txt");  //this is the provided data file for the program to search through

    while (file >> word)
    {
        ++frequency[word];
    }

    file.close();  //finds and stores the provided data file

    cout << "------------------------------------------------------------" << endl;  //prints program welcome message
    cout << "* Welcome to the Corner Grocer Item Search History Program *" << endl;
    cout << "------------------------------------------------------------" << endl;

    int choice;
    do  //creates display for menu prompts to the user
    {
        cout << "Press 1 to:\n";
        cout << "1. Input the name of the item you wish to search for to get its total purchase amount.\n";
        cout << "Press 2 to:\n";
        cout << "2. Print the list with numbers that represent the frequency of all items purchased.\n";
        cout << "Press 3 to:\n";
        cout << "3. Print the same frequency information for all the items in the form of a histogram.\n";
        cout << "Press 4 to:\n";
        cout << "4. Exit the program.\n";

        cin >> choice;  //allows the user to input their menu choice

        switch (choice)  //creates the four search option scenarios
        {
        case 1: //single item search scenario
        {
            string searchWord;
            cout << "Enter the word you want to search for: ";
            cin >> searchWord;

            if (frequency.find(searchWord) != frequency.end())
            {
                cout << searchWord << " appears " << frequency[searchWord] << " times in the file." << endl;
            }
            else
            {
                cout << searchWord << " does not appear in the file." << endl;
            }

            break;
        }
        
        case 2: //total list scenario
        {
            for (auto& it : frequency)
            {
                cout << it.first << ' ' << it.second << endl;
            }

            break;
        }
        case 3:  //histogram scenario
        {
            for (auto& it : frequency)
            {
                cout << it.first;

                for (int i = 0; i < it.second; ++i)
                {
                    cout << '*';
                }

                cout << endl;
            }

            break;
        }
        case 4:  //program exit scenario
        {
            cout << "Thank you for using the Corner Grocer Item Search Program. Goodye!";
            return 0;
        }
        default:
        {
            cout << "Invalid choice." << endl;
        }
        }
    } while (choice != 4);  //allows the user to to continue searching using different scenarios until they choose to exit the program

    return 0;
}