using System.Collections.Generic;

namespace ExamM226A
{
    public class Team : Contestant
    {
        public List<IndividualContestant> Athletes {get;set;}

        public bool IsCorrectTeamSize( int maxSize, int minSize ) {
            return Athletes.Count >= minSize && Athletes.Count <= maxSize;
        }
    }
}