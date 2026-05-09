#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

void pause_screen();
string TenToR(string, int);
string RToTen(string, int);
string TenToR(string, int, int, bool &);
string RToTen(string, int, int, bool &);
int str_int(char);
char int_str(int);
string beauty_print(string, int);
string beauty_print(string, int, bool);
string delete_fake_zero(string, bool = true);
long double str_lo_do(string, unsigned long long &);
string radix_complement(string, int);
string diminished_radix_complement(string, int);
void save_num(string, string, string, int, int);

int main()
{
    string num;
    int currentR, nextR, number_of_digit;
    char choice;
    bool error_status;

    while (1)
    {
        error_status = false;
        cout << "\n------------------------------------------";
        cout << "\n        tools for digital disign          ";
        cout << "\n------------------------------------------";
        cout << "\n\n\n";
        cout << "1 : convert number-base \n";
        cout << "2 : diminished radix complement \n";
        cout << "3 : radix complement \n";
        cout << "4 : unsigned integer binary -> signed integer binary \n";
        cout << "\n\n----> what do you want : ";
        cin >> choice;

        system("cls");

        if (choice == '1')
        {

            cout << "\n------------------------------------------";
            cout << "\n           convert number-base            ";
            cout << "\n------------------------------------------";
            cout << "\n\n\n";

            // ------ start check and get for number and base ------

            // check number
            cout << "--> send your number : ";
            cin >> num;
            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) == -2)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a number !!!\n";
                    error_status = true;
                    break;
                }

                if (str_int(num[i]) == -1)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (str_int(num[j]) == -1)
                        {
                            cout << endl;
                            cout << "<*__*> Warning : this is not a number !!!\n";
                            error_status = true;
                            break;
                        }
                    }
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check current base
            cout << "--> send your current number-base (2-36) : ";
            cin >> currentR;
            if (!(currentR >= 2 && currentR <= 36))
            {
                cout << endl;
                cout << "<*__*> Warning : your base is out of the range !!!\n";
                error_status = true;
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) >= currentR)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this number does not exist in this base !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check next base
            cout << "--> send number-base you want (2-36) : ";
            cin >> nextR;
            if (!(nextR >= 2 && nextR <= 36))
            {
                cout << endl;
                cout << "<*__*> Warning : your base is out of the range !!!\n";
                error_status = true;
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check fraction part
            bool have_fraction;
            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (num[i] == '.')
                {
                    have_fraction = true;
                    break;
                }
                else
                {
                    have_fraction = false;
                }
            }
            if (have_fraction == true && currentR == 10)
            {
                cout << "--> send how many digit-fraction do you want if the fraction part is non-terminating (1 - 500000) : ";
                cin >> number_of_digit;
                if (!(number_of_digit >= 1 && number_of_digit <= 500000))
                {
                    cout << endl;
                    cout << "<*__*> Warning : your digit is out of the range !!!\n";
                    error_status = true;
                }
            }
            else if (have_fraction == true && nextR == 10)
            {
                cout << "--> send how many digit-fraction do you want if the fraction part is non-terminating (1 - 15) : ";
                cin >> number_of_digit;
                if (!(number_of_digit >= 1 && number_of_digit <= 15))
                {
                    cout << endl;
                    cout << "<*__*> Warning : your digit is out of the range !!!\n";
                    error_status = true;
                }
            }
            else if (have_fraction == true)
            {
                cout << "--> send how many digit-fraction do you want if the fraction part is non-terminating (1 - 500000) : ";
                cin >> number_of_digit;
                if (!(number_of_digit >= 1 && number_of_digit <= 500000))
                {
                    cout << endl;
                    cout << "<*__*> Warning : your digit is out of the range !!!\n";
                    error_status = true;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // ------ end check and get for number and base ------

            cout << "\n\n";

            string path = "saved number.txt";
            string tmp;

            if (!have_fraction)
            {
                if (currentR == 10)
                {
                    tmp = beauty_print(TenToR(num, nextR), nextR);
                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
                else if (nextR == 10)
                {
                    tmp = beauty_print(RToTen(num, currentR), 10);
                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
                else
                {
                    tmp = beauty_print(TenToR(RToTen(num, currentR), nextR), nextR);
                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
            }
            else
            {
                bool is_non_terminating;
                if (currentR == 10)
                {
                    string res = TenToR(num, nextR, number_of_digit, is_non_terminating);
                    tmp = beauty_print(res, nextR, is_non_terminating);

                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
                else if (nextR == 10)
                {
                    string res = RToTen(num, currentR, number_of_digit, is_non_terminating);
                    tmp = beauty_print(res, 10, is_non_terminating);

                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
                else
                {
                    string res1 = RToTen(num, currentR, 15, is_non_terminating);
                    string res2 = TenToR(res1, nextR, number_of_digit, is_non_terminating);
                    tmp = beauty_print(res2, nextR, is_non_terminating);

                    cout << tmp;
                    save_num(path, tmp, num, currentR, nextR);
                }
            }

            cout << endl;
        }
        else if (choice == '2')
        {

            cout << "\n-----------------------------------------------";
            cout << "\n         diminished radix complement           ";
            cout << "\n-----------------------------------------------";
            cout << "\n\n\n";

            // ------ start check and get for number and base ------

            // check number
            cout << "--> send your integer number : ";
            cin >> num;
            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) == -2)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a number !!!\n";
                    error_status = true;
                    break;
                }

                if (str_int(num[i]) == -1)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a integer number !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check current base
            cout << "--> send your number-base (2-36) : ";
            cin >> currentR;
            if (!(currentR >= 2 && currentR <= 36))
            {
                cout << endl;
                cout << "<*__*> Warning : your base is out of the range !!!\n";
                error_status = true;
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) >= currentR)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this number does not exist in this base !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // ------ end check and get for number and base ------

            cout << "\n\n";

            cout << "the initial value               : " << num << endl;
            cout << "the diminished complement value : " << diminished_radix_complement(num, currentR) << endl;
        }
        else if (choice == '3')
        {

            cout << "\n------------------------------------------";
            cout << "\n            radix complement              ";
            cout << "\n------------------------------------------";
            cout << "\n\n\n";

            // ------ start check and get for number and base ------

            // check number
            cout << "--> send your integer number : ";
            cin >> num;
            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) == -2)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a number !!!\n";
                    error_status = true;
                    break;
                }

                if (str_int(num[i]) == -1)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a integer number !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check current base
            cout << "--> send your number-base (2-36) : ";
            cin >> currentR;
            if (!(currentR >= 2 && currentR <= 36))
            {
                cout << endl;
                cout << "<*__*> Warning : your base is out of the range !!!\n";
                error_status = true;
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) >= currentR)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this number does not exist in this base !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // ------ end check and get for number and base ------

            cout << "\n\n";

            cout << "the initial value               : " << num << endl;
            cout << "the diminished complement value : " << radix_complement(num, currentR) << endl;
        }
        else if (choice == '4')
        {

            cout << "\n------------------------------------------";
            cout << "\n        change unsigned to signed         ";
            cout << "\n------------------------------------------";
            cout << "\n\n\n";

            // ------ start check and get for number and base ------

            int how_many_bit;
            string changed_signed;

            // check number
            cout << "--> send a positive integer and binary number : ";
            cin >> num;
            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (num[0] == '-')
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a positive number !!!\n";
                    error_status = true;
                    break;
                }

                if (str_int(num[i]) == -2)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a number !!!\n";
                    error_status = true;
                    break;
                }

                if (str_int(num[i]) == -1)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this is not a integer number !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check current base
            currentR = 2;

            for (int i = num.length() - 1; i >= 0; i--)
            {
                if (str_int(num[i]) >= currentR)
                {
                    cout << endl;
                    cout << "<*__*> Warning : this number does not exist in binary number !!!\n";
                    error_status = true;
                    break;
                }
            }
            if (error_status)
            {
                pause_screen();
                continue;
            }

            // check bit
            cout << "--> send how many bit do you want (the number of bits should be more than of our digit number) : ";
            cin >> how_many_bit;
            if (how_many_bit < num.length())
            {
                cout << endl;
                cout << "<*__*> Warning : number of bit is small !!!\n";
                error_status = true;
            }
            else if (how_many_bit == num.length() && num[0] == '1')
            {
                cout << endl;
                cout << "<*__*> Warning : this number is a negative number whose sign has been changed by one of the three methods !!!\n";
                error_status = true;
            }

            if (error_status)
            {
                pause_screen();
                continue;
            }

            // ------ end check and get for number and base ------

            cout << "\n\n";

            if (how_many_bit - (int)num.length() > 0)
            {
                num.insert(0, how_many_bit - (int)num.length(), '0');
            }

            changed_signed = num;
            changed_signed[0] = '1';

            cout << "the initial decimal number : " << RToTen(num, 2) << endl;
            cout << "the initial number      : " << num << endl;
            cout << "the signed-magnitud     : " << changed_signed << endl;
            cout << "the signed-1 complement : " << diminished_radix_complement(num, 2) << endl;
            cout << "the signed-2 complement : " << radix_complement(num, 2) << endl;
        }
        else
        {
            cout << endl;
            cout << "<*__*> error : this choice is not available !!!";
        }

        pause_screen();
    }
}

