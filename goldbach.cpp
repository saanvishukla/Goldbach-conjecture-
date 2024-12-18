#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Goldbach's conjecture is one of the oldest and best-known unsolved problems in number theory and all of mathematics. It states that every even natural number greater than 2 is the sum of two prime numbers.
Here is the wikipedia link for more information: https://en.wikipedia.org/wiki/Goldbach%27s_conjecture.

Before you start the lab, please:
    1. Read the self-study topic File I/O [https://course.cse.ust.hk/comp2011/notes/h.fileio.pdf].
    2. Read the self-study topic C++ String Class [https://course.cse.ust.hk/comp2011/notes/h.stlstr.pdf].
*/

bool isPrime(int n)
{
    // -------------------------------------------------------
    // This function checks if a number is prime or not
    // Input: n, an integer
    // Output: true if n is prime, false otherwise
    // For example, isPrime(5) returns true
    // NOTE: 1 is not a prime number
    // ** Your TODO: Implement this function **
    if (n <= 1)return false; 
    for (int i=2;i * i<=n;i++){ // int i = 2 while(i * i <=n) i + 1
        if(n % i==0)return false; 
    }
    return true; 
}

void findPrimePair(int n)
{
    // -------------------------------------------------------
    // This function finds all pairs of prime numbers that sum up to n
    // Input: n, an integer
    // Output: the pairs of prime numbers (p, q) such that n = p + q
    // For example, findPrimePair(10), outputs: "10=3+7=5+5"
    // NOTE: you should output all pairs of prime numbers that sum up to n, and then print them in ascending order of p
    // NOTE: please DO NOT print the same pair twice, e.g., 3+7 and 7+3 are the same pair, only print the first one
    // NOTE: if n is not an even number, print "n is not an even number" and return
    // ** Your TODO: Implement this function **
    if (n<= 2||n%2!=0) {
        cout<<n<<"is not an even number."<< endl;
        return;
    }
    string result=to_string(n)+"="; 
    bool Pairfound=false; 
    for (int p=2;p<=n/2;p++){
        int q=n-p; 
        if (isPrime(p)&&isPrime(q)){
            if (Pairfound){
                result+="="; 
            }
            result+=to_string(p)+"+"+to_string(q); 
            Pairfound=true; 
        }
    }
    if (!Pairfound){
        result+="No prime pairs found."; 
    }
    // -------------------------------------------------------
    cout<<result<<endl;
}

void findPrimePairInRange(int lower,int upper)
{
    // -------------------------------------------------------
    // This function finds all even numbers in the range [lower, upper] that can be expressed as the sum of two prime numbers in at least two different ways
    // Input: lower bound, an integer (include this number)
    // Input: upper bound, an integer (include this number)
    // Output: a list of even numbers in the range [lower, upper] that can be expressed as the sum of two prime numbers in at least two different ways
    // For example, findPrimePairInRange(1, 20), outputs: "10 14 16 18 20"
    // NOTE: 8=3+5 and 8=5+3 are considered as one way, not two ways. 10=3+7 and 10=5+5 are considered as two ways.
    // ** Your TODO: Implement this function **

    // -------------------------------------------------------
    bool evennumbersfound=false;
    for (int n=lower;n<=upper;n++){
        if(n%2==0&&n>2){ 
            int count=0; 
            for(int p=2;p<=n/2;p++){
                int q=n-p;
                if(isPrime(p)&&isPrime(q)){
                    count++; 
                }
            }
            if (count>=2){
                cout<<n<<" "; 
                evennumbersfound = true; 
            }
        }
    } 
    cout << endl;
} 

void findEvenNumbers(string path)
{
    // -------------------------------------------------------
    // This function finds all even numbers in the range [1, 100] that can be expressed as the sum of the given prime number and another prime number
    cout << "Reading prime number from " << path << endl;
    ifstream fin(path); // read prime number from this file
    int prime;
    fin >> prime;
    cout << "Prime number: " << prime << endl;
    // ** Your TODO: Implement this function **
    for (int n = prime+1; n <= 100; n+=2){
        int anothernumber = n - prime;
        if (anothernumber <= 2) continue;
        if(isPrime(anothernumber)){
            cout<<n<< " ";
        }
    }
    // -------------------------------------------------------
    cout << endl;
    fin.close();
}

int main()
{
    cout << "Welcome to lab3: Goldbach's Conjecture" << endl;
    cout << "0. Exit the program." << endl;
    cout << "1. Check if a number is prime or not." << endl;
    cout << "2. Test Goldbach's conjecture for a given even number n." << endl;
    cout << "3. Test Goldbach's conjecture for all even numbers in a given range [a, b]." << endl;
    cout << "4. Read prime numbers from a file and find all even numbers in the range [1, 100] that can be expressed as the sum of the given prime number and another prime number." << endl;
    while (true)
    {
        int choice;
        cout << "Please chose the task you want to run: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            cout << "Exit the lab3 program." << endl;
            return 0;
        case 1:
        {
            int p;
            cout << "Enter a number p: ";
            cin >> p;
            cout << endl;
            if (isPrime(p))
                cout << p << " is a prime number." << endl;
            else
                cout << p << " is not a prime number." << endl;
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter an even number n: ";
            cin >> n;
            cout << endl;
            findPrimePair(n);
            break;
        }
        case 3:
        {
            int lower, upper;
            cout << "Enter the lower bound: ";
            cin >> lower;
            cout << endl;
            cout << "Enter the upper bound: ";
            cin >> upper;
            cout << endl;
            findPrimePairInRange(lower, upper);
            break;
        }
        case 4:
        {
            string path;
            cout << "Enter the path for input file (e.g ./files/prime1.txt ): ";
            cin >> path;
            cout << endl;
            findEvenNumbers(path);
            break;
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}