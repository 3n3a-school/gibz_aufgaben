namespace ExamM226A
{
    public class GoldPartner : Partner
    {
        private int Contribution {get;set;}
        public GoldPartner(ContactPerson contactPerson, int contribution) : base(contactPerson) {
            Contribution = contribution;
        }
    }
}