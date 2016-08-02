#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


void PrintAllRegularBracketsSequenceInternal(int N,
    int number_of_opened_brackets,
    int number_of_closed_brackets,
    string output_str ) {
  // last step of recursion
  if ((number_of_opened_brackets == N) && (number_of_closed_brackets == N)) {
    cout << output_str << endl;
    return;
  }

  // if number of opened brackets less than N, we increase number_of_opened_brackets per 1, and add to output_string symbol '(',
  // then we call PrintAllRegularBracketsSequenceInternal with this new parameters
  if( number_of_opened_brackets < N )
    PrintAllRegularBracketsSequenceInternal( N,
        number_of_opened_brackets + 1,
        number_of_closed_brackets,
        output_str + '(');

  // if current number_of_opened_brackets exceeds number_of_closed_brackets, we increase number_of_closed_brackets per 1
  // and add to output_string symbol ')', then we also call PrintAllRegularBracketsSequenceInternal with this new parameters
  if( number_of_opened_brackets > number_of_closed_brackets )
    PrintAllRegularBracketsSequenceInternal( N,
        number_of_opened_brackets,
        number_of_closed_brackets + 1,
        output_str + ')');
}


// main function that generate all regular brackets sequence
void PrintAllRegularBracketsSequence(int N) {
  string output_str("");
  PrintAllRegularBracketsSequenceInternal(N, 0, 0, output_str);
}

// N = 2
// (())
// ()()
int main() {
  int N;
  cout << " Please, enter integer number N = ";
  cin >> N;

  freopen("brackets.out", "w", stdout);

  cout << " There are all regular brackets sequence of length 2*N: " << endl;
  PrintAllRegularBracketsSequence(N);
  return 0;
}