void pause_screen()
{
    cout << endl;
    cout << endl;
    system("pause");

    system("cls");
}

// 10 -> R (integer)
string TenToR(string number, int R)
{
    string result;
    unsigned long long ull_number = stoull(number);

    int temp;
    while (ull_number != 0)
    {
        temp = ull_number % R;
        result.insert(0, 1, int_str(temp));
        ull_number /= R;
    }
    return result;
}

// R -> 10 (integer)
string RToTen(string number, int R)
{
    unsigned long long result = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        result += str_int(number[(number.length() - 1) - i]) * pow(R, i);
    }
    return to_string(result);
}

// 10 -> R (integer + fraction)
string TenToR(string number, int R, int digit, bool &is_non_terminating)
{
    string result;
    unsigned long long integer_part;
    long double fraction_part;
    unsigned long long how_many_ten;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if (number[i] == '.')
        {
            fraction_part = str_lo_do(number.substr(i).insert(0, 1, '0'), how_many_ten);
            integer_part = stoull(number.erase(i));
            break;
        }
    }

    int temp_ull;
    do
    {
        temp_ull = integer_part % R;
        result.insert(0, 1, int_str(temp_ull));
        integer_part /= R;
    } while (integer_part != 0);
    result += '.';

    long double temp_ld;
    int digit_counter = 0;
    while (fraction_part != 0 && digit_counter < digit)
    {
        temp_ld = fraction_part * R;
        result += int_str(floor(temp_ld / how_many_ten));
        fraction_part = temp_ld - (floor(temp_ld / how_many_ten) * how_many_ten);
        digit_counter++;
    }

    if (fraction_part != 0)
    {
        result += "...";
        is_non_terminating = true;
    }
    else
    {
        is_non_terminating = false;
    }

    return result;
}

