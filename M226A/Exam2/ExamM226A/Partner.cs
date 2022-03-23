namespace ExamM226A {
    public class Partner
    {
        public ContactPerson ContactPerson {get;set;}

        private object _suggestedPartnerType;
        public object SuggestedPartnerType {
            get{ return (Partner)_suggestedPartnerType; }
            set { _suggestedPartnerType = value; } 
        }
        
        public Partner(ContactPerson contactPerson, int contribution = -1) {
            ContactPerson = contactPerson;

            if (contribution != -1) {
                SuggestedPartnerType = SuggestPartnerType(contribution);
            }
        }

        private object SuggestPartnerType( int contribution ) {
            if (contribution > 25000) {
                return new PlatinumPartner(ContactPerson, contribution);
            } else if (contribution > 0 ) {
                return new GoldPartner(ContactPerson, contribution);
            } else {
                return new MediaPartner(ContactPerson);
            }
        }
    }
}