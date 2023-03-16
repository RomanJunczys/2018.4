#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

bool is_distance_less(string word){

    for( int i = 0; i < word.size(); i++ )
    {
        for( int j = i + 1; j < word.size(); j++)
        {
            int dist = abs( (int)word[i] - (int)word[j]  );

            if( dist > 10 )
            {
                return false;
            }
        }
    }

    return true;

}

int main()
{
    // ifstream in_file("przyklad.txt");

    ifstream in_file("sygnaly.txt");

    ofstream out_file("wyniki4.txt");


    // Zadanie 4.1

    string word = "";
    string message = "";

    for(int i = 39; i < 1000; i++){

            in_file >> word;

            if ( ((i+1) % 40) == 0){
                    message += word[9];
            }
    }

    out_file << "Zadanie 4.1" << endl;
    out_file << message << endl;


    // reset cursor's position
    in_file.seekg(0);


    // Zadanie 4.2

    string max_word = "";
    int max_num_diff_chars = 0;

    for(int i = 0; i < 1000; i++){

            in_file >> word;

            unordered_set<char> diff_chars;
            for(char c : word){
                diff_chars.insert(c);
            }

            int num_diff_chars = diff_chars.size();
            if( num_diff_chars > max_num_diff_chars){
                max_word = word;
                max_num_diff_chars = num_diff_chars;
            }

    }

    out_file << "Zadanie 4.2 " << endl;
    out_file << max_word << " " << max_num_diff_chars << endl;


    // Zadanie 4.3

    // reset cursor's position
    in_file.seekg(0);

    out_file << "Zadanie 4.3" << endl;

    for(int i = 0; i < 1000; i++){

            in_file >> word;

            if ( is_distance_less(word)){
                    out_file << word << endl;
            }
    }

    in_file.close();
    out_file.close();


    return 0;
}