// R -> 10 (integer + fraction)
string RToTen(string number, int R, int digit, bool &is_non_terminating)
{

    long double result = 0;

    int *place_value = new int(number.length() - 1);
    int place_dot;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if (number[i] == '.')
        {
            place_dot = (number.length() - 1) - i;
            number.erase(i, 1);
            break;
        }
    }

    for (int i = -place_dot; i <= (signed)number.length() - place_dot; i++)
    {
        place_value[(number.length() - 1) - (i + place_dot)] = i;
    }

    for (int i = number.length() - 1; i >= 0; i--)
    {
        result += str_int(number[i]) * pow(R, place_value[i]);
    }

    ostringstream oss;
    oss << setprecision(digit + to_string((int)result).length()) << result;
    string res = oss.str();

    is_non_terminating = false;

    return res;
}

// diminished radix complement
string diminished_radix_complement(string number, int R)
{
    string dim_comp_num;

    for (int i = 0; i < number.length(); i++)
    {
        dim_comp_num += int_str((R - 1) - str_int(number[i]));
    }

    return dim_comp_num;
}

// diminished radix complement
string radix_complement(string number, int R)
{
    string temp_num, comp_num;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if (i == number.length() - 1)
        {
            while (number[i] == '0')
            {
                i--;
                temp_num += int_str(0);
                if (i < 0)
                {
                    break;
                }
            }

            if (i < 0)
            {
                break;
            }
            else
            {
                temp_num += int_str(R - str_int(number[i]));
            }
        }
        else
        {
            temp_num += int_str((R - 1) - str_int(number[i]));
        }
    }

    for (int i = number.length() - 1; i >= 0; i--)
    {
        comp_num += temp_num[i];
    }

    return comp_num;
}

