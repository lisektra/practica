#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <list>

using namespace std;

string reading_text(string namefile)
{
    string source_text = "";
    ifstream file_original;
    file_original.open("original_" + namefile + ".txt");

    if (file_original.is_open())
    {
        char simbol;
        while (file_original.get(simbol))
        {
            source_text += simbol;
        }
        file_original.close();
    }
    else
    {
        cout << "Файл original не открылся";
        exit(0);
    }

    return source_text;
}

list<string> division_into_words(string source_text)
{
    list<string> words;

    stringstream ss(source_text);
    string word;
    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}

list<string> removing_extra_characters(list<string> words)
{
    list<string> wordsnew;
    vector<char> symbols_wordsnew;

    for (string word : words)
    {
        for (char symbol : word)
        {
            if (symbol >= 'а' && symbol <= 'я' || symbol >= 'А' && symbol <= 'Я')
                symbols_wordsnew.push_back(symbol);
        }
        string updated_word(symbols_wordsnew.begin(), symbols_wordsnew.end());
        wordsnew.push_back(updated_word);
        symbols_wordsnew.clear();
    }

    return wordsnew;
}

void quick_sort(vector<string>& mas, int left, int right)
{
    int i = left;
    int j = right;

    string support = mas[(left + right) / 2];

    while (i <= j)
    {
        while (mas[i] < support)
        {
            i++;
        }
        while (mas[j] > support)
        {
            j--;
        }
        if (i <= j)
        {
            string temp = mas[i];
            mas[i] = mas[j];
            mas[j] = temp;
            i++;
            j--;
        }
    }
        if (left < j)
            quick_sort(mas, left, j);
        if (i < right)
            quick_sort(mas, i, right);
}
    void write_result(string namefile, vector<string> words)
    {
    ofstream file_result;
    file_result.open("result_" + namefile + ".txt");

    for (int i = 0; i < words.size(); i++)
    {
        file_result << words[i] << endl;
    }
    file_result.close();
}

vector<int> get_array_count_words(vector<string> &words)
{
    vector<int> count_words_array(33);
    string hi_reg = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string lo_reg = "абвгдеёжзийклмнопрстуфхцчшщъэьэюя";
    cout << words[0];
    for (int i = 0; i < words.size(); i++)
    {
        if (hi_reg.find(words[i][0]) != string::npos)
            count_words_array[hi_reg.find(words[i][0])]++;
        else if (lo_reg.find(words[i][0]) != string::npos) {
            count_words_array[lo_reg.find(words[i][0])]++;
        }      
    }
    return count_words_array;
}

void write_analysis(string namefile, string source_text, int word_count, vector<int> number_words_array, int sort_time)
{
    ofstream file_analysis;

    string analysis_str = "analysis_" + namefile + ".txt";
    file_analysis.open(analysis_str);

    file_analysis
        << "Исходный текст: " << endl
        << "<<" << source_text << ">>" << endl
        << "Параметры выбранного варианта (12): кириллица, по алфавиту, по возрастанию, игнорировать числа, быстрая сортировка" << endl
        << "Количество слов: " << word_count << endl
        << "Время сортировки: " << static_cast<double>(sort_time) / 1000 << " с" << endl
        << "Статистика (количество слов на каждую букву алфавита): " << endl;

    cout
        << "Исходный текст: " << endl
        << "<<" << source_text << ">>" << endl
        << "Параметры выбранного варианта (12): кириллица, по алфавиту, по возрастанию, игнорировать числа, быстрая сортировка" << endl
        << "Количество слов: " << word_count << endl
        << "Время сортировки: " << static_cast<double>(sort_time) / 1000 << " с" << endl
        << "Статистика (количество слов на каждую букву алфавита): " << endl;

    string lo_reg = "абвгдеёжзийклмнопрстуфхцчшщъэьэюя";

    for (int i = 0; i < number_words_array.size(); i++)
    {
        file_analysis << lo_reg[i] << ": " << number_words_array[i] << endl;
        cout << lo_reg[i] << ": " << number_words_array[i] << endl;
    }
    file_analysis.close();
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string namefile;

    cout << "Введите номер файла: ";
    cin >> namefile;

    string source_text = reading_text(namefile);

    list<string> words = division_into_words(source_text);
    list<string> wordn = removing_extra_characters(words);
    list<string> list = wordn;
    vector<string> wordsitog(list.begin(), list.end());

    int start_time = clock();
    quick_sort(wordsitog, 0, wordsitog.size() - 1);
    int end_time = clock();
    int sort_time = end_time - start_time;

    write_result(namefile, wordsitog);

    vector<int> number_words_array = get_array_count_words(wordsitog);

    int words_count = wordsitog.size();

    write_analysis(namefile, source_text, words_count, number_words_array, sort_time);

    return 0;
}