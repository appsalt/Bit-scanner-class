// Bit scanner class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <string>


class BitScanner
{
    public:
        BitScanner(std::vector<bool>& A)
            :_A(A)
        {
            for (std::vector<bool>::iterator it = _A.begin(); it != _A.end(); ++it)
            {
                switch (*it)
                {
                case 0:
                    ++B[0];
                    break;
                case 1:
                    ++B[1];
                    break;
                }
            }
        }
        ~BitScanner()
        {
            delete pB;
        }

        int* returnRead()
        {
            pB[0] = B[0];
            pB[1] = B[1];
            return pB;
        }

    private:   
    std::vector<bool> _A;
    int B[2]{};
    int* pB = new int[2]{};
    
};

void RBVF(std::vector<bool> &V, int N)
{
    // Random Boolean Vector Fill
        V.resize(0);
        for (int i = 0; i < N; ++ i)
        {
            V.push_back(rand() % 2);
        }
}

int main()
{
    // seed the random and create vecor and fill it with bool type, using custom function 
        srand(time(NULL));
        std::vector<bool> OnesAndZeroes(0);
        int length{ 20 }; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< NUMBER OF COIN FLIPPS
        RBVF(OnesAndZeroes, length);
    
    // Create an object that initially goes trought the bool vector and counts cases
        BitScanner a(OnesAndZeroes);

    // Create an int pointer for the counting objects result (new int arr[2])
        int* aRead = a.returnRead();


    // We end by visualizeing the result
        std::cout << std::endl;
        for (size_t i = 0; i < length; i++)
        {
            std::cout << OnesAndZeroes[i];
            std::cout << " ";
        }
        std::cout << std::endl;
        std::cout << "result: \nn(0) = ";
        std::cout << aRead[0];
        std::cout << "\nn(1) = ";
        std::cout << aRead[1];
        std::cout << std::endl;
        std::cout << "0: ";
        for (size_t i = 0; i < aRead[0]; i++)
        {
            std::cout << "|";
        }
        std::cout << std::endl;
        std::cout << "1: ";
        for (size_t i = 0; i < aRead[1]; i++)
        {
            std::cout << "|";
        }
        std::cout << std::endl;

    return 0;
}

