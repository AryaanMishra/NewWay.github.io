#ifndef WORDLE_FILES_H
#define WORDLE_FILES_H
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <set>
#include <random>
#include <algorithm>
#include <numeric>
#include<bits/stdc++.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m" // cout  << ERASE; // then you print everythimg else
#define GREY "\033[90m"
#define ERASE "\33[F"

//the allowed words and the word words are set as the solution. Watch video, make sure which file is used for solution and then solve.

std::map<int, std::pair<std::string, std::string>> dictionary = {
        {4, {"4-allowed.txt", "4-words.txt"}},
        {5, {"5-allowed.txt", "5-words.txt"}},
        {6, {"6-allowed.txt", "6-words.txt"}},
        {7, {"7-allowed.txt", "7-words.txt"}},
        {8, {"8-allowed.txt", "8-words.txt"}}
    };

std::vector<int> timesPlayed;
std::vector<int> attempts;

std::vector<std::string> wordsAttempted;
int button = 0;

void wordle(int num){
    system("clear");
    std::cout << "========================="<< std::endl;
    std::cout<<"    WELCOME TO WORDLE"<<std::endl;
    std::cout << "========================="<< std::endl <<std::endl;
    std::cout<<"1. Play Wordle"<<std::endl;
    std::cout<<"2. How to Play"<<std::endl;
    std::cout<<"3. Statistics Summary"<<std::endl;
    std::cout<<"4. Reset Statistics"<<std::endl;
    std::cout<<"5. Exit"<<std::endl<<std::endl;
    std::cout<<"Select an Option:"<<std::endl;
    std::string choice;
    std::getline(std::cin,choice);
    void choices(std::string choice, int num);
    choices(choice, num);
}

