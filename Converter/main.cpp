/*Converter
Purpose: To convert between binary, decimal and hex numbers
Author: David Cheah*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

void clearScreen();
void clearCin();
string dec2bin(string input);
string dec2hex(string input);
string bin2dec(string input);
string bin2hex(string input);
string hex2dec(string input);
string hex2bin(string input);
string checkBin(string input);
string checkHex(string input);

string in,dec,hex,bin;

void convertDec();
void convertHex();
void convertBin();

int main(int argc, char *argv[])
{
    char sel;
    
    int result;
start:
    cout << "\nChoose\n";
    cout << "(D)ecimal\n";
    cout << "(B)inary\n";
    cout << "(H)exadecimal\n";
    cout << "E(x)it\n";
    cin >> sel;
    
    switch(sel){
        case 'd':
             convertDec();
            break;
        case 'b':
             convertBin();
             break;
        case 'h':
             convertHex();
             break;
        case 'x':
             return EXIT_SUCCESS;
             break;
        default:
                clearScreen();
                goto start;
                break;  
        } 
    cout << endl;
    goto start;
    return EXIT_SUCCESS;
}

void convertDec()
{
     //Convert from Decimal
     clearScreen();
     clearCin();
     cout << "DEC:";     
     getline(cin,in);
     cout << "\nConverting " << in;
     cout << "\nDEC: " << in;
     cout << "\nBIN: " << dec2bin(in);
     cout << "\nHEX: " << dec2hex(in);
}

void convertHex()
{
     //Convert from Hex
     clearScreen();
     clearCin();
     cout << "HEX:";    
     getline(cin,in);
     cout << "\nConverting " << in;
     cout << "\nDEC: " << hex2dec(in);
     cout << "\nBIN: " << hex2bin(in);
     cout << "\nHEX: " << checkHex(in);     
}
void convertBin()
{
     //Convert from Bin
     clearScreen();
     clearCin();
     cout << "BIN:";     
     getline(cin,in);
     cout << "\nConverting " << in;
     cout << "\nDEC: " << bin2dec(in);
     cout << "\nBIN: " << checkBin(in);
     cout << "\nHEX: " << bin2hex(in);      
}

void clearScreen()
{
     system("cls");   
}

void clearCin()
{
    cin.clear();
    cin.ignore(10000,'\n');    
}

string dec2bin(string input)
{
    string output = "";
    char buffer [33];
    itoa (atoi(input.c_str()),buffer,2);
    output = string(buffer);
    output = checkBin(output);
    return output;
}

string dec2hex(string input)
{
    string output = "";
    char buffer [33];
    itoa (atoi(input.c_str()),buffer,16);
    output = string(buffer);
    output = checkHex(output);
    return output;
}

string bin2dec(string input)
{
    string output = "";
    ostringstream convert;
    bitset<8> bits(input);
    convert << bits.to_ulong();
    output = convert.str();
    
    return output;
}

string bin2hex(string input)
{
    string output(""),tmp;
    input = checkBin(input);
    
    for (int i=0;i<input.length();i+=4)
    {
    	tmp = input.substr(i,4);
    	if (!tmp.compare("0000"))
    	{
    		output = output + "0";
    	}
    	else if (!tmp.compare("0001"))
    	{
    		output = output + "1";
    	}
    	else if (!tmp.compare("0010"))
    	{
    		output = output + "2";
    	}
    	else if (!tmp.compare("0011"))
    	{
    		output = output + "3";
    	}
    	else if (!tmp.compare("0100"))
    	{
    		output = output + "4";
    	}
    	else if (!tmp.compare("0101"))
    	{
    		output = output + "5";
    	}
    	else if (!tmp.compare("0110"))
    	{
    		output = output + "6";
    	}
    	else if (!tmp.compare("0111"))
    	{
    		output = output + "7";
    	}
    	else if (!tmp.compare("1000"))
    	{
    		output = output + "8";
    	}
    	else if (!tmp.compare("1001"))
    	{
    		output = output + "9";
    	}
    	else if (!tmp.compare("1010"))
    	{
    		output = output + "A";
    	}
    	else if (!tmp.compare("1011"))
    	{
    		output = output + "B";
    	}
    	else if (!tmp.compare("1100"))
    	{
    		output = output + "C";
    	}
    	else if (!tmp.compare("1101"))
    	{
    		output = output + "D";
    	}
    	else if (!tmp.compare("1110"))
    	{
    		output = output + "E";
    	}
    	else if (!tmp.compare("1111"))
    	{
    		output = output + "F";
    	}
    	else
    	{
    		continue;
    	}
    }
    output = checkHex(output);
    return output;
}

string hex2dec(string input)
{    
     string tmp,output;
     //hex to binary
     tmp = hex2bin(input);
     
     //binary to decimal
     output = bin2dec(tmp);
     
     return output;
}

string hex2bin(string input)
{
    string output,tmp;
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    for (int i=0;i<input.length();i+=1)
    {
        tmp = input.substr(i,1);
        if (!tmp.compare("0"))
        {
        	output = output + "0000";
        }
        else if (!tmp.compare("1"))
        {
        	output = output + "0001";
        }
        else if (!tmp.compare("2"))
        {
        	output = output + "0010";
        }
        else if (!tmp.compare("3"))
        {
        	output = output + "0011";
        }
        else if (!tmp.compare("4"))
        {
        	output = output + "0100";
        }
        else if (!tmp.compare("5"))
        {
        	output = output + "0101";
        }
        else if (!tmp.compare("6"))
        {
        	output = output + "0110";
        }
        else if (!tmp.compare("7"))
        {
        	output = output + "0111";
        }
        else if (!tmp.compare("8"))
        {
        	output = output + "1000";
        }
        else if (!tmp.compare("9"))
        {
        	output = output + "1001";
        }
        else if (!tmp.compare("A"))
        {
        	output = output + "1010";
        }
        else if (!tmp.compare("B"))
        {
        	output = output + "1011";
        }
        else if (!tmp.compare("C"))
        {
        	output = output + "1100";
        }
        else if (!tmp.compare("D"))
        {
        	output = output + "1101";
        }
        else if (!tmp.compare("E"))
        {
        	output = output + "1110";
        }
        else if (!tmp.compare("F"))
        {
        	output = output + "1111";
        }
        else
        {
        	continue;
        }
    }    
    
    output = checkBin(output);
    return output;
}

string checkBin(string input)
{
     string zero = "0";
     string output = "";
     int count = 9 - (input.length() + 1);
     output = input;
     
     for (int i = 0; i < count; i++)
     {
         output = zero + output;
     }
     
     return output;   
}

string checkHex(string input)
{
     string zero = "0";
     string head = "0x";
     string output = "";
     transform(input.begin(), input.end(), input.begin(), ::toupper);
     output = input;
     
     if (input.length() < 2){
         output = zero + output;
     }
     output = head + output;
     return output;   
}

