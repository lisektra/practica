Учебная практика

Программа предназначена для анализа текста на русском языке (символы кириллицы). На вход требуется файл с расширением .txt. Программа считывает текст из файла, разбивает его на слова, сортирует их по алфавиту в порядке возрастания и выводит в выходной файл. Также в файл анализа выводится небольшой анализ текста. Название исходного файла вводится с консоли, остальные файла создаются в процессе работы программы. 

Для разбивки исходного текста на слова используется функция:

```C++
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
```
Для сортировки используется функция:

``` C++
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
```
Программа работает только с файлами с расширением .txt.

Скриношот файла с исходными данными:

![image](https://user-images.githubusercontent.com/106808462/171882390-ba0a02c8-af0d-4db7-ac27-18f20df56612.png)

Скриношот файла с отсортированными словами:

![image](https://user-images.githubusercontent.com/106808462/171882517-baac8fd4-b984-4977-bf47-64890997ef96.png)

Скриношот файла с анализом:

![image](https://user-images.githubusercontent.com/106808462/171882760-e16b7ad2-19c7-42a6-85c4-87f3fe349dda.png)

Скриношот c консоли:

![image](https://user-images.githubusercontent.com/106808462/171882604-956642e4-cb7e-4494-9b4a-26227226d8b8.png)


   
