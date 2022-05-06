namespace ExamM226A
{
    public class PlatinumPartner : Partner
    {
        public int Contribution {get;set;}
        public PlatinumPartner( ContactPerson contactPerson, int contribution ) : base(contactPerson) {
            Contribution = contribution;
        }
    }
}