void choices(std::string choice, int num){   
        void playWordle(const std::string& allowed_words_file, const std::string& answer_file, int num);
        void howToPlay(int num);
        void statisticsSummary(int num);
        void resetStatistics(int num);
        void exitGame();
        void afterMath();

        if (choice == "1"){
            playWordle(dictionary[num].first,dictionary[num].second, num);
        }else if(choice == "2"){
            howToPlay(num);
        }
        else if(choice == "3"){
            statisticsSummary(num);
        }
        else if(choice == "4"){
            resetStatistics(num);
        }
        else if(choice == "5"){
            exitGame();
        }else{
            std::cout<<"Invalid entry. Please try Again"<<std::endl;
            std::cout<<"Press [enter] to continue" << std::endl;
            std::string choice;
            std::getline(std::cin, choice);
            if(choice.length()==0){
                system("clear");
                wordle(num);
            }
        }
    }

    void exitGame(){
        system("exit");
        system("clear");
    }

    void howToPlay(int num){
        system("clear");
        std::cout<<"============================================="<<std::endl;
        std::cout<<"                 HOW TO PLAY"<<std::endl;
        std::cout<<"============================================="<<std::endl;
        std::cout<<"Guess the Wordle in 6 tries."<<std::endl<<std::endl;
        std::cout<<"HOW TO PLAY:"<<std::endl;
        std::cout<<"- Each guess must be a valid 5 letter word."<<std::endl;
        std::cout<<"- The color of the tiles will change to show you how close your guess was to the word."<<std::endl<<std::endl;
        std::cout<<GREEN<<" ---"<<RESET;
        std::cout<<" ---  ---  ---  ---"<<std::endl;
        std::cout<<GREEN<<"| W |"<<RESET;
        std::cout<<"| E || A || R || Y |"<<std::endl;
        std::cout<<GREEN<<" ---"<<RESET;
        std::cout<<"  ---  ---  ---  ---"<<std::endl;
        std::cout<<"W is in the word and in the correct spot."<<std::endl<<std::endl;
        std::cout<<" ---  ";
        std::cout<<YELLOW<<"---"<<RESET;
        std::cout<<"  ---  ---  ---"<<std::endl;
        std::cout<<"| P |";
        std::cout<<YELLOW<<"| I |"<<RESET;
        std::cout<<"| L || L || S |"<<std::endl;
        std::cout<<" ---  ";
        std::cout<<YELLOW<<"---"<<RESET;
        std::cout<<"  ---  ---  ---"<<std::endl;
        std::cout<<"I is in the word but in the wrong spot."<<std::endl<<std::endl;
        std::cout<<" ---  ---  ---  ";
        std::cout<<GREY<<"---"<<RESET;
        std::cout<<"  ---"<<std::endl;
        std::cout<<"| V || A || G |";
        std::cout<<GREY<<"| U |"<<RESET;
        std::cout<<"| E |"<<std::endl;
        std::cout<<" ---  ---  ---  ";
        std::cout<<GREY<<"---"<<RESET;
        std::cout<<"  ---"<<std::endl;
        std::cout<<"U is not in the word in any spot."<<std::endl<<std::endl;
        std::cout<<"Press [enter] to continue" << std::endl;
        std::string choice;
        std::getline(std::cin, choice);
        if(choice.length()==0){
            system("clear");
            wordle(num);
        }
    }

    void statisticsSummary(int num){

        system("clear");

        std::ifstream stats_file;
        std::vector<double> line1;
        stats_file.open("stats.txt", std::ios::in);
        if(stats_file.is_open()){
            std::string word2;        
            while(stats_file >> word2){
                line1.push_back(stod(word2));
            }
        }

        std::ifstream timesPlayed_stats_file;
        std::vector<int> line3;
        timesPlayed_stats_file.open("timesPlayed.txt", std::ios::in);
        if(timesPlayed_stats_file.is_open()){
            std::string word3;        
            while(timesPlayed_stats_file >> word3){
                line3.push_back(stoi(word3));
            }
            timesPlayed_stats_file.close();
        } 

        std::ifstream attempt_stats_file;
        std::vector<int> line2;
        attempt_stats_file.open("attempts.txt", std::ios::in);
        if(attempt_stats_file.is_open()){
            std::string word2;        
            while(attempt_stats_file >> word2){
                line2.push_back(stoi(word2));
            }
            attempt_stats_file.close();
        } 

        std::ifstream word_attempt_file;
        std::vector<std::string> line4;
        word_attempt_file.open("wordsPlayed.txt", std::ios::in);
        if(word_attempt_file.is_open()){
            std::string word2;        
            while(word_attempt_file >> word2){
                line4.push_back(word2);
            }
            word_attempt_file.close();
        } 

        double num1 = line1[2];


        std::cout<<"=========================="<<std::endl;
        std::cout<<"    STATISTICS SUMMARY"<<std::endl;
        std::cout<<"=========================="<<std::endl;
        std::cout<<"Times Played:\t\t"<<line1[0]<<std::setprecision(2) <<std::endl;
        std::cout<<std::setprecision(2)<< std::fixed <<"Average Attempts:\t"<<line1[1]<<std::endl;
        std::cout<<std::setprecision(2)<< std::fixed <<"Win Percentage:\t\t"<<num1<<RESET<< "%" << std::endl;
        std::cout<<"Current Streak:\t\t"<<int(line1[3])<<std::endl;
        std::cout<<"Longest Streak:\t\t"<<int(line1[4])<<std::endl<<std::endl;

        std::cout<<"--------------------------"<<std::endl;
        std::cout<<"WORD     ATTEMPTS      WIN"<<std::endl;
        std::cout<<"--------------------------"<<std::endl;
        
        if(button == 0){
            for(int t =0; t <= line4.size()-1; t++){
            std::cout << line4[t];
            std::cout << "\t" << line2[t];
            if(line3[t] == 1){
                std::cout << "\t\tYes" << std::endl;
            }else{
                std::cout << "\t\tNo" << std::endl;
            }
        }
        }
        
        
        
        std::cout<<"Press [enter] to continue";
        std::string choice;
        std::getline(std::cin, choice);
        if(choice.length()==0){
            system("clear");
            wordle(num);
        }
    }

    void resetStatistics(int num){
    // clear the vectors.
    system("clear");
    button ++;

    std::ofstream stats_file;
    stats_file.open("stats.txt", std::ios::out);
    if(stats_file.is_open()){
        stats_file << "0" << std::endl;
        stats_file << "0" << std::endl;
        stats_file << "0" << std::endl;
        stats_file << "0" << std::endl;
        stats_file << "0" << std::endl;

        stats_file.close();
    } 
    std::ofstream ofs;
    ofs.open("timesPlayed.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::ofstream ofs1;
    ofs1.open("attempts.txt", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();

    std::ofstream ofs2;
    ofs2.open("wordsPlayed.txt", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();

    std::cout<<"=========================="<<std::endl;
    std::cout<<"    STATISTICS SUMMARY"<<std::endl;
    std::cout<<"=========================="<<std::endl;
    std::cout<<"Times Played:\t\t0"<<std::endl;
    std::cout<<"Average Attempts:\t0"<<std::endl;
    std::cout<<"Win Percentage:\t\t0%" << std::endl;
    std::cout<<"Current Streak:\t\t0"<<std::endl;
    std::cout<<"Longest Streak:\t\t0"<<std::endl<<std::endl;

    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"WORD     ATTEMPTS      WIN"<<std::endl;
    std::cout<<"--------------------------"<<std::endl<<std::endl;
        

    std::cout<<"Stats have been reset."<<std::endl;
    std::cout<<"Press [enter] to continue"<< std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    if(choice.length()==0){
            system("clear");
            wordle(num);
    }
}

void afterMath(int num){
    //times played
     
     //doesn't work because the timesplayed has to come from line2.size()
     //grey output

    std::ofstream ofs;
    ofs.open("../keyboard/status.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::ofstream ofs1;
    ofs1.open("../keyboard/green.txt", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();

    std::ofstream ofs2;
    ofs2.open("../keyboard/gray.txt", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();

    std::ofstream ofs3;
    ofs3.open("../keyboard/yellow.txt", std::ofstream::out | std::ofstream::trunc);
    ofs3.close();

    std::ofstream ofs4;
    ofs3.open("../keyboard/keyboard.txt", std::ofstream::out | std::ofstream::trunc);
    ofs3.close();
      
    std::ifstream stats_file1;
        std::vector<std::string> line1;
        stats_file1.open("stats.txt", std::ios::in);
        if(stats_file1.is_open()){
            std::string word2;        
            while(stats_file1 >> word2){
                line1.push_back(word2);
            }
            stats_file1.close();
        }

    //int timesPlayedInt = (1) + (std::stoi(line1[0]));
    //std::string timesPlayedString = std::to_string(timesPlayedInt);

    //average attempts
    std::ofstream attempts_file("attempts.txt", std::ios::app);
    if (attempts_file.is_open()) {
        for (int i = attempts.size()-1; i < attempts.size(); i++) {
            attempts_file << attempts[i] << std::endl;
        }
        attempts_file.close();
    }

    std::ifstream attempt_stats_file;
        std::vector<int> line2;
        attempt_stats_file.open("attempts.txt", std::ios::in);
        if(attempt_stats_file.is_open()){
            std::string word2;        
            while(attempt_stats_file >> word2){
                line2.push_back(stoi(word2));
            }
            attempt_stats_file.close();
        } 

    int total_sum = 0;
     int num_elements = line2.size();
    for (int i = 0; i < num_elements; i++) {
        total_sum += line2[i];
    }
    double avg = static_cast<double>(total_sum) / num_elements;
    std::string averageAttemptsString = std::to_string(avg);
    
    //win percent 
    std::ofstream times_file("timesPlayed.txt", std::ios::app);
    if (times_file.is_open()) {
        for (int i = timesPlayed.size()-1; i < timesPlayed.size(); i++) {
            times_file << timesPlayed[i] << std::endl;
        }
        times_file.close();
    }

    std::ifstream timesPlayed_stats_file;
        std::vector<int> line3;
        std::vector<int> line4;
        timesPlayed_stats_file.open("timesPlayed.txt", std::ios::in);
        if(timesPlayed_stats_file.is_open()){
            std::string word3;        
            while(timesPlayed_stats_file >> word3){
                line3.push_back(stoi(word3));
                if(word3 == "1"){
                    line4.push_back(stoi(word3));
                }
            }
            timesPlayed_stats_file.close();
        } 

        int timesPlayedInt = line3.size();
        std::string timesPlayedString = std::to_string(timesPlayedInt);


    double winPercent = (static_cast<double> (line4.size())/line3.size()) * 100.0;
    std::string winPercentString = std:: to_string(winPercent);
    

    int currentStreak = 1;
    for(int l = line3.size()-1; l > 0; --l){
        if((line3[l] == 1) && (line3[l-1] == 1)){
            currentStreak ++;
        }else if(line3[l-1] == 0){
            break;
        }else{
            currentStreak = 0;
            break;
        }
    }
    std::string currentStreakString = std:: to_string(currentStreak);


    int cur_num = line3[0];
    int cur_streak = 1;
    int max_streak = 1;

    for (int i = 1; i < line3.size(); i++) {
        if (line3[i] == cur_num) {
         cur_streak++;
        } else {
            cur_num = line3[i];
            cur_streak = 1;
        }
    if (cur_streak > max_streak) {
      max_streak = cur_streak;
    }
  }

    std::string longestStreakString = std:: to_string(max_streak);

    std::ofstream word_file("wordsPlayed.txt", std::ios::app);
    if (word_file.is_open()) {
        for (int i = wordsAttempted.size()-1; i < wordsAttempted.size(); i++) {
            word_file << wordsAttempted[i] << std::endl;
        }
        word_file.close();
    }


    std::ofstream stats_file;
    stats_file.open("stats.txt", std::ios::out);
    if(stats_file.is_open()){
        stats_file << timesPlayedString << std::endl;
        stats_file << averageAttemptsString <<  std::endl;
        stats_file << winPercentString <<  std::endl;
        stats_file << currentStreakString << std::endl;
        stats_file << longestStreakString << std::endl;
        stats_file.close();
    } 

    std::cout<<"Press [enter] to continue" << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    if(choice.length()==0){
            system("clear");
            wordle(num);
    }
}


void playWordle(const std::string& allowed_words_file, const std::string& answer_file, int num){

    system("clear");
    std::ofstream ofs1;
    ofs1.open("../keyboard/gray.txt", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();

    std::ofstream ofs2;
    ofs2.open("../keyboard/green.txt", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();

    std::ofstream ofs3;
    ofs3.open("../keyboard/yellow.txt", std::ofstream::out | std::ofstream::trunc);
    ofs3.close();

    std::ofstream ofs4;
    ofs4.open("../keyboard/status.txt", std::ofstream::out | std::ofstream::trunc);
    ofs4.close();

    std::ofstream status_file;
    status_file.open("../keyboard/status.txt", std::ios::out);
    if(status_file.is_open()){
        status_file << "Start" << std::endl;
        status_file.close();
    }


  std::ifstream wordsFile(allowed_words_file);
  if (!wordsFile.is_open()) {
    std::cout << "Could not open words.txt file." << std::endl;
    return;
  }

  std::ifstream allowedFile(answer_file);
  if (!allowedFile.is_open()) {
    std::cout << "Could not open allowed.txt file." << std::endl;
    return;
  }

  std::vector<std::string> words;
  std::string word;
  std::string word1;
  while (wordsFile >> word) {
    words.push_back(word);
  }

 std:: vector<std::string> allowed;
  while (allowedFile >> word1) {
    allowed.push_back(word1);
  }
   while (wordsFile >> word1) {
    allowed.push_back(word1);
  }

  srand(time(0));
  std::string solution = allowed[rand() % words.size()];



  std::cout << "Welcome to Wordle!" << std::endl;
  std::cout << solution << std::endl;
   wordsAttempted.push_back(solution);
  std::cout << "Guess the word. It has " << solution.length() << " letters." << std::endl;
  

  bool gotAnswer = false;

for( int n = 1; n <= 6; n++){
  
    std::string guess;
    //std::cout << "Enter your guess: ";
    getline(std::cin, guess);
    std::cout  << ERASE<<ERASE << std::endl;

    std::vector<char> green;
    std::vector<char> gray;
    std::vector<char> yellow;

    if (guess.length() != solution.length()) {
      std::cout << "Your guess should have " << solution.length() << " letters." ;
      std::cout<<ERASE<<std::endl;
      --n;
      continue;
    }

    transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

    bool validGuess = true;
    for (char c : guess) {
      if (!isalpha(c)) {
        validGuess = false;
        break;
      }
    }
    if (!validGuess) {
      std::cout << "Your guess should only contain alphabetical characters." << std::endl;
      --n;
      continue;
    }

    bool valid = (std::binary_search(allowed.begin(),allowed.end(),guess)) || (std::binary_search(words.begin(),words.end(),guess));

    if (!valid) {
      std::cout << "Your guess is not a solution for Wordle." << std::endl;
      --n;
      continue;
    }


    bool correct = true;
    bool inWord = false;
    int sum1 = solution.length();
    bool* inSolution = new bool[sum1];
    for(int i = 0; i < sum1; i++){
        inSolution[i] = false;
    }

    std::ofstream file;
        file.open("../keyboard/keyboard.txt", std::ios::app);
        if(file.is_open()){
            for(int i =0; i< guess.size(); i++){
                file << guess[i] << std::endl;
            }
            file.close();
        }


    for (int i = 0; i < solution.length(); i++) {
      if (guess[i] == solution[i]) {
          std::cout << "\033[32m" << " --- " << "\033[0m";
        inSolution[i] = true;
      } else {
        inWord = false;
        for (int j = 0; j < solution.length(); j++) {
          if (guess[i] == solution[j] && !inSolution[j]) {
              std::cout << "\033[33m" << " --- " << "\033[0m";
            inWord = true;
            //inSolution[j] = true;
            break;
          }
        }
        if (!inWord) {
            std::cout << "\033[90m" << " --- " << "\033[0m";
          correct = false;
        }
      }
    }
    std:: cout << std::endl;

    for (int i = 0; i < solution.length(); i++) {
      if (guess[i] == solution[i]) {

        std::ofstream green_file;
        green_file.open("../keyboard/green.txt", std::ios::app);
        if(green_file.is_open()){
            green_file << guess[i] << std::endl;
            green_file.close();
        }
        std::ofstream key_file;
            key_file.open("../keyboard/keyboard.txt", std::ios::app);
            if(key_file.is_open()){
                key_file << guess[i] << std::endl;
                key_file.close();
            }

        std::cout << "\033[32m" << "| " << "\033[0m";
        std::cout << "\033[32m" << guess[i] << "\033[0m";
        std::cout << "\033[32m" << " |" << "\033[0m";
        green.push_back(guess[i]);
        inSolution[i] = true;
      } else {
        inWord = false;
        for (int j = 0; j < solution.length(); j++) {
          if (guess[i] == solution[j] && !inSolution[j]) {
            std::cout << "\033[33m" << "| " << "\033[0m";
            std::cout << "\033[33m" << guess[i] << "\033[0m";
            std::cout << "\033[33m" << " |" << "\033[0m";

            std::ofstream yellow_file;
            yellow_file.open("../keyboard/yellow.txt", std::ios::app);
            if(yellow_file.is_open()){
                yellow_file << guess[i] << std::endl;
                yellow_file.close();
            }
            std::ofstream key_file;
            key_file.open("../keyboard/keyboard.txt", std::ios::app);
            if(key_file.is_open()){
                key_file << guess[i] << std::endl;
                key_file.close();
            }
            inWord = true;
            yellow.push_back(guess[i]);
            //inSolution[j] = true;
            break;
          }
        }
        if (!inWord) {

            std::ofstream gray_file;
            gray_file.open("../keyboard/gray.txt", std::ios::app);
            if(gray_file.is_open()){
                gray_file << guess[i] << std::endl;
                gray_file.close();
            }

            std::ofstream key_file;
            key_file.open("../keyboard/keyboard.txt", std::ios::app);
            if(key_file.is_open()){
                key_file << guess[i] << std::endl;
                key_file.close();
            }

            std::cout << "\033[90m" << "| " << "\033[0m";
            std::cout << "\033[90m" << guess[i] << "\033[0m";
            std::cout << "\033[90m" << " |" << "\033[0m";
            gray.push_back(guess[i]);
          correct = false;
        }
      }
    }
    std:: cout << std::endl;


    for (int i = 0; i < solution.length(); i++) {
      if (guess[i] == solution[i]) {
          std::cout << "\033[32m" << " --- " << "\033[0m";
        inSolution[i] = true;
      } else {
        inWord = false;
        for (int j = 0; j < solution.length(); j++) {
          if (guess[i] == solution[j] && !inSolution[j]) {
              std::cout << "\033[33m" << " --- " << "\033[0m";
            inWord = true;
            inSolution[j] = true;
            break;
          }
        }
        if (!inWord) {
            std::cout << "\033[90m" << " --- " << "\033[0m";
          correct = false;
        }
      }
    }
    std:: cout << std::endl;

    if (correct) {
      std::cout << "Congratulations! You guessed the word \"" << solution << "\" in " << n << " guesses." << std::endl;
      gotAnswer = true;
      attempts.push_back(n);
      timesPlayed.push_back(1);
      break;
    }

  
}
if (gotAnswer == false){
     std::cout << "Sorry, you did not guess the hidden word (" << solution  << "." << std::endl;
     attempts.push_back(6);
     timesPlayed.push_back(0);
}

afterMath(num);

}


#endif