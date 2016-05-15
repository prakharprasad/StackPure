/*
  **********************************************************************

  	     	This application demonstrates the concept
     		of stack data-structure  using linked-list

  **********************************************************************
  *
  *  Copyright (C) 2011   Prakhar Prasad,  prakharpd(at-sign)gmail(dot)com
  *  http://prakharpd.blogspot.com/
  *
  *  This program is free software: you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation, either version 3 of the License, or
  *  any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>

  **********************************************************************
  Compile: g++ stackpure.cpp -o stackpure
  Execute: ./stackpure (Unix) or stackpure.exe (Windows)

*/

#include<iostream>
#include<cstdlib>

using namespace std;
int shift(int n)			//for generating spaces
{
    for(int i = 1; i <= n; i++)
        cout << ' ';
}
int len(int dt)			//for calculating length of number supplied
{
    if(dt == 0) {
        return 1;
    }
    int len = 0;
    while(dt) {
        dt /= 10;
        ++len;
    }
    return len;
}

int draw_hborder(int c)		//for drawing table borders
{
    if(c > 1)
        c = c * 2;
    cout << "+";
    for(int i = 1; i <= c; i++) {
        cout << "-";
    }
    cout << "+";
    cout << endl;
}
int draw_hline(int c)		//for drawing row separator line
{
    if(c > 1)
        c = c * 2;
    for(int i = 1; i <= c; i++) {
        cout << '-';
    }
}
int genblock(int c, const int s = -1)	//for generating a complete row
{
    cout << "|";
    if(s != -1) {
        shift((c / 2));
        cout << s;
        int tmp = len(s);
        if(tmp != c) {
            while(tmp != c) {
                shift(1);
                ++tmp;
            }
        }
        shift(c / 2);
    } else {
        draw_hline(c);
    }
    cout << "|" << endl;
}

struct node {
    //Linked List
    int data;

    node * next;

};
node * top = NULL, *ptr = NULL;
int push(const int mem)		//push some data to the stack
{
    ptr = new node;
    if(!ptr) {
        cout << "\nOOM/Stack Overflow";	//if no more memory is left
        return 0;
    }
    ptr->data = abs(mem);
    if(top == NULL) {
        top = ptr;
        top->next = NULL;
    } else {
        ptr->next = top;
        top = ptr;
    }
    return 1;
}

int pop()				//for popping (deleting) data
{
    int tmp;
    if(top == NULL) {
        cout << "\nStack Underflow (Nothing to POP)";
        return 0;
    }
    tmp = top->data;
    cout << "\nAre you sure ? " << tmp << " will be deleted (Y/N) ";
    char ch;
    cin >> ch;
    if((char(ch) == 'y') ||(char(ch) == 'Y')) {
        ptr = top;
        top = top->next;
        delete ptr;
        cout << endl << tmp << " has been POPed" << endl;
    }
    return 1;
}

int show_stack()			//display stack content
{
    ptr = top;
    int c = 0, max = 0;
    if(ptr == NULL) {
        cout << "\nNothing to show !";
        return 0;
    }
    while(ptr != NULL) {
        if(ptr->data > max) {
            max = ptr->data;
        }
        ptr = ptr->next;
        c++;
    }
    if(c > 0) {
        int x = len(max);
        if(x % 2 != 0 && x > 1) {
            x++;
        }
        ptr = top;
        draw_hborder(x);
        while(ptr != NULL) {
            genblock(x, ptr->data);
            ptr = ptr->next;
            if(ptr != NULL) {
                genblock(x);
            }
        }
        draw_hborder(x);
    }
}

int main()
{
main:
    int tmp;
    cout << "\n\nSelect your choice !\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Show\n";
    cout << "4. Exit\n";
    cin >> tmp;
    if(!cin) {
        cout << "\nPlease enter a number, not something else!";
        cin.clear();		// clear the "fail" condition
        while(cin.get() != '\n');
        goto main;
    }
    switch(tmp) {
        case 1:
            cout << "\nEnter Some Number ->";
            cin >> tmp;
            if(!cin) {
                cout << "\nPlease enter a number, not something else!";
                cin.clear();	// clear the "fail" condition
                while(cin.get() != '\n');
                goto main;
            }
            push(tmp);
            cout << "\nPushed !";
            break;
        case 2:
            pop();
            break;
        case 3:
            show_stack();
            break;
        case 4:
            return 0;
        default:
            cout << "\nInvalid";
    }
    goto main;
}