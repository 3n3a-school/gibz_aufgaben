using System;
using System.Collections.Generic;

namespace ExamM226A
{
    public class TeamComptetition : Competition
    {
        private int MinSize {get;set;}
        private int MaxSize {get;set;}

        public TeamComptetition( string title, int maxSize, int minSize = 2 ): base( title ) {
            MaxSize = maxSize;
            MinSize = minSize;
        }

        public List<Team> GetAllInvalidTeams() {
            List<Team> _invalidTeams = new();
            foreach (Team team in Contestants)
            {
                if ( ! team.IsCorrectTeamSize(MaxSize, MinSize) ) {
                    _invalidTeams.Add(team);
                }
            }
            return _invalidTeams;
        }

        public override void AddContestant(Contestant contestant)
        {
            if (contestant.IsCorrectTeamSize(MaxSize, MinSize)) {
                base.AddContestant((Team)contestant);
            }
        }
    }
}