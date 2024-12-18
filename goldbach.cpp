#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isPrime(int n)
{
  
    if (n <= 1)return false; 
    for (int i=2;i * i<=n;i++){ 
        if(n % i==0)return false; 
    }
    return true; 
}

void findPrimePair(int n)
{

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
    
    cout<<result<<endl;
}

void findPrimePairInRange(int lower,int upper)
{
    
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
    
    cout << "Reading prime number from " << path << endl;
    ifstream fin(path); 
    int prime;
    fin >> prime;
    cout << "Prime number: " << prime << endl;
    for (int n = prime+1; n <= 100; n+=2){
        int anothernumber = n - prime;
        if (anothernumber <= 2) continue;
        if(isPrime(anothernumber)){
            cout<<n<< " ";
        }
    }
    
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