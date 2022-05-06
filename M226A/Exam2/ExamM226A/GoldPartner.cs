namespace ExamM226A
{
    public class GoldPartner : Partner
    {
        public int Contribution {get;set;}
        public GoldPartner(ContactPerson contactPerson, int contribution) : base(contactPerson) {
            Contribution = contribution;
        }
    }
}