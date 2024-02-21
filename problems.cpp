#include <iostream>
#include <cmath>

bool checkPalindrome(std::string word);
int factorialCalculator(int number);
bool primeNumberCalculator(int number);
void fibonacciSequence(int number);
bool anagramChecker(std::string word1, std::string word2);
int reverseNumber(int number);
void bubbleSort();

int main() {
    std::cout << checkPalindrome("121") << std::endl;
    std::cout << factorialCalculator(4) << std::endl;
    std::cout << primeNumberCalculator(11) << std::endl;
    std::cout << anagramChecker("anagram", "nag a ram") << std::endl;
    std::cout << reverseNumber(54321) << std::endl;

    fibonacciSequence(8);
    bubbleSort();
    return 0;
}

bool checkPalindrome(std::string word) {
    std::string reversed_word;
    bool answer;

    for(int i = word.length() - 1; i >= 0; i--) {
        reversed_word += word[i];
    }

    if(word == reversed_word) {
        answer = true;
    } else {
        answer = false;
    }

    return answer;
}

int factorialCalculator(int number) {
    int answer = 1;

    for(int i = 2; i <= number; i++) {
        answer *= i;
    }

    return answer;
}

bool primeNumberCalculator(int number) {
    int divisors_count = 0;
    bool answer;

    for(int i = 1; i <= number; i++) {
        if(number % i == 0) divisors_count++;
    }

    if(divisors_count == 2) {
        answer = true;
    } else {
        answer = false;
    }

    return answer;
}

void fibonacciSequence(int number) {
    int sequence[number] = {0, 1};
    int current = 1;
    int prev = 0;

    for(int i = 2; i <= number; i++) {
        sequence[i] = sequence[current] + sequence[prev];
        current++; prev++;
    }

    for(int i = 0; i < number - 1; i++) {
        std::cout << sequence[i] << " , ";
    }

    std::cout << sequence[number - 1] << std::endl;
}

bool anagramChecker(std::string word1, std::string word2) {
    bool answer;
    int letter_repeat_count = 0;

    std::string real_word1;
    std::string real_word2;

    for(int i = 0; i < word1.length(); i++) {
        if(word1[i] != ' ') real_word1 += word1[i];
    }

    for(int i = 0; i < word2.length(); i++) {
        if(word2[i] != ' ') real_word2 += word2[i];
    }


    for(int i = 0; i < real_word1.length(); i++) {
        for(int j = 0; j < real_word2.length(); j++) {
            if(real_word2[j] == real_word1[i]) {
                letter_repeat_count++;
                break;
            }
        }
    }

    if(letter_repeat_count == real_word1.length()) {
        answer = true;
    } else {
        answer = false;
    }

    return answer;
}

int reverseNumber(int number) {
    int answer = 0;
    int i = number;
    
    while(i > 0) {
        int last_digit = (i % 10);
        answer = answer * 10 + last_digit;
        i = floor(i / 10);
    }

    return answer;
}

void bubbleSort() {
    int arr[5] = {5,4,3,2,1};
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    std::cout << "Sorted Array: ";
    for(int i = 0; i < 4; i++) {
        std::cout << arr[i] << ",";
    }

    std::cout << arr[4];
}