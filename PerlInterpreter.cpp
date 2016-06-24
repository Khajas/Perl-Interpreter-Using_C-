/*+++++++++++++++++++++++++++++++++++++++++++
Date: June, 23 2016.
Programmer: Khaja Anwar Ali Siddiqui
Purpose: Interpreter for Perl.
Requirements: Your system should be equiped with perl installation.
++++++++++++++++++++++++++++++++++++++++++++*/
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
        int headerIndex, statementIndex;
        string header="#!/usr/bin/perl -w";     //This should be the first line for all the perl programs.
        string inputStatement;                  //store the input line
        ofstream w2File;                        //Output file streaming variable.
        // Write the commands to be executed
        string cmd0, cmd1, cmd2, cmd3;
        cmd0="chmod u+x tempFILE777";   // To change the file mode to be executable 'x'
        cmd1="./tempFILE777";           // Execute the file
        cmd2="rm tempFILE777";          // Remove the temporary file created.
        // Welcome message
        cout <<"This program is for the interpreter for PERL.\nWritten by Khaja Anwar Ali Siddiqui, NIU.\nEnter your statements and press the enter key.\nOnce you're done press ctrl+d or type 'exit', to exit the program;"<<endl;
        while(cin){     //As long as there are more lines to be interpreted.
                cout<<"> ";
                headerIndex=0, statementIndex=0;        //Reset the indecies to get new inputs.
                getline(cin,inputStatement);    // Get the line from the cmd
                if(inputStatement=="exit") break;
                w2File.open("tempFILE777");      //  open the new temporary file.
        // write the header
                while(headerIndex<header.length()){
                        w2File.put(header[headerIndex]);
                        headerIndex++;
                }
        //Give the newline
                w2File.put('\n');
        // Write the input statement
                while(statementIndex<inputStatement.length()){
                        w2File.put(inputStatement[statementIndex]);
                        statementIndex++;
                }
                w2File.close();         //Close the file now.
		// The file is now ready.
        // Execute the commands
                system(cmd0.c_str());                   //change the file to an executable one.
                system(cmd1.c_str());                   //Execute the file.
                system(cmd2.c_str());                   //Delete the file once executed.
                cout<<endl;
        }
        return 0;
}
/***************************              END OF SOURCE FILE              **********************************/
