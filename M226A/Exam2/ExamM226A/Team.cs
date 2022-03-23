using System.Collections.Generic;

namespace ExamM226A
{
    public class Team : Contestant
    {
        public List<IndividualContestant> Athletes {get;set;}

        public Team() {
            Athletes = new();
        }

        public override bool IsCorrectTeamSize( int maxSize, int minSize ) {
            return Athletes.Count >= minSize && Athletes.Count <= maxSize;
        }

        public void AddAthlete( IndividualContestant athlete ) {
            Athletes.Add(athlete);
        }
    }
}