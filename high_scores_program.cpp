// High Scores Program

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	vector<int>::const_iterator iter; // Iterator (post-it note)
	
	cout << "\nCreating a list of scores.\n";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	
	// Display the high scores
	cout << "\nHigh Scores: \n";
	
	for (iter = scores.begin(); iter != scores.end(); ++iter){
		cout << *iter << endl;
	}
	
	// Randomise the high scores
	cout << "Randomizing the scores.\n";
	srand(time(0));
	random_shuffle(scores.begin(), scores.end()); // shuffle ALL of the elements within the 'scores' container
	
	cout << "High Scores: \n";
	for (iter = scores.begin(); iter != scores.end(); ++iter){
		cout << *iter << endl;
	}

	// Sort the Scores
	cout << "\nSorting the scores. \n";
	sort(scores.begin(), scores.end());
	
	cout << "\nHigh Scores: \n";
	for (iter = scores.begin(); iter != scores.end(); ++iter){
		cout << *iter << endl;
	}
	
	// Create second list of scores
	vector<int> moreScores;
	moreScores.push_back(2000);
	moreScores.push_back(4000);
	moreScores.push_back(8000);
	
	cout << "\nMore High Scores: \n";
	for(iter = moreScores.begin(); iter != moreScores.end(); ++iter){
		cout << *iter << endl;
	} 
	
	// Merge both lists
	cout << "\nMerging both lists\n";
	
	// Create additional vector list to merge into
	vector<int> allscores(6); // fixed length of 6 elements
	merge(scores.begin(), scores.end(), moreScores.begin(), moreScores.end(), allscores.begin());
	
	cout << "\nAll Scores: \n";
	for(iter = allscores.begin(); iter != allscores.end(); ++iter){
		cout << *iter << endl;
	}
	
	// Measuring vector performance
	cout << "\nCreating a 10 element vector to hold scores.\n";
	vector<int> testScores(10, 0); //initialise all 10 elements to 0;
	for(iter = testScores.begin(); iter != testScores.end(); ++iter){
		cout << *iter << endl;
	}
	cout << "Vector Size is: " << testScores.size() << endl;
	cout << "Vector Capacity is: " << testScores.capacity() << endl;
	
	cout << "\nAdding a Score to the vector...\n";
	testScores.push_back(0);
	cout << "Vector Size is: " << testScores.size() << endl;
	cout << "Vector Capacity is: " << testScores.capacity() << endl; // testscore capacity = 20, since it doubled!
	
	cout << "\nAdding more capacity\n";
	testScores.reserve(45); // Manually increase the capacity to 45! 
	cout << "Vector Size is: " << testScores.size() << endl;
	cout << "Vector Capacity is: " << testScores.capacity() << endl;
	
	return 0;
}