// print (integer)
string beauty_print(string str, int base)
{
    int number_of_digit;
    if (base < 7)
    {
        number_of_digit = 4;
    }
    else if (base < 14)
    {
        number_of_digit = 3;
    }
    else
    {
        return str;
    }

    int j = 0;
    int length = str.length() - 1;
    for (int i = length; i >= 0; i--)
    {
        j++;
        if (j == number_of_digit && !(i == 0))
        {
            str.insert(i, 1, '\'');
            j = 0;
        }
    }

    return str;
}

// print (integer + fraction)
string beauty_print(string str, int base, bool is_non_terminating)
{
    int number_of_digit;
    if (base < 7)
    {
        number_of_digit = 4;
    }
    else if (base < 14)
    {
        number_of_digit = 3;
    }
    else
    {
        return str;
    }

    int j = 0;
    int length = str.length() - 1;
    int place_dot = str.length();

    if (is_non_terminating)
    {
        for (int i = length - 3; i >= 0; i--)
        {
            if (str[i] == '.')
            {
                place_dot = i;
                break;
            }
        }
    }
    else
    {
        for (int i = length; i >= 0; i--)
        {
            if (str[i] == '.')
            {
                place_dot = i;
                break;
            }
        }
    }

    for (int i = length; i >= 0; i--)
    {
        if (i < place_dot)
        {
            j++;
            if (j == number_of_digit && !(i == 0))
            {
                str.insert(i, 1, '\'');
                j = 0;
            }
        }
    }

    return delete_fake_zero(str);
}

int str_int(char str)
{
    int a;
    if (str >= 'a' && str <= 'z')
    {
        a = str - 'a' + 10;
    }
    else if (str >= 'A' && str <= 'Z')
    {
        a = str - 'A' + 10;
    }
    else if (str >= '0' && str <= '9')
    {
        a = str - '0';
    }
    else if (str == '.')
    {
        a = -1;
    }
    else
    {
        a = -2;
    }
    return a;
}

char int_str(int num)
{
    char a;
    if (num >= 0 && num <= 9)
    {
        a = num + '0';
    }
    else if (num >= 10 && num <= 35)
    {
        a = num - 10 + 'A';
    }
    return a;
}

string delete_fake_zero(string str, bool have_fraction)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (have_fraction)
        {
            if (str[i] == '0' && str[i + 1] != '.')
            {
                str.erase(i, 1);
                i = -1;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (str[i] == '0')
            {
                str.erase(i, 1);
                i = -1;
            }
            else
            {
                break;
            }
        }
    }

    if (have_fraction)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                str.erase(i, 1);
            }
            else
            {
                break;
            }
        }
    }

    return str;
}

long double str_lo_do(string str, unsigned long long &how_many_ten)
{
    int digit_fraction;
    long double fraction_part = stold(str);

    digit_fraction = str.length() - 2;
    how_many_ten = pow(10, digit_fraction);

    fraction_part = (long double)round(fraction_part * how_many_ten);

    return fraction_part;
}

void save_num(string path, string result, string number, int currentR, int nextR)
{
    fstream file;
    file.open(path, ios::out);

    string temp = "number-base of this number (" + number + ") converted from " + to_string(currentR) + " to " + to_string(nextR) + " :";

    file << temp;
    file << endl;
    file << endl;
    file << result;

    file.close();
}