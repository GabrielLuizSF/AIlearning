
#include <fstream>
#include <iostream>

using namespace std;

string phrase;

class Learner {
public:
    void respond(string phrase);    
};



void Learner::respond(string phrase){
    fstream memory;
    memory.open("memory/memory.txt", ios::in);    

  
    while( !memory.eof() ){    
        string identifier;
        getline(memory,identifier);   

        if(identifier == phrase){    
            string response;
            getline(memory,response);   
              cout << "\nAI> ";
              cout << response << endl;  
            return;   
        }
    }

    memory.close();   
    memory.open("memory/memory.txt", ios::out | ios::app);    
    memory << phrase << endl;   


    string userResponse;
    cout<< "\nI don't know how to respond to that yet!";
    cout<<"\nPlease enter the ideal response to the query: \""<< phrase<< "\"\n" << endl;   

    getline(cin, userResponse);   
    userResponse=userResponse+" "; 
    memory << userResponse << endl;    
    memory.close();  
}


void welcome() {

cout << ""
"  ________________________________________________\n"
"|    _________________________________________     |\n"
"|   |                                         |    |\n"
"|   |  AI> Welcome                            |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |                                         |    |\n"
"|   |_________________________________________|    |\n"
"|                                                  |\n"
"|__________________________________________________|\n"
"      |___________________________________|\n"
"                 |             |\n"
"                 |             |\n"
"  ______________________________________________   \n";


}


main(){
    Learner AI;   
    welcome();
    
    for(;;){
        cout << "\nYou> ";   
        string phrase;
        getline(cin, phrase);   

        AI.respond(phrase);   
    }
}