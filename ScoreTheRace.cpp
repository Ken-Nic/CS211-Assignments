#include<iostream>
using namespace std;

int main() {
   while (true) {
      string runners;
      cout << "Enter the race outcome: ";
      cin >> runners;
      if(runners == "done")
       return 0;

      int numTeams = 0;       // The number of teams
      int scores[122] = {}; // scores[i] keeps track of the total score of team i
      int counts[122] = {}; // counts[i] keeps track of the number of runners on team i
      for (int i = 0; i < runners.length(); ++i) { // For each runner in the race,
        // Get Runners team
         int team = runners.at(i);
         
        // If it's the first runner of that particular team, update the total number of teams
        if(counts[team] == 0)
        {
            numTeams++;
        }

        // Increase the team's score by the runner's rank
        scores[team] += i+1;

        // Update the number of runners on the team
        counts[team]++;
      }

      if(numTeams < 2)
      {
          cout<<"Not enough teams are competing\n";
      } else

      {
        int runnerAmt = 0;
        int team = 0;
        while(runnerAmt == 0 && team < 122)
        {
          runnerAmt = counts[team];
          team++;
        }

        team = team - 1;

        // Check for equal amount of runners
        for(int i = team; i < 122; i++)
        {
            if(counts[team] != runnerAmt)
            {
                cout << "Teams are not balanced, please input runners again. \n";
                break;
            }
        } 

        // Final output
        cout << "There are " << numTeams << " teams.\n";
        cout << "Each team has " << runnerAmt << " runners.\n";
        cout << "Teams\t "<<"Scores\n";
        int winner = team;
        double finalScore = 0.0;

        for(int j = team; j < 122; j++)
        {
            if(counts[j] > 0)
            {
                finalScore = double(scores[j])/double(numTeams);
                cout << (char)j <<'\t'<<finalScore<<endl;
                if(scores[j] < scores[winner])
                {
                    winner = j;
                }
            }
        }
        finalScore = double(scores[winner])/double(numTeams);
        cout<<"The winning team is team "<<(char)winner<<" with a score of "<< finalScore <<'.'<<endl;
      }
   }
   return 0;
}