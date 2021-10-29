#ifndef Input_hpp
#define Input_hpp

#include <iostream>
#include <cstring>
#include <cstddef>

class Output
{
public:
    static void printString(const char *str)
    {
        rewind(stdin);
        for (int i = 0; i < std::strlen(str); ++i)
            std::cout << str[i];
    }
    
    static void printBool(const bool a)
    {        
        a ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
    }
};

class Input
{
public:
    static int getInt()
    {
        std::string toNum;
        int number;

        do
        {
            rewind(stdin);
            std::cout << "Enter Int number:" << std::endl;
            std::cin >> toNum;
        } while ((number = intParse(toNum)) <= -1);

        return number;
    }

    static long getLong()
    {
        std::string toNum;
        long number;

        do
        {
            rewind(stdin);
            std::cout << "Enter Long number:" << std::endl;
            std::cin >> toNum;
        } while ((number = longParse(toNum)) <= -1);

        return number;
    }

    static double getDouble()
    {
        std::string toNum;
        double number;

        do
        {
            rewind(stdin);
            std::cout << "Enter Double number:" << std::endl;
            std::cin >> toNum;
        } while ((number = doubleParse(toNum)) <= -1);

        return number;
    }

    static float getFloat()
    {
        std::string toNum;
        float number;

        do
        {
            rewind(stdin);
            std::cout << "Enter Float number:" << std::endl;
            std::cin >> toNum;
        } while ((number = floatParse(toNum)) <= -1);

        return number;
    }

    static std::string getString()
    {
        std::string str;
        do
        {
            rewind(stdin);
            std::cout << "Enter string:" << std::endl;
            std::getline(std::cin, str);
        } while (str.empty());

        return str;
    }
    
    static std::string getStringWithoutNumbers()
    {
        std::string str;
        do
        {
            rewind(stdin);
            std::cout << "Enter string:" << std::endl;
            std::getline(std::cin, str);
        } while (str.empty() || checkString(str) == -1);

        return str;
    }
    
    static char *getString(int length)
    {
        char *str = new char[length];
        do
        {
            rewind(stdin);
            std::cout << "Enter string:" << std::endl;
            char c;
            for (int i = 0; i < length; i++)
            {
                c = std::cin.get();

                if (c == '\n')
                {
                    str[i] = '\0';
                    break;
                }

                str[i] = c;
            }
        } while (str[0] == '\0');

        return str;
    }
    
    static char *getStringWithoutNumbers(int length)
    {
        char *str = new char[length];
        do
        {
            rewind(stdin);
            std::cout << "Enter string:" << std::endl;
            char c;
            for (int i = 0; i < length; i++)
            {
                c = std::cin.get();

                if (c == '\n')
                {
                    str[i] = '\0';
                    break;
                }

                str[i] = c;
            }
        } while (str[0] == '\0' || checkString(str) == -1);

        return str;
    }

    static bool getBoolean()
    {
        std::cout << "Enter '1' for True or any value for False boolean value:\n";
        if (getInt() == 1)
            return true;
        return false;
    }
    
    static double getTime()
    {
        int number;
        double time;
        std::string buf, toCheck;
        do
        {
            rewind(stdin);
            std::cout << "Enter time:" << std::endl;
            std::cin >> toCheck;
        } while ((number = parseForTime(toCheck)) <= -1);
        
        time = stod(toCheck);
        return time;
    }
    
private:
    static int parseForTime(const std::string& toCheck)
    {
        if (toCheck.empty())
            return -1;
        
        std::string firstPart,secondPart;
        int firstValue,secondValue;
        
        int dots = 0;

        for (char i : toCheck)
        {
            if (i == '.')
                dots++;

            if ((i != '.' && !isInRangeASCII(i, (int)'0', (int)'9')) || dots > 1)
                return -1;
        }

        for(int i = 0; i < toCheck.size();i++)
        {
            if(toCheck[i] == '.')
            {
                i++;
                for(int j = i; j < toCheck.size();j++)
                    secondPart += toCheck[j];
                break;
            }
            firstPart += toCheck[i];
        }
        
        try
        {
            firstValue = std::stoi(firstPart);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        
        try
        {
            secondValue = std::stoi(secondPart);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        
        if(firstValue > 24 || firstValue < 0 || secondValue > 60 || secondValue < 0)
            return -1;
        return 1;
    }
    
    static bool isInRangeASCII(const char c, uint16_t index1, uint16_t index2)
    {
        int code = (int )c;
        return ( code >= index1 && code <= index2  );
    }

    static int intParse(const std::string& toNum)
    {
        int value = 0;
        if (toNum.empty())
            return -1;

        for (char i : toNum)
            if (!isInRangeASCII(i, (int)'0', (int)'9'))
                return -1;

        try
        {
            value = std::stoi(toNum);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        return value;
    }

    static long longParse(const std::string& toNum)
    {
        long value;
        if (toNum.empty())
            return -1;

        for (char i : toNum)
            if (!isInRangeASCII(i, (int)'0', (int)'9'))
                return -1;

        try
        {
            value = std::stol(toNum);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        return value;
    }

    static double doubleParse(const std::string& toNum)
    {
        double value = 0;
        int dots = 0;

        if (toNum.empty())
            return -1;

        for (char i : toNum)
        {
            if (i == '.')
                dots++;

            if ((i != '.' && !isInRangeASCII(i, (int)'0', (int)'9')) || dots > 1)
                return -1;
        }

        try
        {
            value = std::stod(toNum);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        return value;
    }

    static float floatParse(const std::string& toNum)
    {
        float value = 0;
        int dots = 0;

        if (toNum.empty())
            return -1;

        for (char i : toNum)
        {
            if (i == '.')
                dots++;

            if ((i != '.' && !isInRangeASCII(i, (int)'0', (int)'9')) || dots > 1)
                return -1;
        }

        try
        {
            value = std::stof(toNum);
        }
        catch (...)
        {
            std::cout << "Wrong Format!\n";
            return -1;
        }
        return value;
    }
    
    static int checkString(const std::string string)
    {
        for(int i = 0; i < string.size(); i++)
        {
            if(isdigit(string[i]))
                return -1;
        }
        return 1;
    }
};

#endif /* Input_hpp */


