namespace ExamM226A
{
    public class MediaPartner : Partner
    {
        public MediumTypes PrimaryMediumType {get;set;} 

        public MediaPartner( ContactPerson contactPerson ) : base(contactPerson) {
            
        }
    }
}