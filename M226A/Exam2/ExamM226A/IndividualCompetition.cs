namespace ExamM226A
{
    public class IndividualCompetition : Competition
    {
        private int MinAge {get;set;}
        public override List<IndividualContestant> Contestants {get;set;}

        public IndividualCompetition( string title, int minAge = 6) : base(title) {
            MinAge = minAge;
        }

        public override void AddContestant(Contestant contestant)
        {
            base.AddContestant((IndividualContestant)contestant);
        }
    }
}