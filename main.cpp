#include <iostream>
#include <fstream>
const int SKOLKO_SLOV = 1000;
const int MAX_DLINA_SLOVA = 100;

//Chitaet v massiv file
void ArriveOutput(char charray[MAX_DLINA_SLOVA][SKOLKO_SLOV], int vyhod, char dlinnyeSlova[MAX_DLINA_SLOVA][SKOLKO_SLOV], int howMuchLength, int skolkoDlinnyhSlov)
{
    std::ofstream out("output.txt");
    /*for(int j = 0; j < vyhod; j++)
    {
        std::cout << charray[j] << std::endl;
    }
    for(int i = 0; i < skolkoDlinnyhSlov; i++)
    {
        std::cout << "Dlinnoe: " << dlinnyeSlova[i] << std::endl;
    }*/
    for(int i = skolkoDlinnyhSlov-1; i > skolkoDlinnyhSlov-howMuchLength-1; i--)
    {
        std::cout << "Dlinnoesort: " << dlinnyeSlova[i] << std::endl;
        out << dlinnyeSlova[i] << std::endl;
    }
}

void ReadFileInput(int& vyhod, char charray[MAX_DLINA_SLOVA][SKOLKO_SLOV], int& howMuchLength, char& symbol)
{
    std::ifstream in("input.txt");
    in >> howMuchLength;

    in >> symbol;
    for(int i = 0; !in.eof(); i++)
    {
        in >> charray[i];
        vyhod = i;
    }
}

int main()
{
    system("chcp 65001");
    int howMuchLength;
    char symbol;
    char charray[MAX_DLINA_SLOVA][SKOLKO_SLOV];
    char dlinnyeSlova[MAX_DLINA_SLOVA][SKOLKO_SLOV];

    int vyhod = 0;
    int skolkoDlinnyhSlov = 0;

    ReadFileInput(vyhod, charray, howMuchLength, symbol);
    //std::cout << "length: " << howMuchLength << std::endl;
    //std::cout << "symbol: " << symbol << std::endl;
    for(int i = 0; i < vyhod; i++)
    {
        if (charray[i][strlen(charray[i])-1] == symbol)
        {
            int wordsLenght = strlen(charray[i]);
            //std::cout << "Word's length = "  << wordsLenght << std::endl;
            skolkoDlinnyhSlov++;
            strcpy_s(dlinnyeSlova[skolkoDlinnyhSlov-1], charray[i]);
        }
    }
    //std::cout << "Skolko dlinnyhSlov: " << skolkoDlinnyhSlov << std::endl;

    for(int i = 0; i < skolkoDlinnyhSlov; i++)
        for(int j = i+1; j < skolkoDlinnyhSlov; j++)
            if(strlen(dlinnyeSlova[j]) <= strlen(dlinnyeSlova[i]))
                std::swap(dlinnyeSlova[j], dlinnyeSlova[i]);

    ArriveOutput(charray, vyhod, dlinnyeSlova, howMuchLength, skolkoDlinnyhSlov);
    return 0;
}

