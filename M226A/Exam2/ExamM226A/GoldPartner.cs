namespace ExamM226A
{
    public class GoldPartner : Partner
    {
        public GoldPartner(ContactPerson contactPerson, int contribution) : base(contactPerson) {
            Contribution = contribution;
        }
    }
}