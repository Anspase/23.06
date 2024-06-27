// РОБОТА З ФАЙЛАМИ
// ================

// №1

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// using namespace std;

// void removeWords(const string&inputFileName, const string&outputFileName, const string&unacceptedWordsFileName){
//     ifstream inputFile(inputFileName);
//     ifstream unacceptedWordsFile(unacceptedWordsFileName);
//     ofstream outputFile(outputFileName);

//     string unacceptedWords;
//     while (unacceptedWordsFile >> unacceptedWords) {
//         string row;
//         while (getline(inputFile, row)) {
//             string Row;
//             istringstream iss(row);
//             string word;
//             while (iss >> word) {
//                 if (word != unacceptedWords)
//                     Row += word + " ";
//             }
//             outputFile << Row << endl;
//         }
//         inputFile.clear();
//         inputFile.seekg(0, ios::beg);
//     }
//     inputFile.close();
//     unacceptedWordsFile.close();
//     outputFile.close();
// }

// int main(){
//     removeWords("input.txt", "output.txt", "words.txt");
//     return 0;
// }

// №2

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <algorithm> 
// using namespace std;


// string transliterate(const string&ukrainianText);

// int main(){
//     string inputFileName, outputFileName;

//     cout << "Введіть ім'я файлу з українським текстом: ";
//     cin >> inputFileName;
//     cout << "Введіть ім'я файлу для збереження англійського тексту: ";
//     cin >> outputFileName;

//     ifstream inputFile(inputFileName);
//     ofstream outputFile(outputFileName);
//     if(inputFile.is_open() && outputFile.is_open()) {
//         string ukrainianText((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

//         string englishText = transliterate(ukrainianText);
//         outputFile << englishText;
//         inputFile.close();
//         outputFile.close();
//         cout << "Транслітерація завершена!" << endl;
//     } else {
//         if (!inputFile.is_open()) 
//             cout << "Помилка відкриття файлу для читання: " << inputFileName << endl;
//         if (!outputFile.is_open()) 
//             cout << "Помилка відкриття файлу для запису: " << outputFileName << endl;
//     }

//     return 0;
// }

// string transliterate(const string&ukrainianText) {
//     string transliteratedText;
//     for (char c : ukrainianText) {
//         char lower = tolower(c);
//         if (lower >= 'a' && lower <= 'z') {
//             int index = lower - 'a'; 
//             const char* mapping[] = {
//                 "a", "b", "v", "h", "g", "d", "e", "ie", "zh", "z",
//                 "y", "i", "i", "i", "k", "l", "m", "n", "o", "p",
//                 "r", "s", "t", "u", "f", "kh", "ts", "ch", "sh", "shch",
//                 "", "iu", "ia",
//                 "G", "Ye", "I", "Yi", "Y", "",
//                 "A", "B", "V", "H", "D", "E", "Zh", "Z",
//                 "Y", "I", "I", "K", "L", "M", "N", "O", "P",
//                 "R", "S", "T", "U", "F", "Kh", "Ts", "Ch", "Sh", "Shch"
//             };
//             transliteratedText += mapping[index];
//         } else if (lower >= 'A' && lower <= 'Z') {
//             int index = lower - 'A';
//             const char* mapping[] = {
//                 "G", "Ye", "I", "Yi", "Y", "",
//                 "A", "B", "V", "H", "D", "E", "Zh", "Z",
//                 "Y", "I", "I", "K", "L", "M", "N", "O", "P",
//                 "R", "S", "T", "U", "F", "Kh", "Ts", "Ch", "Sh", "Shch"
//             };
//             transliteratedText += mapping[index];
//         } else 
//             transliteratedText += c; 
//     }
//     return transliteratedText;
// }
