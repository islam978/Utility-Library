#pragma once

#include<iostream>
#include<cstdlib>
#include "clsDateLibrary.h"
using namespace std;


class clsUtil {

public:

    static enum enTypechar {
        SmallLetter = 1, CapitalLetter = 2,
        SpecialCharacter = 3, Digit = 4, MixChars = 5
    };

	static void Srand() {
		//Seeds the random number generator in C++, called only once   
		srand((unsigned)time(NULL));
	}


	static int RandomNumber(int From, int To) {
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;

	}

    static char GetRandomCharacter(enTypechar charType) {
        switch (charType) {
        case enTypechar::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;

        }
        case enTypechar::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enTypechar::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enTypechar::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }

        case enTypechar::MixChars:
        {
            return char(RandomNumber(33, 122));
            break;
        }

        }
        return '0';

    }


    static string GenerateWord(enTypechar charType, short length) {
        string word = "";
        for (int i = 0; i < length; i++) {
            word = word + GetRandomCharacter(charType);
        }
        return word;
    }

    static string GenerateKey(enTypechar charType) {
        string key = "";
        key = key + GenerateWord(charType, 4) + '-';
        key = key + GenerateWord(charType, 4) + '-';
        key = key + GenerateWord(charType, 4) + '-';
        key = key + GenerateWord(charType, 4);
        return key;
    }


    static void GenerateKeys(short numbersOfKeys, enTypechar charType) {
        for (int i = 1; i <= numbersOfKeys; i++) {
            cout << "Key [" << i << "] :";
            cout << GenerateKey(charType) << endl;
        }
    }

    static void Swap(int  &x, int &y) {
        int temp = 0;
        temp = x;
        x = y;
        y = temp;


    }

    static void Swap(string & x, string & y) {
        string temp = "";
        temp = x;
        x = y;
        y = temp;


    }

    static void Swap(double & x, double & y) {
        double temp = 0.0;
        temp = x;
        x = y;
        y = temp;


    }

    static void Swap(clsDate & x, clsDate & y) {
        clsDate::SwapDates(x,y);

    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void ShuffleArray(int arr[], int lengthArray) {
        for (int i = 0; i < lengthArray; i++) {
            swap(arr[RandomNumber(1, lengthArray) - 1], arr[RandomNumber(1, lengthArray) - 1]);
        }
    }


    static void ShuffleArray(string arr[], int lengthArray) {
        for (int i = 0; i < lengthArray; i++) {
            swap(arr[RandomNumber(1, lengthArray) - 1], arr[RandomNumber(1, lengthArray) - 1]);
        }
    }

    static void FillArrayWithRandomNumbers(int arr[], int lengthArray, int From , int To) {
        for (int i = 1; i <= lengthArray; i++) {
            arr[i] = RandomNumber(From, To);


        }
    }

    static void FillArrayWithRandomWords(string arr[], int lengthArray, enTypechar TypeChar, short lengthWord) {
        for (int i = 1; i <= lengthArray; i++) {
            arr[i] = GenerateWord(TypeChar,lengthWord);


        }
    }

    static void FillArrayWithRandomKeys(string arr[], int lengthArray, enTypechar TypeChar)  {
        for (int i = 1; i <= lengthArray; i++) {
            arr[i] = GenerateKey(TypeChar);


        }
    } 


    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }


    static string Tabs(short NumberOfTabs){
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }
};
