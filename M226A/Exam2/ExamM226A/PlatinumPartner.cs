namespace ExamM226A
{
    public class PlatinumPartner : Partner
    {
        private int Contribution {get;set;}
        public PlatinumPartner( ContactPerson contactPerson, int contribution ) : base(contactPerson) {
            Contribution = contribution;
        }
    }
}