namespace ExamM226A
{
    public abstract class Contestant
    {
        public virtual bool IsCorrectTeamSize(int maxSize, int minSize) {
            return false;
        }
    }
}