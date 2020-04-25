//  main.cpp
//  searchbook
//
//  Created by Chang Deng on 2020/4/25.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

//people struct

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
    
};

// address books
struct Adderssbooks
{
    struct Person personArr [MAX];
    int m_Size;
    
};

// show menu
void showMenu()
{
    cout << "********************************" << endl;
    cout << "*****   1. add people      *****" << endl;
    cout << "*****   2. show people     *****" << endl;
    cout << "*****   3. delete people   *****" << endl;
    cout << "*****   4. search people   *****" << endl;
    cout << "*****   5. edit people     *****" << endl;
    cout << "*****   6. move all people *****" << endl;
    cout << "*****   0. exit            *****" << endl;
    cout << "********************************" << endl;
}

void addPerson(Adderssbooks * p)
{
    // 判断通讯录是不是满了
    if (p -> m_Size == MAX)
    {
        cout << "The adderss book is full, can not add one more person " << endl;
    }
    else
    {
        // add person
        // add name
        
        string name;
        cout << "please add name : ";
        cin >> name;
        p -> personArr[p -> m_Size].m_Name = name;
        
        // add sex
        cout << "please input a sex, 1 ~ male, 2 ~ female : ";
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                p -> personArr[p -> m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "invalid number, please input again: ";
            }
        }
        
        // add age
        
        cout << "please input age : ";
        int age;
        while (true)
        {
            cin >> age;
            if (age < 0 || age > 150)
            {
                cout << "wrong input, please input another age ";
            }
            else
            {
                p -> personArr[p -> m_Size].m_Age = age;
                break;
            }
        }
        
        // add phone
        cout << "please input your phone number : ";
        string phone;
        cin >> phone;
        p -> personArr[p -> m_Size].m_Phone = phone;
        
        // add address
        cout << "please input your address : ";
        string address;
        cin >> address;
        p -> personArr[p -> m_Size].m_Addr = address;
        
        // update m_size
        p -> m_Size = (p -> m_Size) + 1;
        cout << "successful !!" << endl;
    }
}

int isExist (Adderssbooks * p, string name)
{
    for (int i = 0; i < p->m_Size; i ++)
    {
        if (p->personArr[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson (Adderssbooks * p)
{
    cout << "please input the name you want to delete : " ;
    string name;
    cin >> name;
    int ret = isExist(p,name);
    if (ret != -1)
    {
        for (int i = ret; i < p->m_Size; i ++)
        {
            // move forward
            p -> personArr[i] = p -> personArr[i + 1];
        }
        p -> m_Size = (p -> m_Size) - 1;
        cout << "delete successful!!" << endl;
    }
    else
    {
        cout << "don't find this person " << endl;
    }
}

void checkPerson(Adderssbooks * p)
{
    cout << "please input the name you want to check : ";
    string name;
    cin >> name;
    
    int ret = isExist(p, name);
    if ( ret != -1)
    {
        cout << "Name : " << p -> personArr[ret].m_Name << "\t\t|";
        cout << "sex : " << (p -> personArr[ret].m_Sex == 1 ? "male  ":"female") << "\t\t|";
        cout << "age : " << p -> personArr[ret].m_Age << "\t\t|";
        cout << "phone : " << p -> personArr[ret].m_Phone << "\t\t|";
        cout << "address : " << p -> personArr[ret].m_Addr << endl;
    }
    else
    {
        cout << "this people not in the book" << endl;
    }
}

void modifyPerson (Adderssbooks * p)
{
    cout << "input the name you want to modify : ";
    string name;
    cin >> name;
    
    int ret = isExist(p, name);
    
    if (ret != -1)
    {
        cout << "name : ";
        string inputName;
        cin >> inputName;
        p->personArr[ret].m_Name = inputName;
        
        cout << "please input a sex, 1 ~ male, 2 ~ female : ";
        int sex ;
        
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                p -> personArr[ret].m_Sex = sex;
                break;
            }
            else
            {
                cout << "invalid number, please input again: ";
            }
        }
        
        cout << "age : ";
        int age;
        while (true)
        {
            cin >> age;
            if (age < 0 || age > 150)
            {
                cout << "wrong input, please input another age ";
            }
            else
            {
                p -> personArr[ret].m_Age = age;
                break;
            }
        }
        
        // add phone
        cout << "phone number : ";
        string phone;
        cin >> phone;
        p -> personArr[ret].m_Phone = phone;
        
        // add address
        cout << "address : ";
        string address;
        cin >> address;
        p -> personArr[ret].m_Addr = address;
    }
    else
    {
        cout << "This people is not in the book";
    }
}

void cleanPerson(Adderssbooks * p)
{
    p -> m_Size = 0;
    cout << "no people in the book now !!" << endl;
}

void showPerson(Adderssbooks * p)
{
    // check person number (0 ~ no record, >0 show person information )
    if (p->m_Size == 0)
    {
        cout << "No person in the address book" << endl;
    }
    else
    {
        for (int i = 0; i < p -> m_Size; i ++)
        {
            cout << "Name : " << p -> personArr[i].m_Name << "\t\t|";
            cout << "sex : " << (p -> personArr[i].m_Sex == 1 ? "male  ":"female") << "\t\t|";
            cout << "age : " << p -> personArr[i].m_Age << "\t\t|";
            cout << "phone : " << p -> personArr[i].m_Phone << "\t\t|";
            cout << "address : " << p -> personArr[i].m_Addr << endl;
        }
    }
}


int main()
{
    Adderssbooks abs;
    abs.m_Size = 0;
    
    
    while (true)
    {
        showMenu();
        int select = 0; // user choose input
        cout << "please choose what you want : ";
        cin >> select;
        switch (select) {
            case 1: // add
                addPerson(&abs); //using address as parameters can change the value.
                break;
            case 2: //show
                showPerson(&abs);
                break;
            case 3: // delete
                deletePerson(&abs);
                break;
            case 4: // search
                checkPerson(&abs);
                break;
            case 5: // edit
                modifyPerson(& abs);
                break;
            case 6: // move all
                cleanPerson(&abs);
                break;
            case 0: // exit
                cout << "See you next time !" << endl;
                return 0;
                break;
            default:
                cout << "invalid input, pls input again" << endl;
                break;
        }
    }
    return 0;
}
